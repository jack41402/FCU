//
//  main.c
//  assgn3_D1265065
//
//  Created by Corrine  on 2024/4/8.
//

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

// Print the image file head.
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
  printf("XResolution:      %u\n", header.XResolution);
  printf("YResolution:      %u\n", header.YResolution);
  printf("Colors:           %u\n", header.Colors);
  printf("ImportantColors:  %u\n", header.ImportantColors);
}


// Write the image file.
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
  FILE *fptr; // File pointer.
  fptr = fopen(fname, "wb"); // Open the output file using binary mode.
  // Output the vertical mirror reflection image file.
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
  unsigned char    *io_palette; // Pointer: input/output image palette.
  unsigned char    *io_imageData; // Pointer: input/output image pixel data.
  Header reduced_header; // Bitmap file header of the reduced image.
  // The reduced image will use the same palette of input/output image.
  unsigned char    *reduced_imageData; // Pointer: reduced image pixel data.
    unsigned char *merged_imageData;
  char file_name[40];
  int rowSize; // Number of bytes in a row of the input image.
  int rowSize_reduced; // Number of bytes in a row of the reduced image.
  int fillings; // Number of bytes of padding 0's.
  int i, j; // Loop variable.
  int k; // Index of the pixel in the orignal image.
  int k_reduced; // Index of the pixel in the reduced image.
  int k_1, k_2, k_3, k_4; // k_i is the index of the pixel in the i-th quadrant of the merged image.
    int frame_size;
    int R, G, B;
    Header merged_header;
    int rowSize_merged;

  if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
    printf("Please enter an image file name without .bmp extension.\n");
    return 1;
  }
  else if (argc>2) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    return 1;
  }
    printf("Enter the size of frame in pixel (between 4 and 20): ");
    scanf("%d", &frame_size);
    // Scan the frame size value.
    printf("Enter RGB value of the frame color: ");
    scanf("%d %d %d", &R, &G, &B);
    // Scan the RGB value.
  fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); // Open the input file using binary mode.
  if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    printf("File %s does not exist.\n", strcat(argv[1], ".bmp")); // Print error message.
    return 1; // Terminate the program.
  }

 // Input the colored image file.
  fread(&io_header.Type, 1, 2, fptr); // Two fixed characters, "BM".
  fread(&io_header.Size, 4, 1, fptr); // File size in bytes.
  fread(&io_header.Reserved, 1, 4, fptr); // Reserved field.
  fread(&io_header.OffsetBits, 4, 1, fptr); // Offset.
  fread(&io_header.InfoSize, 4, 1, fptr); // Information size in byte.
  fread(&io_header.Width, 4, 1, fptr); // Image width in pixel.
  fread(&io_header.Height, 4, 1, fptr); // Image height in pixel.
  fread(&io_header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
  fread(&io_header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
  fread(&io_header.Compression, 4, 1, fptr); // Value indicating what type of compression.
  fread(&io_header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  fread(&io_header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
  fread(&io_header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
  fread(&io_header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
  fread(&io_header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

  io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14); // Allocate memory space for the palette.
  fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);  // Read palette from the image file.
  io_imageData = (unsigned char *) malloc(io_header.ImageSize); // Allocate memory space for image pixel data.
  fread(io_imageData, io_header.ImageSize, 1, fptr); // Read image pixel data from the image file.
    
  fclose(fptr); // Close the input file.
   
  // Print the input image file head.
  printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); // Print the file header message.
  print_header(io_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  
  // Create file head of the quaterly reduced image.
  // Copy the fields of the input image header.
    reduced_header = io_header; // Let the struture of reduced header same as io header.
  reduced_header.Type[0] = 'B'; // Two fixed characters, "BM".
  reduced_header.Type[1] = 'M';
  // Update the width and length of the image pixels, half size of the input image.
  reduced_header.Width = ceil((float) io_header.Width / 2.0); // Image width in pixel.
  reduced_header.Height = ceil((float) io_header.Height / 2.0); // Image height in pixel.
 
  // Size of the actual pixel data, in bytes.
  // Compute the image size of the reduced image.
  // "ceil((float) reduced_header.Width * 3.0 / 4.0) * 4" makes the number of bytes of a row to be
  // greater than or eqaul to width*3 and a multiple of 4.
  reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height;
  // Compute the file size in bytes.
  reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;
  // Allocate memory space for image pixel data of the reduced image.
  reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  // Perform image reduction.
  // Copy even rows and enen columns of the original input image data to the reduced image.
  // Compute the row size of the original image.
  fillings = (4 - (io_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = io_header.Width * 3 + fillings; // The number of bytes in a row of the original image.
  
  // Compute the row size of the reduced image.
  fillings = (4 - (reduced_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_reduced = reduced_header.Width * 3 + fillings; // The number of bytes in a row of the reduced image.
  // Copy even rows and enen columns of the original input image data to the reduced image.
  for (i = 0; i < reduced_header.Height; i++) // Go through all rows of the reduced image.
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each of the reduced image.
      k = i * 2 * rowSize + j * 2 * 3; // Pixel index of the original input image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      reduced_imageData[k_reduced] = io_imageData[k]; // Copy blue level.
      reduced_imageData[k_reduced+1] = io_imageData[k+1]; // Copy green level.
      reduced_imageData[k_reduced+2] = io_imageData[k+2]; // Copy red level
    }

  // Print the reduced image file head.
  printf(">>>> File header of the reduced image, %s:\n\n",
         strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); // Print the file header message.
  print_header(reduced_header);
  printf("******************************************************************\n\n");
  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  // write the file.
    // Create file head of the merged image.
    // Copy the fields of the input image header.
    merged_header = reduced_header;
    merged_header.Type[0] = 'B';// Two fixed characters, "BM".
    merged_header.Type[1] = 'M';
    // Update the width and length of the image pixels, half size of the input image.
    merged_header.Width = reduced_header.Width * 2.0 + frame_size * 3;
    // Image width in pixel.
    merged_header.Height = reduced_header.Height * 2.0 + frame_size * 3;
    // Image height in pixel.
    merged_header.ImageSize = ceil((float) merged_header.Width * 3.0 / 4.0) * 4 * merged_header.Height;
    // Size of the actual pixel data, in bytes.
    merged_header.Size = reduced_header.Size - reduced_header.ImageSize + merged_header.ImageSize;
    // Compute the file size in bytes.
    merged_imageData = (unsigned char *) malloc(merged_header.ImageSize);
    // Allocate memory space for image pixel data of the reduced image.
    fillings = (4 - (merged_header.Width * 3) % 4) % 4;
    // The number of filling bytes at the end of a row.
    rowSize_merged = merged_header.Width * 3 + fillings;
    // Compute the row size of the merged image.
    
    for (i = 0; i < reduced_header.Height; i++) {
      for (j = 0; j < reduced_header.Width; j++) {
      k_reduced = i * rowSize_reduced + j * 3;
      k_1 = (i + merged_header.Height / 2 + frame_size / 2) * rowSize_merged + (merged_header.Width - 1 - j - frame_size) * 3; // 1st quadrant
      k_2 = (i + merged_header.Height / 2 + frame_size / 2) * rowSize_merged + (j + frame_size)  * 3; // 2nd quadrant.
      k_3 = (merged_header.Height / 2 - 1 - i - frame_size / 2) * rowSize_merged + (j + frame_size) * 3; // 3rd quadrant.
      k_4 = (merged_header.Height / 2 - 1 - i - frame_size / 2) * rowSize_merged + (merged_header.Width - 1 - j - frame_size) * 3; // 4th quadrant.
      merged_imageData[k_1] = reduced_imageData[k_reduced]; // Copy the pixel in the 1st quadrant.
      merged_imageData[k_1+1] = reduced_imageData[k_reduced+1];
      merged_imageData[k_1+2] = reduced_imageData[k_reduced+2];
      merged_imageData[k_2] = reduced_imageData[k_reduced]; // Copy the pixel in the 2nd quadrant.
      merged_imageData[k_2+1] = reduced_imageData[k_reduced+1];
      merged_imageData[k_2+2] = reduced_imageData[k_reduced+2];
      merged_imageData[k_3] = reduced_imageData[k_reduced]; // Copy the pixel in the 3rd quadrant.
      merged_imageData[k_3+1] = reduced_imageData[k_reduced+1];
      merged_imageData[k_3+2] = reduced_imageData[k_reduced+2];
      merged_imageData[k_4] = reduced_imageData[k_reduced]; // Copy the pixel in the 4th quadrant.
      merged_imageData[k_4+1] = reduced_imageData[k_reduced+1];
      merged_imageData[k_4+2] = reduced_imageData[k_reduced+2];
    }
  }
    
    for (i = 0; i < merged_header.Height; i++) {// Go through all rows of the reduced image.
        for (j = 0; j < merged_header.Width; j++) {// Go through all pixels in each of the reduced image.
            if (i <= frame_size || (i >= (frame_size + reduced_header.Height) && (i <= (frame_size*2 + reduced_header.Height))) || i >= (frame_size*2 + reduced_header.Height*2)){ // Determine when to print the frame out for height.
                k = i * rowSize_merged + j * 3; // Pixel index of the merged image.
                merged_imageData[k] = B; // Copy the blue value
                merged_imageData[k+1] = G; // Copy the green value
                merged_imageData[k+2] = R; // Copy the red value
            }
            if (j <= frame_size || (j >= (frame_size + reduced_header.Width) && (j <= (frame_size*2 + reduced_header.Width))) || j >= (frame_size*2 + reduced_header.Width*2)){ // Determine when to print the frame out for width.
                k = i * rowSize_merged + j * 3; // Pixel index of the merged image.
                merged_imageData[k] = B; // Copy the blue value
                merged_imageData[k+1] = G; // Copy the green value
                merged_imageData[k+2] = R; // Copy the red value
            }
        }
    }
    // Print the merged image file head.
  printf(">>>> File header of the merged image, %s:\n\n",
         strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp")); // Print the file header message.
  print_header(merged_header);
  printf("******************************************************************\n\n");
  write_image_file(file_name, merged_header, io_palette, merged_imageData);
  // write the file.
  // release the memory space of every file.
  free(io_palette);
  free(io_imageData);
  free(reduced_imageData);
  free(merged_imageData);
  system("pause");
  return 0;
}

