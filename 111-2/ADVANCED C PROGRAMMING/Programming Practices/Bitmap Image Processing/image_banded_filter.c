/* This program reads a bitmap image file. It converts a
   colored bitmap image to a banded_filter bitmap image.
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


int main(int argc, char *argv[]) {
  FILE *fptr; // File pointer 
  Header	header; // Bitmap file header
  unsigned char	*palette; // Pointer: palette.
  unsigned char	*imageData; // Pointer: Image pixel data.
  int rowSize; // Number of bytes in a row. 
  int fillings; // Number of bytes of padding 0's.  
  int first_filter; // The selected first filter.
  int filter; // The current filter under processing.
  int bandwidth; // The input bandwidth of filters.
  int weight; // The input filtering weight.
  int i, j, k; // Loop variable.

  if (argc==1) { // One argument in the command line. This argument must "image_banded_filter", the executable code.
    printf("Please enter the image file name.\n");
    system("pause");
    return 1;
  }
  else if (argc>3) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered.\n");
    system("pause");
    return 1;
  }

  // The input command has two or three strings, the 2nd one is the name of the input file.
  fptr = fopen(argv[1], "rb"); // Open the input file using binary mode.
  if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    printf("File %s does not exist.\n", argv[1]); // Print error message.
    return 1; // Terminate the program.
  }  

 // Input the colored image file.
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

/*===================================================================*/
/* For every entry in the palette, four bytes are used to describe   */
/* the RGB values of the color in the following way:                 */
/*   1 byte for blue component                                       */
/*   1 byte for green component                                      */
/*   1 byte for red component                                        */
/*   1 byte filter which is set to 0 (zero)                          */
/* Constant 14 is the lenght of the file header.                     */
/*===================================================================*/
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
  
  // Select the stating filter.
  do {
    printf("Select the starting filter (0: gray-level, 1: blue, 2: green, 3: red): ");
    scanf("%d", &first_filter);
  } while (first_filter<0 || first_filter>3);  
  printf("\n");
  
  // Set the bandwidth.
  do {
    printf("Enter the bandwidth (between 1 and %d): ", header.Width);
    scanf("%d", &bandwidth);
  } while (bandwidth<1 || bandwidth>header.Width);
  printf("\n");
  
  // Set the weight of the filtering effect.
  do {
    printf("Enter the filter weight(between 0 and 255): ");
    scanf("%d", &weight);
  } while (weight<0 || weight>255);  
  printf("\n");

  fillings = (4 - (header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = header.Width * 3 + fillings; // The number of bytes in a row.
  for (i = 0; i < header.Height; i++) { // Go through all rows.
    for (j = 0; j < header.Width; j++) { // Go through all pixels in row i.
      k = i * rowSize + j * 3; // The starting index in imageData of the pixel to be transformed.
      filter = (j / bandwidth + first_filter) % 4; // Calculate the filter for the transformed pixel.
      switch (filter) {
        case 0: { 
          // For gray-level filter, the levels of RGB in an image pixel are set to 
          // "(B*weight*20 + G*weight*50 + R*weight*30)/(weight*100)".
          if (weight!=0) {
            imageData[k] = (imageData[k] * weight * 20 + imageData[k+1] * weight * 50 + 
                            imageData[k+2] * weight * 30) / (weight * 100);
            imageData[k+1] = imageData[k];
            imageData[k+2] = imageData[k];
          }
          break;
        }
        case 1: {
          // For blue-colored filter, set level of B to "B<255-weight ? B+weight : weight" and 
          // preserve the levels of G and R.
          imageData[k] = imageData[k] < 255 - weight ? imageData[k] + weight : weight;
          break;
        }
        case 2: {
          // For green-colored filter, set level of G to "G<255-weight ? G+weight : weight" and 
          // preserve the levels of B and R.
          imageData[k+1] = imageData[k+1] < 255 - weight ? imageData[k+1] + weight : weight;
          break;
        }
        case 3: {
          // For red-colored filter, set level of R to "R<255-weight ? R+weight : weight" and 
          // preserve the levels of B and G.
          imageData[k+2] = imageData[k+2] < 255 - weight ? imageData[k+2] + weight : weight;
          break;
        }
      }
    }
  }
  
  // If the input command has three strings, use the 3rd one as the output file name;
  // otherwise, use the default file name "banded_filter.bmp".
  if (argc==3) { // User provided output file name.
    fptr = fopen(argv[2], "wb"); // Open the output file using binary mode.
    printf("\nThe banded_filter image is \"%s\".\n\n", argv[2]); // Print the output file name message.
  } 
  else { // Default output file name.
    fptr = fopen("banded_filter.bmp", "wb"); // Open the output file using binary mode.
    printf("\nThe banded_filter image is \"banded_filter.bmp\".\n\n"); // Print the output file name message.
  }  
  // Output the banded_filter image file.
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
 
  // Print the banded_filter image file head.
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
  /* End of output commands */

  free(palette); // Release memory space of palette.
  free(imageData); // Release memory space of image pixel data.
  return 0;
}
