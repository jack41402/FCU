#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// creat a bitmap file to store digital images
typedef struct {
  char Type[2];
  unsigned Size;        // File size in bytes.
  char Reserved[4];     // Reserved field.
  unsigned OffsetBits;

  unsigned InfoSize;
  unsigned Width;
  unsigned Height;
  unsigned short Planes;
  unsigned short BitPerPixel;  // Number of bits used to represent the data for each pixel.
  unsigned Compression;
  unsigned ImageSize;
  unsigned XResolution;
  unsigned YResolution;
  unsigned Colors;
  unsigned ImportantColors;
} Header;

// the function to print the image file head
void print_header(Header header) {
  
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]);
  printf("Size:             %u\n", header.Size);
  printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1],
                                         header.Reserved[2], header.Reserved[3]);
  printf("OffsetBits:       %u\n", header.OffsetBits);
  printf("InfoSize:         %u\n", header.InfoSize);
  printf("Width:            %u\n", header.Width);
  printf("Height:           %u\n", header.Height);
  printf("Planes:           %d\n", header.Planes);
  printf("BitPerPixel:      %d\n", header.BitPerPixel);
  printf("Compression:      %u\n", header.Compression);
  printf("ImageSize:        %u\n", header.ImageSize);
  // Preferred horizontal resolution of the image, in pixels per meter.
  printf("XResolution:      %u\n", header.XResolution);
  // Preferred vertical resolution of the image, in pixels per meter.
  printf("YResolution:      %u\n", header.YResolution);
  // Value is zero except for indexed images using fewer than the maximum number of colors.
  printf("Colors:           %u\n", header.Colors);
  // Number of colors that are considered important when rendering the image.
  printf("ImportantColors:  %u\n", header.ImportantColors);
}


// Write the image file.
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
  FILE *fptr;
  fptr = fopen(fname, "wb"); // Open the output file using binary mode.
  // Output the vertical mirror reflection image file.
  fwrite(&header.Type, 1, 2, fptr);
  fwrite(&header.Size, 4, 1, fptr);
  fwrite(&header.Reserved, 1, 4, fptr);
  fwrite(&header.OffsetBits, 4, 1, fptr);
  fwrite(&header.InfoSize, 4, 1, fptr);
  fwrite(&header.Width, 4, 1, fptr);
  fwrite(&header.Height, 4, 1, fptr);
  fwrite(&header.Planes, 2, 1, fptr);
  fwrite(&header.BitPerPixel, 2, 1, fptr);
  fwrite(&header.Compression, 4, 1, fptr);
  fwrite(&header.ImageSize, 4, 1, fptr);
  fwrite(&header.XResolution, 4, 1, fptr);
  fwrite(&header.YResolution, 4, 1, fptr);
  fwrite(&header.Colors, 4, 1, fptr);
  fwrite(&header.ImportantColors, 4, 1, fptr);

  fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr);
  fwrite(imageData, 1, header.ImageSize, fptr);
  fclose(fptr);
}

