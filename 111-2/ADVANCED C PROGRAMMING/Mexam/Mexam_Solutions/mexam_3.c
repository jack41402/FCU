/* 
  Write a C program to perform transformation of mirror reflection along 
  the vertical line on the center of the image and attach the transformed 
  on the right-hand-side of the original image. 
*/
#include <stdio.h>
#include <stdlib.h>

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


int main() {
  FILE *fptr; // File pointer 
  Header	header; // Bitmap file header
  unsigned char	*palette; // Pointer: palette.
  unsigned char	*imageData; // Pointer: Image pixel data.
  unsigned long ImageSize_extended; // Size of the extended image.
  unsigned char *imageData_extended;  // Image data of the extended image.
  int rowSize; // Number of bytes in a row. 
  int fillings; // Number of bytes of padding 0's in the original image.
  int rowSize_extended; // Number of bytes in a row of the extended image. 
  int fillings_extended; // Number of bytes of padding 0's in the extended image.
  int i, j; // Loop variable.
  int k; // Pixel index of the original image.
  int k_left, k_right; // Pixel indices of left part and the right part of the extended image.

  // Read image file "abraham_lake.bmp". Remember to download the image.
  fptr = fopen("abraham_lake.bmp", "rb"); // Open the input file using binary mode.
  if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    printf("File %s does not exist.\n", "abraham_lake.bmp"); // Print error message.
    return 1; // Terminate the program.
  }  
  
  // Input file header and image information. 
  fread(&header.Type, 1, 2, fptr); // Two fixed characters, "BM".
  fread(&header.Size, 4, 1, fptr); // File size in bytes.
  fread(&header.Reserved, 1, 4, fptr); // Reserved field.
  fread(&header.OffsetBits, 4, 1, fptr); // Offset.
  fread(&header.InfoSize, 4, 1, fptr); // Information size in byte.
  fread(&header.Width, 4, 1, fptr); // Image width in pixel.
  fread(&header.Height, 4, 1, fptr); // Image height in pixel.
  fread(&header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
  fread(&header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
  fread(&header.Compression, 4, 1, fptr); // Value indicating what type of compression.
  fread(&header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  fread(&header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
  fread(&header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
  fread(&header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
  fread(&header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

  palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14); // Allocate memory space for the palette.
  fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);  // Read palette from the image file.

  /*===================================================================*/
  /* The image pixels are stored in the row major order from left      */
  /* to right and from bottom to top. That is, the last row from the   */
  /* top is stored at the beginning of the data area and the first row */
  /* from the top is stored at the end of the data area. Each pixel is */
  /* represendted in three bytes as its RGB values. The RGB values are */
  /* stored in the order of Blue, Green, and Red starting from the     */
  /* first byte.                                                       */
  /* The total number of bytes for the pixels in a row must be a       */
  /* multiple of four. If the total number is not a multiple of four,  */
  /* the trailing bytes are padded by zeros (hexdecimal).              */
  /* ==================================================================*/
  imageData = (unsigned char *) malloc(header.ImageSize); // Allocate memory space for image pixel data.
  fread(imageData, header.ImageSize, 1, fptr); // Read image pixel data from the image file.
	
  fclose(fptr); // Close the input file.
  
  // Perform transformation of mirror reflection along the vertical line on the center 
  // of the image and attach the transformed on the right-hand-side of the original image.  
  // The number of filling bytes at the end of the original image.
  fillings = (4 - (header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = header.Width * 3 + fillings; // The number of bytes in a row.
  
  // The number of filling bytes at the end of each row when the width is doubled.
  // Allocate memory for the extended image.
  fillings_extended = (4 - (header.Width * 3 * 2) % 4) % 4;
  rowSize_extended = header.Width * 3 * 2 + fillings_extended; // The number of bytes in a row of the extended image.
  ImageSize_extended = header.Height * rowSize_extended; // Image size of the extended image.
  imageData_extended = (unsigned char *) malloc(ImageSize_extended); // Allocate memory space for image pixel data of the extended image.
  
  // Copy image pixels.
  for (i = 0; i < header.Height; i++) { // Go through all rows.
    for (j = 0; j < header.Width; j++) { // Go through all pixels on a row of the original image.
      k = i * rowSize + j * 3; // The index of the pixel in row i of the original image.
	  k_left = i * rowSize_extended + j * 3; // The index of the pixel on the left hlaf in row i of the extended image.
	  k_right = i * rowSize_extended + (header.Width * 2 - 1 - j) * 3; // The index of the pixel on the left hlaf in row i of the extended image.
      // Copy blue level.
      imageData_extended[k_left] = imageData[k];
      imageData_extended[k_right] = imageData[k];
      // Copy green level.
      imageData_extended[k_left+1] = imageData[k+1];
      imageData_extended[k_right+1] = imageData[k+1];
      // Copy red level.
      imageData_extended[k_left+2] = imageData[k+2];
      imageData_extended[k_right+2] = imageData[k+2];
    }
  }
  
  // Open ouput file "abraham_lake_vertical_extended.bmp".
  fptr = fopen("abraham_lake_vertical_extended.bmp", "wb"); // Open the output file using binary mode.
  
  // Modify the bit map file header.
  header.Size = header.Size - header.ImageSize + ImageSize_extended;
  header.Width =  header.Width * 2;
  header.ImageSize = ImageSize_extended;
  
  // Write the file header and image information of the extended image.
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

  // Write the color palette and image data of the extended image.
  fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); // Write the palette.
  fwrite(imageData_extended, 1, header.ImageSize, fptr); // Write the image pixel data of the extended image.
  
  fclose(fptr); // Close the output file.
 
  // Print the file header and image information of the extended image.
  printf(">>>> File header and image information of the extended image:\n\n");
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]); // Two fixed characters, "BM".
  printf("Size:             %u\n", header.Size); // File size in bytes.
  printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], 
                                         header.Reserved[2], header.Reserved[3]); // Reserved field.
  printf("OffsetBits:       %u\n", header.OffsetBits); // Offset.
  printf("InfoSize:         %u\n", header.InfoSize); // Information size in byte.
  printf("Width:            %u\n", header.Width); // Image width in pixel.
  printf("Height:           %u\n", header.Height); // Image height in byte.
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

  // Free memory space of color palette, image data of the original image and the extended image.
  free(palette); // Release memory space of palette.
  free(imageData); // Release memory space of image pixel data.
  free(imageData_extended); // Release memory space of image pixel data of the extended image.
  return 0;
}
