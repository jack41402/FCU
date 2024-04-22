#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    // File header: 14 bytes.
    char Type[2];         // Two fixed characters, "BM" for bitmap images.
    unsigned Size;        // File size in bytes.
    char Reserved[4];     // Reserved field.
    unsigned OffsetBits;  // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
    // Image information: 40 bytes.
    unsigned InfoSize;    // Information size in byte.
    unsigned Width;       // Image width in pixel.
    unsigned Height;      // Image height in pixel.
    unsigned short Planes;       // Number of image planes in the image, must be 1.
    unsigned short BitPerPixel;  // Number of bits used to represent the data for each pixel.
    unsigned Compression;        // Value indicating what type of compression, if any, is used, (0: uncompressed).
    unsigned ImageSize;          // Size of the actual pixel data, in bytes.
    unsigned XResolution;        // Preferred horizontal resolution of the image, in pixels per meter.
    unsigned YResolution;        // Preferred vertical resolution of the image, in pixels per meter.
    unsigned Colors;             // Value is zero except for indexed images using fewer than the maximum number of colors.
    unsigned ImportantColors;    // Number of colors that are considered important when rendering the image.
} Header;

void print_header(Header header) {// Print the image file head
    printf("Type:             %c%c\n", header.Type[0], header.Type[1]); 
    printf("Size:             %u\n", header.Size); 
    printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3]); 
    printf("OffsetBits:       %u\n", header.OffsetBits); 
    printf("InfoSize:         %u\n", header.InfoSize); 
    printf("Width:            %u\n", header.Width);
    printf("Height:           %u\n", header.Height); 
    printf("Planes:           %d\n", header.Planes); 
    printf("BitPerPixel:      %d\n", header.BitPerPixel); 
    printf("Compression:      %u\n", header.Compression); 
    printf("ImageSize:        %u\n", header.ImageSize); 
    printf("XResolution:      %u\n", header.XResolution);
    printf("YResolution:      %u\n", header.YResolution);
    printf("Colors:           %u\n", header.Colors);
    printf("ImportantColors:  %u\n", header.ImportantColors);
    
}

