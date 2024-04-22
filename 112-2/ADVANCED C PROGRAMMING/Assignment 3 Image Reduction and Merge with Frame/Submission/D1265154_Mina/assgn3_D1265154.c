#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  char Type[2]; // File type, should always be "BM" for bitmap images
  unsigned Size; // Total size of the bitmap file in bytes
  char Reserved[4]; // Reserved field, typically unused
  unsigned OffsetBits; // Offset to the beginning of the pixel data from the start of the file
  unsigned InfoSize; // Size of the information header in bytes
  unsigned Width; // Width of the image in pixels
  unsigned Height; // Height of the image in pixels
  unsigned short Planes; // Number of color planes, usually 1
  unsigned short BitPerPixel; // Number of bits per pixel
  unsigned Compression; // Compression method used, usually 0 for uncompressed
  unsigned ImageSize; // Size of the raw bitmap data (including padding) in bytes
  unsigned XResolution; // Horizontal resolution of the image in pixels per meter
  unsigned YResolution; // Vertical resolution of the image in pixels per meter
  unsigned Colors; // Number of colors in the color palette, typically 0 for full-color images
  unsigned ImportantColors; // Number of important colors used, typically ignored
} Header;

void print_header(Header header) {
  
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]); // Two fixed characters, "BM".
  printf("Size:             %u\n", header.Size); // File size in bytes.
  printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], 
                                         header.Reserved[2], header.Reserved[3]); // Reserved field.
  printf("OffsetBits:       %u\n", header.OffsetBits); // Offset.
  printf("InfoSize:         %u\n", header.InfoSize); // Information size in byte.
  printf("Width:            %u\n", header.Width); // Image width in pixel.
  printf("Height:           %u\n", header.Height); // Image height in pixel.
  printf("Planes:           %d\n", header.Planes); // Number of image planes in the image, must be 1.
  printf("BitPerPixel:      %d\n", header.BitPerPixel); // Number of bits used to represent the data for each pixel.
  printf("Compression:      %u\n", header.Compression); // Value indicating what type of compression.
  printf("ImageSize:        %u\n", header.ImageSize); // Size of the actual pixel data, in bytes.
  // Preferred horizontal resolution of the image, in pixels per meter.
  printf("XResolution:      %u\n", header.XResolution);
  // Preferred vertical resolution of the image, in pixels per meter.
  printf("YResolution:      %u\n", header.YResolution);
  // Value is zero except for indexed images using fewer than the maximum number of colors.
  printf("Colors:           %u\n", header.Colors);
  // Number of colors that are considered important when rendering the image.
  printf("ImportantColors:  %u\n", header.ImportantColors);
  // End of output commands
}

