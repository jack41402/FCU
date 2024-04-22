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
}


// Write the image file.
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
	FILE *fptr; // File pointer. 
	fptr = fopen(fname, "wb"); // Open the output file using binary mode.
	// Output the an image file to disk.
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
	Header input_header; // Bitmap file header of the input (original/merged) image.
	unsigned char	*input_palette; // Pointer: input image palette.
	unsigned char	*input_imageData; // Pointer: input image pixel data.
	Header reduced_header; // Bitmap file header of the reduced image.
	// The reduced image will use the same palette of input image.
	unsigned char	*reduced_imageData; // Pointer: reduced image pixel data.
	Header merged_header; // Bitmap file header of the merged image.
	// The merged image is the same palette of input image.
	unsigned char	*merged_imageData; // Pointer: merged image pixel data.
	char file_name[40];
	int frame_size; // Size of frame in pixel.
	unsigned frame_R, frame_G, frame_B; // RGB value of frame pixels.   
	int rowSize_input; // Number of bytes in a row of the input image. 
	int rowSize_reduced; // Number of bytes in a row of the reduced image.
	int rowSize_merged; // Number of bytes in a row of the merged image with frame.
	int i, j; // Loop variable.
	int k; // Index of the pixel in the orignal image.
	int k_reduced; // Index of the pixel in the reduced image.
	int k_1, k_2, k_3, k_4; // k_i is the index of the pixel in the i-th quadrant of the merged image.

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
  
	do { // Input frame size in pixel.
		printf("Enter the size of frame in pixel (between 4 and 20): ");
		scanf("%d", &frame_size); 
	} while (frame_size<4 || frame_size>20);
	
	// Select the frame color. 
	printf("\nEnter RGB value of the frame color: ");
	scanf("%u %u %u", &frame_R, &frame_G, &frame_B);
	printf("\n");

	// Input the colored image file.
	fread(&input_header.Type, 1, 2, fptr); // Two fixed characters, "BM".
	fread(&input_header.Size, 4, 1, fptr); // File size in bytes.
	fread(&input_header.Reserved, 1, 4, fptr); // Reserved field.
	fread(&input_header.OffsetBits, 4, 1, fptr); // Offset.
	fread(&input_header.InfoSize, 4, 1, fptr); // Information size in byte.
	fread(&input_header.Width, 4, 1, fptr); // Image width in pixel.
	fread(&input_header.Height, 4, 1, fptr); // Image height in pixel.
	fread(&input_header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
	fread(&input_header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
	fread(&input_header.Compression, 4, 1, fptr); // Value indicating what type of compression.
	fread(&input_header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
	fread(&input_header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
	fread(&input_header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
	fread(&input_header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
	fread(&input_header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

	/*===================================================================*/
	/* For every entry in the palette, four bytes are used to describe   */
	/* the RGB values of the color in the following way:                 */
	/*   1 byte for blue component                                       */
	/*   1 byte for green component                                      */
	/*   1 byte for red component                                        */
	/*   1 byte filter which is set to 0 (zero)                          */
	/* Constant 14 is the lenght of the file header.                     */
	/*===================================================================*/
	input_palette = (unsigned char *) malloc(input_header.OffsetBits - input_header.InfoSize - 14); // Allocate memory space for the palette.
	fread(input_palette, input_header.OffsetBits - input_header.InfoSize - 14, 1, fptr);  // Read palette from the image file.

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
	input_imageData = (unsigned char *) malloc(input_header.ImageSize); // Allocate memory space for image pixel data.
	fread(input_imageData, input_header.ImageSize, 1, fptr); // Read image pixel data from the image file.
	
	fclose(fptr); // Close the input file.
   
	// Print the input image file head.
	printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); // Print the file header message.
	print_header(input_header);
	printf("******************************************************************\n\n"); // Print a separate line.
  
	// Create file head of the quaterly reduced image.
	// Copy the fields of the input image header.
	reduced_header.Type[0] = 'B'; // Two fixed characters, "BM".
	reduced_header.Type[1] = 'M';
	reduced_header.Size = input_header.Size; // File size in bytes.
	for (i=0; i<4; i++) // Reserved field, four characters.
		reduced_header.Reserved[i] = input_header.Reserved[i];
	reduced_header.OffsetBits = input_header.OffsetBits; // Offset.
	reduced_header.InfoSize = input_header.InfoSize; // Information size in byte.
	// Update the width and length of the image pixels, half size of the input image.
	// If the input image has odd width or length, take the ceiling.
	reduced_header.Width = ceil((float) input_header.Width / 2.0); // Image width in pixel.
	reduced_header.Height = ceil((float) input_header.Height / 2.0); // Image height in pixel.
	reduced_header.Planes = input_header.Planes; // Number of image planes in the image, must be 1.
	reduced_header.BitPerPixel = input_header.BitPerPixel; // Number of bits used to represent the data for each pixel.
	reduced_header.Compression = input_header.Compression; // Value indicating what type of compression.
	// Size of the actual pixel data, in bytes.
	// Compute the image size of the reduced image.
	// "ceil((float) reduced_header.Width * 3.0 / 4.0) * 4" makes the number of bytes of a row to be
	// greater than or eqaul to width*3 and a multiple of 4.
	reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; 
	// Compute the file size in bytes.
	reduced_header.Size = input_header.Size - input_header.ImageSize + reduced_header.ImageSize;
	reduced_header.XResolution = input_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
	reduced_header.YResolution = input_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
	reduced_header.Colors = input_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
	reduced_header.ImportantColors = input_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  
	// Allocate memory space for image pixel data of the reduced image.
	reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  
	// Perform image reduction.// Copy even rows and enen columns of the original input image data to the reduced image.
	// Compute the row size of the original image.
	rowSize_input = ceil((float) input_header.Width * 3.0 / 4.0) * 4; // The number of bytes in a row of the original image.
  
	// Compute the row size of the reduced image.
	rowSize_reduced = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4; // The number of bytes in a row of the reduced image.
	// Copy even rows and enen columns of the original input image data to the reduced image.
	for (i = 0; i < reduced_header.Height; i++) // Go through all rows of the reduced image.
		for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each of the reduced image.
			k = i * 2 * rowSize_input + j * 2 * 3; // Pixel index of the original input image.
			k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
			reduced_imageData[k_reduced] = input_imageData[k]; // Copy blue level.
			reduced_imageData[k_reduced+1] = input_imageData[k+1]; // Copy green level.
			reduced_imageData[k_reduced+2] = input_imageData[k+2]; // Copy red level
	    }

	// Print the reduced image file head.
	printf(">>>> File header of the reduced image, %s:\n\n", 
		   strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); // Print the file header message.
	print_header(reduced_header);
	printf("******************************************************************\n\n"); // Print a separate line.
  
	// Write image to file "AAA_reduced.bmp"
	// The file name is reused and the palette is the same as the original image.
	write_image_file(file_name, reduced_header, input_palette, reduced_imageData);
  
	// Create file head of the merged image.
	// Copy the fields of the input image header.
	merged_header.Type[0] = 'B'; // Two fixed characters, "BM".
	merged_header.Type[1] = 'M';
	merged_header.Size = input_header.Size; // File size in bytes.
	for (i=0; i<4; i++) // Reserved field, four characters.
		merged_header.Reserved[i] = input_header.Reserved[i];
	merged_header.OffsetBits = input_header.OffsetBits; // Offset.
	merged_header.InfoSize = input_header.InfoSize; // Information size in byte.
	// Update the width and length of the image pixels, half size of the input image.
	// If the input image has odd width or length, take the ceiling.
	merged_header.Width = reduced_header.Width * 2 + frame_size * 3; // Image width in pixel with frame.
	merged_header.Height = reduced_header.Height * 2 + frame_size * 3; // Image height in pixel with frame.
	merged_header.Planes = input_header.Planes; // Number of image planes in the image, must be 1.
	merged_header.BitPerPixel = input_header.BitPerPixel; // Number of bits used to represent the data for each pixel.
	merged_header.Compression = input_header.Compression; // Value indicating what type of compression.
	// Size of the actual pixel data, in bytes.
	// Compute the image size of the merged image.
	// "ceil((float) merged_header.Width * 3.0 / 4.0) * 4" makes the number of bytes of a row to be
	// greater than or eqaul to width*3 and a multiple of 4.
	merged_header.ImageSize = ceil((float) merged_header.Width * 3.0 / 4.0) * 4 * merged_header.Height; 
	// Compute the file size in bytes.
	merged_header.Size = input_header.Size - input_header.ImageSize + merged_header.ImageSize;
	merged_header.XResolution = input_header.XResolution; // Preferred horizontal resolution of the image, in pixels per meter.
	merged_header.YResolution = input_header.YResolution; // Preferred vertical resolution of the image, in pixels per meter.
	merged_header.Colors = input_header.Colors; // Value is zero except for indexed images using fewer than the maximum number of colors.
	merged_header.ImportantColors = input_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  
	// Allocate memory space for image pixel data of the merged image.
	merged_imageData = (unsigned char *) malloc(merged_header.ImageSize); 
	
	rowSize_merged = ceil((float) merged_header.Width * 3.0 / 4.0) * 4; // Row size of the merged image.
	
	// Set all pixels of the merged to be the frame color.
	for (i = 0; i < merged_header.Height; i++) // Go through all rows of the merged image.
		for (j = 0; j < merged_header.Width; j++) { // Go through all pixels in each row of the merged image.
			k = i * rowSize_merged + j * 3; // Pixel index of the merged image.
			merged_imageData[k] = (unsigned char) frame_B; // Set blue value of the frame color. 
			merged_imageData[k+1] = (unsigned char) frame_G; // Set gteen value of the frame color.
			merged_imageData[k+2] = (unsigned char) frame_R; // Set red value of the frame color.
		}			 

	// Peform the merge operation.
	// Reuse rowSize and rowSize_reduced computed earlier.
	for (i = 0; i < reduced_header.Height; i++) { // Go through all rows of the reduced image.
		for (j = 0; j < reduced_header.Width; j++) { // Go through all pixels in each row of the reduced image.
			k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
			// Computer pixel index of the merged image.
			// Note that row 0 is the bottom row and column 0 is the left-most column.
			k_1 = (reduced_header.Height + frame_size * 2 + i) * rowSize_merged + (reduced_header.Width * 2 - 1 + frame_size * 2 - j) * 3; // 1st quadrant.
			k_2 = (reduced_header.Height + frame_size * 2 + i) * rowSize_merged + (frame_size + j) * 3; // 2nd quadrant. 
			k_3 = (reduced_header.Height - 1 + frame_size - i) * rowSize_merged + (frame_size + j) * 3; // 3rd quadrant. 
			k_4 = (reduced_header.Height - 1 + frame_size - i) * rowSize_merged + (reduced_header.Width * 2 - 1 + frame_size * 2 - j) * 3; // 4th quadrant.
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

	// Print the merged image file head.
	printf(">>>> File header of the frame merged image, %s:\n\n", 
           strcat(strcat(strcpy(file_name, argv[1]), "_frame_merged"), ".bmp")); // Print the file header message.
	print_header(merged_header);
	printf("******************************************************************\n\n"); // Print a separate line.
  
	// Write image to file "AAA_merged.bmp"
	// The merged file reuse the header, palette, image_Data of the input image.
	write_image_file(file_name, merged_header, input_palette, merged_imageData);

	free(input_palette); // Release memory space of palette of the input image.
	free(input_imageData); // Release memory space of image pixel data of the input image.
	free(reduced_imageData); // Release memory space of image pixel data of the reduced image.
	free(merged_imageData); // Release memory space of image pixel data of the merged image.
	
	return 0;
}
