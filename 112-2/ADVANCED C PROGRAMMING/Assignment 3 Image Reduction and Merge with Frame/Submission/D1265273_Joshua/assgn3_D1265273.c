#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  // File header: 14 bytes.
  char Type[2];         // Two fixed characters, "BM" 
  unsigned Size;        // File size
  char Reserved[4];     // Reserved field.
  unsigned OffsetBits;  // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
  unsigned InfoSize;    // Information size in byte.
  unsigned Width;       // Image width in pixel.
  unsigned Height;      // Image height in pixel.
  unsigned short Planes;       // Number of image planes in the image, must be 1.
  unsigned short BitPerPixel;  // Number of bits used to represent the data for each pixel.
  unsigned Compression;        // Value indicating what type of compression, if any, is used
  unsigned ImageSize;          // Size of the actual pixeldata, in bytes.
  unsigned XResolution;        // Preferred horizontal resolution of the image, in pixels per meter.
  unsigned YResolution;        // Preferred vertical resolution of the image, in pixels per meter.
  unsigned Colors;             // Value is zero except for indexed images using fewer than the maximum number of colors.
  unsigned ImportantColors;    // Number of colors that are considered important when rendering the image.
} Header;

// Print the image file head.
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
}

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
  unsigned char	*io_palette; // input image palette.
  unsigned char	*io_imageData; // input image pixel data.
  Header reduced_header; // header of the reduced image.
  Header colored_header;
  // The reduced image will use the same palette of input image.
  unsigned char	*reduced_imageData; // reduced image pixel data.
  unsigned char *colored_imageData;//colored image pixel data 
  char file_name[40];//file name array
  int rowSize; // Number of bytes in a row of the input image. 
  int rowSize_reduced; // Number of bytes in a row of the reduced image.
  int rowSize_colored;
  int fillings; // Number of bytes of padding 0's.
  int i, j; // Loop variable.
  int k; // Index of the pixel in the orignal image.
  int k_reduced; // Index of the pixel in the reduced image.
  int k_colored;
  int k_1, k_2, k_3, k_4; // k_i is the index of the pixel in the i-th quadrant of the merged image.
  int c_1, c_2, c_3;//RGB variable
  int n;//frame variable

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
    return 1; 
  }  

 // read the input image data
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

 //enter the size of the frame and the RGB value for the frame
 printf("Enter the size of the frame in pixel (between 4 and 20): ") ;
 scanf("%d",&n);
 printf("Enter RGB value of the frame color: ");
 scanf("%d %d %d",&c_1,&c_2,&c_3);

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
  reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; //compute the image size
  reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;//compute the file size
  reduced_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
  reduced_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
  reduced_header.Colors = io_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
  reduced_header.ImportantColors = io_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  
  reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);//allocate memory space for imaage pixel data
  fillings = (4 - (io_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize = io_header.Width * 3 + fillings; // The number of bytes in a row of the original image.
  
  fillings = (4 - (reduced_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_reduced = reduced_header.Width * 3 + fillings; // The number of bytes in a row of the reduced image.
  for (i = 0; i < reduced_header.Height; i++) // Go through all rows of the reduced image.
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each of the reduced image.
      k = i * 2 * rowSize + j * 2 * 3; // Pixel index of the original input image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      reduced_imageData[k_reduced] = io_imageData[k]; // Copy blue level.
      reduced_imageData[k_reduced+1] = io_imageData[k+1]; // Copy green level.
      reduced_imageData[k_reduced+2] = io_imageData[k+2]; // Copy red level
    }

  printf(">>>> File header of the reduced image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); // Print the file header message.
  print_header(reduced_header);
  printf("******************************************************************\n\n"); // Print a separate line.

  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);//write tmage to file "file _name_reduced.bmp"
  
  // Peform the merge operation.
  colored_header.Type[0] = 'B'; // Two fixed characters, "BM".
  colored_header.Type[1] = 'M';
  colored_header.Size = io_header.Size; // File size in bytes.
  for (i=0; i<4; i++) // Reserved field, four characters.
    colored_header.Reserved[i] = io_header.Reserved[i];
  colored_header.OffsetBits = io_header.OffsetBits; // Offset.
  colored_header.InfoSize = io_header.InfoSize; // Information size in byte.
  colored_header.Width = io_header.Width + n*3; // Image width in pixel.
  colored_header.Height = io_header.Height + n*3; // Image height in pixel.
  colored_header.Planes = io_header.Planes; // Number of image planes in the image, must be 1.
  colored_header.BitPerPixel = io_header.BitPerPixel; // Number of bits used to represent the data for each pixel.
  colored_header.Compression = io_header.Compression; // Value indicating what type of compression.
  colored_header.ImageSize = ceil((float) colored_header.Width * 3.0 / 4.0) * 4 * colored_header.Height; //compute the image size
  colored_header.Size = io_header.Size - io_header.ImageSize + colored_header.ImageSize;//compute the file size
  colored_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
  colored_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
  colored_header.Colors = io_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
  colored_header.ImportantColors = io_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  colored_imageData = (unsigned char *) malloc(colored_header.ImageSize);//allocate memory space for colored image 
  
  fillings = (4 - (colored_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_colored = colored_header.Width * 3 + fillings; // The number of bytes in a row of the original image.
  
  for(i=0; i<colored_header.Height; i++){//go throw all the rows
  	for(j=0; j<colored_header.Width; j++){//go throw all the pixel
  		k_colored = i * rowSize_colored + 3 * j;// Pixel index of the reduced input image.
  		colored_imageData[k_colored] = c_3;//blue level
  		colored_imageData[k_colored + 1] = c_2;//green level
  		colored_imageData[k_colored + 2] = c_1;//red level
	  }
  }
  
 // Peform the merge operation.
  // Reuse rowSize and rowSize_reduced computed earlier.
  for (i = 0; i < reduced_header.Height; i++) { // Go through all rows of the reduced image.
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each row of the reduced image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      k_1 = (i + io_header.Height / 2 + n*2) * rowSize_colored + (io_header.Width - 1 - j + n*2) * 3 ; // 1st quadrant.
      k_2 = (i + io_header.Height / 2 + n*2 ) * rowSize_colored + (j + n) * 3; // 2nd quadrant. 
      k_3 = (reduced_header.Height - 1 - i + n) * rowSize_colored + (j + n) * 3; // 3rd quadrant. 
      k_4 = (reduced_header.Height - 1 - i + n) * rowSize_colored + (io_header.Width - 1 - j + n*2) * 3 ; // 4th quadrant.
	  colored_imageData[k_1] = reduced_imageData[k_reduced]; // Copy the pixel in the 1st quadrant.
	  colored_imageData[k_1+1] = reduced_imageData[k_reduced+1];
	  colored_imageData[k_1+2] = reduced_imageData[k_reduced+2];
	  colored_imageData[k_2] = reduced_imageData[k_reduced]; // Copy the pixel in the 2nd quadrant.
	  colored_imageData[k_2+1] = reduced_imageData[k_reduced+1];
	  colored_imageData[k_2+2] = reduced_imageData[k_reduced+2];
	  colored_imageData[k_3] = reduced_imageData[k_reduced]; // Copy the pixel in the 3rd quadrant.
	  colored_imageData[k_3+1] = reduced_imageData[k_reduced+1];
	  colored_imageData[k_3+2] = reduced_imageData[k_reduced+2];
	  colored_imageData[k_4] = reduced_imageData[k_reduced]; // Copy the pixel in the 4th quadrant.
	  colored_imageData[k_4+1] = reduced_imageData[k_reduced+1];
	  colored_imageData[k_4+2] = reduced_imageData[k_reduced+2];
    }
  }
  

  printf(">>>> File header of the merged image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_frame_merged"), ".bmp")); // Print the file header message.
  print_header(colored_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  
  // Write image to file "AAA_merged.bmp"
  // The merged file reuse the header, palette, image_Data of the input image.
  write_image_file(file_name, colored_header, io_palette, colored_imageData);//write image to "file_name_frame_merged" 

  free(io_palette); // Release memory space of palette of the input image.
  free(io_imageData); // Release memory space of image pixel data of the input image.
  free(reduced_imageData); // Release memory space of image pixel data of the reduced image.
  free(colored_imageData);//releade memory space of image pixel data of the colored image
  
  system("pause"); 
  return 0;
}