// Write the image file.
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
    FILE *fptr = fopen(fname, "wb"); // Open the output file using binary mode.
    fwrite(&header.Type, 1, 2, fptr); // Two fixed characters, "BM".
    fwrite(&header.Size, 4, 1, fptr); // File size in bytes.
    fwrite(&header.Reserved, 1, 4, fptr); // Reserved field.
    fwrite(&header.OffsetBits, 4, 1, fptr); // Offset.
    fwrite(&header.InfoSize, 4, 1, fptr); // Information size in byte.
    fwrite(&header.Width, 4, 1, fptr); // Image width in pixel.
    fwrite(&header.Height, 4, 1, fptr); // Image height in pixel.
    fwrite(&header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
    fwrite(&header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
    fwrite(&header.Compression, 4, 1, fptr); // Value indicating what type of compression.
    fwrite(&header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
    fwrite(&header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
    fwrite(&header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
    fwrite(&header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
    fwrite(&header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

    fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); // Write the palette.
    fwrite(imageData, 1, header.ImageSize, fptr); // Write the image pixel data.
    fclose(fptr); // Close the output file.
}

int main(int argc, char *argv[]) {
    FILE *fptr; // File pointer 
    Header io_header; // Bitmap file header of the input/output (original/merged) image.
    unsigned char	*io_palette; // Pointer: input/output image palette.
    unsigned char	*io_imageData; // Pointer: input/output image pixel data.
    Header reduced_header; // Bitmap file header of the reduced image.
    // The reduced image will use the same palette of input/output image.
    unsigned char	*reduced_imageData; // Pointer: reduced image pixel data.
    char file_name[40];
    int rowSize; // Number of bytes in a row of the input image. 
    int rowSize_reduced; // Number of bytes in a row of the reduced image.
    int fillings; // Number of bytes of padding 0's.
    int i, j; // Loop variable.
    int k; // Index of the pixel in the orignal image.
    int k_reduced; // Index of the pixel in the reduced image.
    int k_1, k_2, k_3, k_4; // k_i is the index of the pixel in the i-th quadrant of the merged image.
    int fx, fr, fg, fb;

    if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
        printf("Please enter an image file name without .bmp extension.\n");
        return 1;
    }
    else if (argc>2) { // If the command has more than three strings, too many arguments are entered.
        printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
        return 1;
    }

    printf("Enter the size of frame in pixel (between 4 and 20): ");
    scanf("%d", &fx);
    printf("\nEnter RGB value of the frame color: ");
    scanf("%d %d %d", &fr, &fg, &fb);

    // The input command has two or three strings, the 2nd one is the name of the input file.
    // Since strcat has a side effect to change str1, strcpy(file_name, argv[1]) is used to preserve
    // file name argv[1].
    fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); // Open the input file using binary mode.
    if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
        printf("File %s does not exist.\n", strcat(argv[1], ".bmp")); // Print error message.
        return 1; // Terminate the program.
    }  

    // Input the colored image file.
    fread(&io_header.Type, 1, 2, fptr); 
    fread(&io_header.Size, 4, 1, fptr); // File size in bytes.
    fread(&io_header.Reserved, 1, 4, fptr); // Reserved field.
    fread(&io_header.OffsetBits, 4, 1, fptr); // Offset.
    fread(&io_header.InfoSize, 4, 1, fptr); // Information size in byte.
    fread(&io_header.Width, 4, 1, fptr); // Image width in pixel.
    fread(&io_header.Height, 4, 1, fptr); // Image height in pixel.
    fread(&io_header.Planes, 2, 1, fptr); // must be 1.
    fread(&io_header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
    fread(&io_header.Compression, 4, 1, fptr); // Value indicating what type of compression.
    fread(&io_header.ImageSize, 4, 1, fptr); // Size of the actual pixel data
    fread(&io_header.XResolution, 4, 1, fptr); // horizontal resolution of the image
    fread(&io_header.YResolution, 4, 1, fptr); // vertical resolution of the image
    fread(&io_header.Colors, 4, 1, fptr); 
    fread(&io_header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

    io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14); // Allocate memory space for the palette.
    fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);  // Read palette from the image file.
    
    io_imageData = (unsigned char *) malloc(io_header.ImageSize); // Allocate memory space for image pixel data.
    fread(io_imageData, io_header.ImageSize, 1, fptr); // Read image pixel data from the image file.
        
    fclose(fptr); // Close the input file.
    
    printf("\n>>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); // Print the file header message.
    print_header(io_header);
    printf("******************************************************************\n\n"); 
  
    // Create file head of the quaterly reduced image.
    // Copy the fields of the input image header.
    reduced_header.Type[0] = 'B'; 
    reduced_header.Type[1] = 'M';
    reduced_header.Size = io_header.Size; 
    for (i=0; i<4; i++) 
        reduced_header.Reserved[i] = io_header.Reserved[i];
    reduced_header.OffsetBits = io_header.OffsetBits; 
    reduced_header.InfoSize = io_header.InfoSize; 
    
    reduced_header.Width = ceil((float) io_header.Width / 2.0); // Update the width and length of the image pixels, half size of the input image.
    reduced_header.Height = ceil((float) io_header.Height / 2.0); // If the input image has odd width or length, take the ceiling.
    reduced_header.Planes = io_header.Planes; 
    reduced_header.BitPerPixel = io_header.BitPerPixel; 
    reduced_header.Compression = io_header.Compression; 
    
    reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; 
    reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;
    reduced_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
    reduced_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
    reduced_header.Colors = io_header.Colors; 
    reduced_header.ImportantColors = io_header.ImportantColors; // Number of colors 
    
    reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);// Allocate memory space for image pixel data of the reduced image.
    
    fillings = (4 - (io_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
    rowSize = io_header.Width * 3 + fillings; // Compute the row size of the original image.
  
    // Compute the row size of the reduced image.
    fillings = (4 - (reduced_header.Width * 3) % 4) % 4;
    rowSize_reduced = reduced_header.Width * 3 + fillings; 
    // Copy even rows and enen columns of the original input image data to the reduced image.
    for (i = 0; i < reduced_header.Height; i++) 
        for (j = 0; j < reduced_header.Width; j++) { 
            k = i * 2 * rowSize + j * 2 * 3; 
            k_reduced = i * rowSize_reduced + j * 3; 
            reduced_imageData[k_reduced] = io_imageData[k]; // Copy blue level.
            reduced_imageData[k_reduced+1] = io_imageData[k+1]; // Copy green level.
            reduced_imageData[k_reduced+2] = io_imageData[k+2]; // Copy red level
        }

   
    printf(">>>> File header of the reduced image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); // Print the reduced image file head.
    print_header(reduced_header);
    printf("******************************************************************\n\n"); 
  
    
    write_image_file(file_name, reduced_header, io_palette, reduced_imageData);// The file name is reused and the palette is the same as the original image.
    free(io_imageData);
  
    io_header.Width = io_header.Width + 3 * fx;
    io_header.Height = io_header.Height + 3 * fx;
    unsigned new_imgsize = ceil((float) io_header.Width * 3.0 / 4.0) * 4 * io_header.Height; 
    io_header.Size = io_header.Size - io_header.ImageSize + new_imgsize;
    io_header.ImageSize = new_imgsize;
    unsigned char	*io_imageData_out = (unsigned char *) malloc(io_header.ImageSize);
    fillings = (4 - (io_header.Width * 3) % 4) % 4; 
    rowSize = io_header.Width * 3 + fillings; 

    for (i = 0; i < io_header.Height; i++) {
        for (j = 0; j < io_header.Width; j++) {
            k = i * rowSize + j * 3;
            io_imageData_out[k] = fb;
            io_imageData_out[k+1] = fg;
            io_imageData_out[k+2] = fr;
        }
    }

    for (i = 0; i < reduced_header.Height; i++) {
        for (j = 0; j < reduced_header.Width; j++) { 
            k_reduced = i * rowSize_reduced + j * 3; 
            k_1 = (i + io_header.Height / 2 + fx / 2) * rowSize + (io_header.Width - 1 - j - fx) * 3; // 1st quadrant.
            k_2 = (i + io_header.Height / 2 + fx / 2) * rowSize + (j + fx) * 3; // 2nd quadrant. 
            k_3 = (reduced_header.Height - 1 - i + fx) * rowSize + (j + fx) * 3; // 3rd quadrant. 
            k_4 = (reduced_header.Height - 1 - i + fx) * rowSize + (io_header.Width - 1 - j - fx) * 3; // 4th quadrant.
            io_imageData_out[k_1] = reduced_imageData[k_reduced]; // Copy the pixel in the 1st quadrant.
            io_imageData_out[k_1+1] = reduced_imageData[k_reduced+1];
            io_imageData_out[k_1+2] = reduced_imageData[k_reduced+2];
            io_imageData_out[k_2] = reduced_imageData[k_reduced]; // Copy the pixel in the 2nd quadrant.
            io_imageData_out[k_2+1] = reduced_imageData[k_reduced+1];
            io_imageData_out[k_2+2] = reduced_imageData[k_reduced+2];
            io_imageData_out[k_3] = reduced_imageData[k_reduced]; // Copy the pixel in the 3rd quadrant.
            io_imageData_out[k_3+1] = reduced_imageData[k_reduced+1];
            io_imageData_out[k_3+2] = reduced_imageData[k_reduced+2];
            io_imageData_out[k_4] = reduced_imageData[k_reduced]; // Copy the pixel in the 4th quadrant.
            io_imageData_out[k_4+1] = reduced_imageData[k_reduced+1];
            io_imageData_out[k_4+2] = reduced_imageData[k_reduced+2];
        }
    }

    
    printf(">>>> File header of the merged image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp")); // Print the merged image file head.
    print_header(io_header);
    printf("******************************************************************\n\n"); // Print a separate line.
    
    write_image_file(file_name, io_header, io_palette, io_imageData_out);

    free(io_palette); // Release memory space of palette of the input image.
    
    system("pause"); 
    return 0;
}