int main(int argc, char *argv[]) {
  FILE *fptr;
  Header io_header;
  unsigned char    *io_palette;
  unsigned char    *io_imageData;
  Header reduced_header; // Bitmap file header of the reduced image.
  // The reduced image will use the same palette of input/output image.
  unsigned char    *reduced_imageData; // Pointer: reduced image pixel data.
  char file_name[40];
  int rowSize; // Number of bytes in a row of the input image.
  int rowSize_reduced; // Number of bytes in a row of the reduced image.
  int fillings; // Number of bytes of padding 0's.
  int i, j; // Loop variable.
  int k; // Index of the pixel in the orignal image.
  int k_reduced; // Index of the pixel in the reduced image.
  int k_1, k_2, k_3, k_4; // k_i is the index of the pixel in the i-th quadrant of the merged image.
    
    Header aa;
    int s;
    int color[3];
    unsigned char    *f_imageData;
    
  if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
    printf("Please enter an image file name without .bmp extension.\n");
    return 1;
  }
  else if (argc>2) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    return 1;
  }

  
  fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); // Open the input file using binary mode.
    
    
    //check whether the file is exist or not.
  if (fptr==NULL) {
    printf("File %s does not exist.\n", strcat(argv[1], ".bmp"));
    return 1;
  }

 // Input the colored image file.
  fread(&io_header.Type, 1, 2, fptr);
  fread(&io_header.Size, 4, 1, fptr);
  fread(&io_header.Reserved, 1, 4, fptr);
  fread(&io_header.OffsetBits, 4, 1, fptr);
  fread(&io_header.InfoSize, 4, 1, fptr);
  fread(&io_header.Width, 4, 1, fptr); // Image width in pixel.
  fread(&io_header.Height, 4, 1, fptr); // Image height in pixel.
  fread(&io_header.Planes, 2, 1, fptr);
  fread(&io_header.BitPerPixel, 2, 1, fptr);
  fread(&io_header.Compression, 4, 1, fptr); // Value indicating what type of compression.
  fread(&io_header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  fread(&io_header.XResolution, 4, 1, fptr);
  fread(&io_header.YResolution, 4, 1, fptr);
  fread(&io_header.Colors, 4, 1, fptr);
  fread(&io_header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.
    
    
    printf("Enter the size of frame in pixel (between 4 and 20): ");
    scanf("%d",&s);
    printf("\nEnter RGB value of the frame color: ");
    scanf("%d %d %d",&color[0],&color[1],&color[2]);
    printf("\n");
    // Create space for the palette by dynamically distributing space
  io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14);
    
    // Read palette from the image file.
  fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);

    // Create space for image pixel data by dynamically distributing space
  io_imageData = (unsigned char *) malloc(io_header.ImageSize);
    
  fread(io_imageData, io_header.ImageSize, 1, fptr);
    
  fclose(fptr); // Close the input file.
   
  // Print the input image file head.
  printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp"));
  print_header(io_header);
  printf("******************************************************************\n\n");
  
  // Create file head of the quaterly reduced image.
  // Copy the fields of the input image header.
  reduced_header.Type[0] = 'B';
  reduced_header.Type[1] = 'M';
  reduced_header.Size = io_header.Size;
  for (i=0; i<4; i++) // Reserved field, four characters.
    reduced_header.Reserved[i] = io_header.Reserved[i];
  reduced_header.OffsetBits = io_header.OffsetBits;
  reduced_header.InfoSize = io_header.InfoSize;
    
  // Update the width and length of the image pixels, half size of the input image.
  // If the input image has odd width or length, take the ceiling.
  reduced_header.Width = ceil((float) io_header.Width / 2.0);
  reduced_header.Height = ceil((float) io_header.Height / 2.0);
  reduced_header.Planes = io_header.Planes;
  reduced_header.BitPerPixel = io_header.BitPerPixel;
  reduced_header.Compression = io_header.Compression;
    
  // Compute the image size of the reduced image.
  reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height;
  // Compute the file size in bytes.
  reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;
  reduced_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
  reduced_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
  reduced_header.Colors = io_header.Colors;
  reduced_header.ImportantColors = io_header.ImportantColors;
  
  // Allocate memory space for image pixel data of the reduced image.
  reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  
  
  // Compute the row size of the original image.
  fillings = (4 - (io_header.Width * 3) % 4) % 4;
  rowSize = io_header.Width * 3 + fillings;
  
  // Compute the row size of the reduced image.
  fillings = (4 - (reduced_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_reduced = reduced_header.Width * 3 + fillings; // The number of bytes in a row of the reduced image.
    
  // Copy even rows and enen columns of the original input image data to the reduced image.
  for (i = 0; i < reduced_header.Height; i++)
    for (j = 0; j < reduced_header.Width; j++) {
      k = i * 2 * rowSize + j * 2 * 3;
      k_reduced = i * rowSize_reduced + j * 3;
      reduced_imageData[k_reduced] = io_imageData[k]; // Copy blue level.
      reduced_imageData[k_reduced+1] = io_imageData[k+1]; // Copy green level.
      reduced_imageData[k_reduced+2] = io_imageData[k+2]; // Copy red level
    }

  // Print the reduced image file head.
  printf(">>>> File header of the reduced image, %s:\n\n",
         strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp"));
  print_header(reduced_header);
  printf("******************************************************************\n\n");
  

  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  
    
    // Create file head of the quaterly reduced image.
    // Copy the fields of the input image header.
    aa.Type[0] = 'B';
    aa.Type[1] = 'M';
    aa.Size = io_header.Size;
    for (i=0; i<4; i++)
      aa.Reserved[i] = io_header.Reserved[i];
    aa.OffsetBits = io_header.OffsetBits;
    aa.InfoSize = io_header.InfoSize;
    
    
    // Resize the image by adding a border around it. The border width is determined by the parameter 's'.
    // The new dimensions of the image will be larger by 2*s pixels in width and height.
    aa.Width = ceil((float) io_header.Width + (s*3));
    aa.Height = ceil((float) io_header.Height + (s*3));
    aa.Planes = io_header.Planes;
    aa.BitPerPixel = io_header.BitPerPixel;
    aa.Compression = io_header.Compression;

    // Calculate the new size of the image data.
    // It includes the padding bytes added at the end of each row to ensure the row size is a multiple of 4.
    aa.ImageSize = ceil((float) aa.Width * 3.0 / 4.0) * 4 * aa.Height;
    
    aa.Size = io_header.Size - io_header.ImageSize + aa.ImageSize;
    aa.XResolution = io_header.XResolution;
    aa.YResolution = io_header.YResolution;
    aa.Colors = io_header.Colors;
    aa.ImportantColors = io_header.ImportantColors;
    
    
    f_imageData = (unsigned char *) malloc(aa.ImageSize);
    
  
    fillings = (4 - (aa.Width * 3) % 4) % 4;
    int rowSize2;
    rowSize2 = aa.Width * 3 + fillings;
    
  // Peform the merge operation.
  // Reuse rowSize and rowSize_reduced computed earlier.
  for (i = 0; i < reduced_header.Height; i++) { // Go through all rows of the reduced image.
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each row of the reduced image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      // Computer pixel index of the merged image.
      // Note that row 0 is the bottom row and column 0 is the left-most column.
      k_1 = (i + aa.Height-s-reduced_header.Height) * rowSize2 + (aa.Width - 1 - j-s) * 3; // 1st quadrant.
      k_2 = (i + aa.Height-s-reduced_header.Height) * rowSize2 + (j+s) * 3; // 2nd quadrant.
      k_3 = (aa.Height - 1 - i - s*2 - reduced_header.Height) * rowSize2 + (j+s) * 3; // 3rd quadrant.
      k_4 = (aa.Height - 1 - i - s*2 - reduced_header.Height) * rowSize2 + (aa.Width - 1 - j-s) * 3; // 4th quadrant.
        f_imageData[k_1] = reduced_imageData[k_reduced]; // Copy the pixel in the 1st quadrant.
        f_imageData[k_1+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_1+2] = reduced_imageData[k_reduced+2];
        f_imageData[k_2] = reduced_imageData[k_reduced]; // Copy the pixel in the 2nd quadrant.
        f_imageData[k_2+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_2+2] = reduced_imageData[k_reduced+2];
        f_imageData[k_3] = reduced_imageData[k_reduced]; // Copy the pixel in the 3rd quadrant.
        f_imageData[k_3+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_3+2] = reduced_imageData[k_reduced+2];
        f_imageData[k_4] = reduced_imageData[k_reduced]; // Copy the pixel in the 4th quadrant.
        f_imageData[k_4+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_4+2] = reduced_imageData[k_reduced+2];
    }
  }
    int r ,w ,q;
    for(i=0;i<s;i++)
    {
        for(j=0;j<aa.Width;j++)
        {
            r = i*rowSize2+j*3;
            w = (i+reduced_header.Height+s) * rowSize2 +j*3;
            q = (i+reduced_header.Height*2+s*2) * rowSize2 +j*3;
            f_imageData[r] = color[2];
            f_imageData[r+1] = color[1];
            f_imageData[r+2] = color[0];
            f_imageData[w] = color[2];
            f_imageData[w+1] = color[1];
            f_imageData[w+2] = color[0];
            f_imageData[q] = color[2];
            f_imageData[q+1] = color[1];
            f_imageData[q+2] = color[0];
        }
    }
    for(i=0;i<s;i++)
    {
        for(j=0;j<aa.Height;j++)
        {
            r = j*rowSize2 + i*3;
            w = j*rowSize2 + (i+s+reduced_header.Width)*3;
            q = j*rowSize2 + (i+s*2+reduced_header.Width*2)*3;
            f_imageData[r] = color[2];
            f_imageData[r+1] = color[1];
            f_imageData[r+2] = color[0];
            f_imageData[w] = color[2];
            f_imageData[w+1] = color[1];
            f_imageData[w+2] = color[0];
            f_imageData[q] = color[2];
            f_imageData[q+1] = color[1];
            f_imageData[q+2] = color[0];
        }
    }
    
  // Print the merged image file head.
  printf(">>>> File header of the frame merged image, %s:\n\n",
         strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp"));
  print_header(aa);
  printf("******************************************************************\n\n");
  
  
  write_image_file(file_name, aa, io_palette, f_imageData);

    
  // Release the memory space
  free(io_palette);
  free(f_imageData);
  free(reduced_imageData);
  
  system("pause");
  return 0;
}