void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
  FILE *fptr; // File pointer. 
  fptr = fopen(fname, "wb"); // Open the output file using binary mode.
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
  Header merged_header;
  // The reduced image will use the same palette of input/output image.
  unsigned char	*reduced_imageData; // Pointer: reduced image pixel data.
  unsigned char	*merged_imageData;
  char file_name[40];
  int rowSize; // Number of bytes in a row of the input image. 
  int rowSize_reduced; // Number of bytes in a row of the reduced image.
  int rowSize_merged;
  int fillings; // Number of bytes of padding 0's.
  int i, j; // Loop variable.
  int k; // Index of the pixel in the orignal image.
  int k_reduced; // Index of the pixel in the reduced image.
  int k_merged;
  int k_1, k_2, k_3, k_4; // k_i is the index of the pixel in the i-th quadrant of the merged image.
  int frame_width, R, G, B;

  if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
    printf("Please enter an image file name without .bmp extension.\n");
    return 1;
  }
  else if (argc>2) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    return 1;
  }

  
  fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); // Open the input file using binary mode.
  if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    printf("File %s does not exist.\n", strcat(argv[1], ".bmp")); // Print error message.
    return 1; // Terminate the program.
  }  
  
  printf("Enter the size of frame in pixel (between 4 and 20):");
  scanf("%d", &frame_width);
  printf("\n");
  
  printf("Enter RGB value of the frame color:");
  scanf("%d %d %d", &R, &G, &B);
  printf("\n");

 
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
   
  
  printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); // Print the file header message.
  print_header(io_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  reduced_header.Type[0] = 'B'; // Two fixed characters, "BM".
  reduced_header.Type[1] = 'M';
  reduced_header.Size = io_header.Size; // File size in bytes.
  for (i=0; i<4; i++) // Reserved field, four characters.
    reduced_header.Reserved[i] = io_header.Reserved[i];
  reduced_header.OffsetBits = io_header.OffsetBits; // Offset.
  reduced_header.InfoSize = io_header.InfoSize; // Information size in byte.
  reduced_header.Width = ceil((float) io_header.Width / 2.0); // Image width in pixel.
  reduced_header.Height = ceil((float) io_header.Height / 2.0); // Image height in pixel.
  reduced_header.Planes = io_header.Planes; // Number of image planes in the image, must be 1.
  reduced_header.BitPerPixel = io_header.BitPerPixel; // Number of bits used to represent the data for each pixel.
  reduced_header.Compression = io_header.Compression; // Value indicating what type of compression.
  
  reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; 
  
  reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;
  reduced_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
  reduced_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
  reduced_header.Colors = io_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
  reduced_header.ImportantColors = io_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  // Allocate memory space for image pixel data of the reduced image.
  reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  
  merged_header.Type[0] = 'B'; // Setting first character of the type field to 'B'
  merged_header.Type[1] = 'M'; // Setting second character of the type field to 'M'
  merged_header.Size = io_header.Size; // Setting size of the merged image file to be the same as the original input file
  for (i=0; i<4; i++) // Copying reserved field from input header to merged header
    merged_header.Reserved[i] = io_header.Reserved[i];
  merged_header.OffsetBits = io_header.OffsetBits; // Copying offset bits from input header to merged header
  merged_header.InfoSize = io_header.InfoSize; // Copying info size from input header to merged header
  merged_header.Width = reduced_header.Width * 2 + frame_width * 3; // Calculating width of the merged image
  merged_header.Height = reduced_header.Height * 2 + frame_width * 3; // Calculating height of the merged image
  merged_header.Planes = io_header.Planes; // Copying planes from input header to merged header
  merged_header.BitPerPixel = io_header.BitPerPixel; // Copying bit per pixel from input header to merged header
  merged_header.Compression = io_header.Compression; // Copying compression from input header to merged header
  merged_header.ImageSize = ceil((float) merged_header.Width * 3.0 / 4.0) * 4 * merged_header.Height; // Calculating image size of the merged image
  merged_header.Size = io_header.Size - io_header.ImageSize + merged_header.ImageSize; // Adjusting size field of merged header based on image size
  merged_header.XResolution = io_header.XResolution; // Copying X resolution from input header to merged header
  merged_header.YResolution = io_header.YResolution; // Copying Y resolution from input header to merged header
  merged_header.Colors = io_header.Colors; // Copying colors from input header to merged header
  merged_header.ImportantColors = io_header.ImportantColors; // Copying important colors from input header to merged header
  merged_imageData = (unsigned char *) malloc(merged_header.ImageSize); // Allocating memory for merged image data

  
  
  fillings = (4 - (io_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = io_header.Width * 3 + fillings; // The number of bytes in a row of the original image.
  
  // Compute the row size of the reduced image.
  fillings = (4 - (reduced_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_reduced = reduced_header.Width * 3 + fillings; // The number of bytes in a row of the reduced image.
  
  fillings = (4 - (merged_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_merged = merged_header.Width * 3 + fillings; // The number of bytes in a row of the reduced image.
  
  
  for (i = 0; i < reduced_header.Height; i++) 
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each of the reduced image.
      k = i * 2 * rowSize + j * 2 * 3; // Pixel index of the original input image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      reduced_imageData[k_reduced] = io_imageData[k]; // Copy blue level.
      reduced_imageData[k_reduced+1] = io_imageData[k+1]; // Copy green level.
      reduced_imageData[k_reduced+2] = io_imageData[k+2]; // Copy red level
    }

  
  printf(">>>> File header of the reduced image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); // Print the file header message.
  print_header(reduced_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  
  
  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  
  
  for (i = 0; i < reduced_header.Height; i++) { // Go through all rows of the reduced image.
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each row of the reduced image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      k_1 = (i + merged_header.Height / 2 + frame_width / 2) * rowSize_merged + (merged_header.Width - 1 - j - frame_width) * 3; // 1st quadrant.
      k_2 = (i + merged_header.Height / 2 + frame_width / 2) * rowSize_merged + (j + frame_width) * 3; // 2nd quadrant. 
      k_3 = (merged_header.Height / 2 - 1 - i - frame_width / 2) * rowSize_merged + (j + frame_width) * 3; // 3rd quadrant. 
      k_4 = (merged_header.Height / 2 - 1 - i - frame_width / 2) * rowSize_merged + (merged_header.Width - 1 - j - frame_width) * 3; // 4th quadrant.
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
  
  
  for (i = 0; i < merged_header.Height; i++) { // Loop through each row of the merged image
    for (j = 0; j < merged_header.Width; j++) { // Loop through each pixel in the current row
      k_merged = i * rowSize_merged + j * 3; // Calculate the index of the current pixel in the merged image
      // Check if the current row or column is within the frame boundaries
      if(i < frame_width || (i >= (reduced_header.Height + frame_width) && i < (reduced_header.Height + frame_width * 2)) || i >= (reduced_header.Height + frame_width) * 2)
      {
      	merged_imageData[k_merged] = B; // Set blue value of the pixel to the frame color
      	merged_imageData[k_merged + 1] = G; // Set green value of the pixel to the frame color
		merged_imageData[k_merged + 2] = R; // Set red value of the pixel to the frame color
	  }
	  if(j < frame_width || (j >= (reduced_header.Width + frame_width) && j < (reduced_header.Width + frame_width * 2)) || j >= (reduced_header.Width + frame_width) * 2)
      {
      	merged_imageData[k_merged] = B; // Set blue value of the pixel to the frame color
      	merged_imageData[k_merged + 1] = G; // Set green value of the pixel to the frame color
		merged_imageData[k_merged + 2] = R; // Set red value of the pixel to the frame color
	  }
    }
}

 
  printf(">>>> File header of the merged image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp")); 
  print_header(merged_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  
 
  write_image_file(file_name, merged_header, io_palette, merged_imageData);

  free(io_palette); // Release memory space of palette of the input image.
  free(io_imageData); // Release memory space of image pixel data of the input image.
  free(reduced_imageData); // Release memory space of image pixel data of the reduced image.
  free(merged_imageData);
  
  system("pause"); 
  return 0;
}
