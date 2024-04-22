/* This program reads a bitmap image file, performs a quarter reduction, 
   and then a merged transformation. */
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
  Header frame_header;
  int frame_size;
  int frame_color[3];
  unsigned char	*frame_imageData;
  int rowSize_frame;
  int a1, a2, a3; //postion
  
  printf("Enter the size of frame in pixel (between 4 and 20):");
  scanf("%d",&frame_size);
  printf("\nEnter the RGB value of the frame color:"); 
  scanf("%d %d %d",&frame_color[0],&frame_color[1],&frame_color[2]) ;
  

  if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
    printf("Please enter an image file name without .bmp extension.\n");
    return 1;
  }
  else if (argc>2) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    return 1;
  }

  // The input command has two or three strings, the 2nd one is the name of the input file.
  // Since strcat has a side effect to change str1, strcpy(file_name, argv[1]) is used to preserve
  // file name argv[1].
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

/*===================================================================*/
/* For every entry in the palette, four bytes are used to describe   */
/* the RGB values of the color in the following way:                 */
/*   1 byte for blue component                                       */
/*   1 byte for green component                                      */
/*   1 byte for red component                                        */
/*   1 byte filter which is set to 0 (zero)                          */
/* Constant 14 is the lenght of the file header.                     */
/*===================================================================*/
  io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14); // Allocate memory space for the palette.
  fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);  // Read palette from the image file.

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
  io_imageData = (unsigned char *) malloc(io_header.ImageSize); // Allocate memory space for image pixel data.
  fread(io_imageData, io_header.ImageSize, 1, fptr); // Read image pixel data from the image file.
	
  fclose(fptr); // Close the input file.
   
  // Print the input image file head.
  printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); // Print the file header message.
  print_header(io_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  
  // Create file head of the quaterly reduced image.
  // Copy the fields of the input image header.
  reduced_header.Type[0] = 'B'; // Two fixed characters, "BM".
  reduced_header.Type[1] = 'M';
  reduced_header.Size = io_header.Size; // File size in bytes.
  for (i=0; i<4; i++) // Reserved field, four characters.
    reduced_header.Reserved[i] = io_header.Reserved[i];
  reduced_header.OffsetBits = io_header.OffsetBits; // Offset.
  reduced_header.InfoSize = io_header.InfoSize; // Information size in byte.
  // Update the width and length of the image pixels, half size of the input image.
  // If the input image has odd width or length, take the ceiling.
  reduced_header.Width = ceil((float) io_header.Width / 2.0); // Image width in pixel.
  reduced_header.Height = ceil((float) io_header.Height / 2.0); // Image height in pixel.
  reduced_header.Planes = io_header.Planes; // Number of image planes in the image, must be 1.
  reduced_header.BitPerPixel = io_header.BitPerPixel; // Number of bits used to represent the data for each pixel.
  reduced_header.Compression = io_header.Compression; // Value indicating what type of compression.
  // Size of the actual pixel data, in bytes.
  // Compute the image size of the reduced image.
  // "ceil((float) reduced_header.Width * 3.0 / 4.0) * 4" makes the number of bytes of a row to be
  // greater than or eqaul to width*3 and a multiple of 4.
  reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; 
  // Compute the file size in bytes.
  reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;
  reduced_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
  reduced_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
  reduced_header.Colors = io_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
  reduced_header.ImportantColors = io_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  
  // Allocate memory space for image pixel data of the reduced image.
  reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  
  // Perform image reduction.// Copy even rows and enen columns of the original input image data to the reduced image.
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
  printf("******************************************************************\n\n"); // Print a separate line.
  
  // Write image to file "AAA_reduced.bmp"
  // The file name is reused and the palette is the same as the original image.
  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  
  
  frame_header.Type[0] = 'B'; // Two fixed characters, "BM".
  frame_header.Type[1] = 'M';
  frame_header.Size = io_header.Size; // File size in bytes.
  for (i=0; i<4; i++) // Reserved field, four characters.
    frame_header.Reserved[i] = io_header.Reserved[i];
  frame_header.OffsetBits = io_header.OffsetBits; // Offset.
  frame_header.InfoSize = io_header.InfoSize; // Information size in byte.
  // Update the width and length of the image pixels, half size of the input image.
  // If the input image has odd width or length, take the ceiling.
  frame_header.Width = ceil((float) io_header.Width + frame_size*3); // Image width in pixel.
  frame_header.Height = ceil((float) io_header.Height + frame_size*3); // Image height in pixel.
  frame_header.Planes = io_header.Planes; // Number of image planes in the image, must be 1.
  frame_header.BitPerPixel = io_header.BitPerPixel; // Number of bits used to represent the data for each pixel.
  frame_header.Compression = io_header.Compression; // Value indicating what type of compression.
  // Size of the actual pixel data, in bytes.
  // Compute the image size of the reduced image.
  // "ceil((float) reduced_header.Width * 3.0 / 4.0) * 4" makes the number of bytes of a row to be
  // greater than or eqaul to width*3 and a multiple of 4.
  frame_header.ImageSize = ceil((float) frame_header.Width * 3.0 / 4.0) * 4 * frame_header.Height; 
  // Compute the file size in bytes.
  frame_header.Size = io_header.Size - io_header.ImageSize + frame_header.ImageSize;
  frame_header.XResolution = io_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
  frame_header.YResolution = io_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
  frame_header.Colors = io_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
  frame_header.ImportantColors = io_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  
  // Allocate memory space for image pixel data of the reduced image.
  frame_imageData = (unsigned char *) malloc(frame_header.ImageSize);
  // Peform the merge operation.
  fillings = (4 - (frame_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  rowSize_frame = frame_header.Width * 3 + fillings; // The number of bytes in a row of the reduced image
  // Reuse rowSize and rowSize_reduced computed earlier.
  for (i = 0; i < reduced_header.Height; i++) { // Go through all rows of the reduced image.
    for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each row of the reduced image.
      k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
      // Computer pixel index of the merged image.
      // Note that row 0 is the bottom row and column 0 is the left-most column.
      k_1 = (i + frame_header.Height - frame_size-reduced_header.Height) * rowSize_frame + (frame_header.Width - frame_size - 1 - j) * 3; // 1st quadrant.
      k_2 = (i + frame_header.Height - frame_size-reduced_header.Height) * rowSize_frame + (j+frame_size) * 3; // 2nd quadrant. 
      k_3 = (frame_header.Height - frame_size*2 - reduced_header.Height - 1 - i) * rowSize_frame + (j+frame_size) * 3; // 3rd quadrant. 
      k_4 = (frame_header.Height - frame_size*2 - reduced_header.Height - 1 - i) * rowSize_frame + (frame_header.Width - frame_size - 1 - j) * 3; // 4th quadrant.
	  frame_imageData[k_1] = reduced_imageData[k_reduced]; // Copy the pixel in the 1st quadrant.
	  frame_imageData[k_1+1] = reduced_imageData[k_reduced+1];
	  frame_imageData[k_1+2] = reduced_imageData[k_reduced+2];
	  frame_imageData[k_2] = reduced_imageData[k_reduced]; // Copy the pixel in the 2nd quadrant.
	  frame_imageData[k_2+1] = reduced_imageData[k_reduced+1];
	  frame_imageData[k_2+2] = reduced_imageData[k_reduced+2];
	  frame_imageData[k_3] = reduced_imageData[k_reduced]; // Copy the pixel in the 3rd quadrant.
	  frame_imageData[k_3+1] = reduced_imageData[k_reduced+1];
	  frame_imageData[k_3+2] = reduced_imageData[k_reduced+2];
	  frame_imageData[k_4] = reduced_imageData[k_reduced]; // Copy the pixel in the 4th quadrant.
	  frame_imageData[k_4+1] = reduced_imageData[k_reduced+1];
	  frame_imageData[k_4+2] = reduced_imageData[k_reduced+2];
    }
  }
  
  for(i=0;i<frame_size;i++){
  	for(j=0;j<frame_header.Width;j++){
  		
  		a1 = i * rowSize_frame + j * 3;
  		a2 = (i+frame_size+reduced_header.Height) * rowSize_frame + j * 3;
  		a3 = (i+frame_size*2+reduced_header.Height*2) * rowSize_frame + j * 3;
  		frame_imageData[a1] = frame_color[2]; 
	  	frame_imageData[a1+1] = frame_color[1];
	  	frame_imageData[a1+2] = frame_color[0];
	  	frame_imageData[a2] = frame_color[2]; 
	  	frame_imageData[a2+1] = frame_color[1];
	  	frame_imageData[a2+2] = frame_color[0];
	  	frame_imageData[a3] = frame_color[2]; 
	  	frame_imageData[a3+1] = frame_color[1];
	  	frame_imageData[a3+2] = frame_color[0];
	  }
  }
  for(i=0;i<frame_size;i++){
  	for(j=0;j<frame_header.Height;j++){
  		
  		a1 = j * rowSize_frame + i * 3;
  		a2 = j * rowSize_frame + (i+reduced_header.Width+frame_size) * 3;
  		a3 = j * rowSize_frame + (i+reduced_header.Width*2+frame_size*2) * 3;
  		frame_imageData[a1] = frame_color[2]; 
	  	frame_imageData[a1+1] = frame_color[1];
	  	frame_imageData[a1+2] = frame_color[0];
	  	frame_imageData[a2] = frame_color[2]; 
	  	frame_imageData[a2+1] = frame_color[1];
	  	frame_imageData[a2+2] = frame_color[0];
	  	frame_imageData[a3] = frame_color[2]; 
	  	frame_imageData[a3+1] = frame_color[1];
	  	frame_imageData[a3+2] = frame_color[0];
	  }
  }

  // Print the merged image file head.
  printf(">>>> File header of the merged image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp")); // Print the file header message.
  print_header(frame_header);
  printf("******************************************************************\n\n"); // Print a separate line.
  
  // Write image to file "AAA_merged.bmp"
  // The merged file reuse the header, palette, image_Data of the input image.
  write_image_file(file_name, frame_header, io_palette, frame_imageData);

  free(io_palette); // Release memory space of palette of the input image.
  free(frame_imageData); // Release memory space of image pixel data of the input image.
  free(frame_imageData); // Release memory space of image pixel data of the reduced image.
  
  system("pause"); 
  return 0;
}
