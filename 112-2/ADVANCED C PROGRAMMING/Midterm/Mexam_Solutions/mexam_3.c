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


int main() {
	char fileName[100];
	FILE *fptr; // File pointer 
	Header	header; // Bitmap file header
	unsigned char	*palette; // Pointer: palette.
	unsigned char	*imageData; // Pointer: Image pixel data.
	unsigned long imageSize_merged; // Size of the merged image.
	unsigned width_merged; // Width of the merged image.
	unsigned height_merged; // Height of the merged image.
	unsigned char *imageData_merged;  // Image data of the merged image.
	unsigned frame_width = 15; // Frame width is 15 pixels.
	unsigned char frame_R = 20; // Frame color of R.
	unsigned char frame_G = 240; // Frame color of G.
	unsigned char frame_B = 240; // Frame color of B.
	int rowSize; // Number of bytes in a row. 
	int rowSize_merged; // Number of bytes in a row of the merged image. 
	int orientation; // Orientation of the original image, 0: portrait, 1: landscape.
	int i, j; // Loop variable.
	int k; // Pixel index of the original image.
	int k1, k2; // Pixel indices of left/right or top/bottom of the merged image.

	do {
		// Input the file name of a bitmap image.
		printf("Enter the name of the image file: ");
		scanf("%s", fileName);
		// Read image file.
		fptr = fopen(fileName, "rb"); // Open the input file using binary mode.
	} while (fptr==NULL); // Repeat if file open fails.
  
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
	
	if (header.Height>header.Width) orientation = 0; // Portrait orientation.
	else orientation = 1; // Landscape orientation.
	 
	// The number of bytes in a row of the input image.
	rowSize = ceil((header.Width * 3) / 4.0) * 4; 
	
	if (orientation==0) {
		// Perform transformation of mirror reflection along the vertical line on the center of the image
		// and attach the transformed on the right-hand-side of the original image with a frame surrounding
		// the merged image and a central vertical bar.
		
		// Allocate memory for the merged image.
		width_merged = header.Width * 2 + frame_width * 3; // Width of the merged image with frame.
		height_merged = header.Height + frame_width * 2; // Height of the merged image with frame.
  		rowSize_merged = ceil((width_merged * 3) / 4.0) * 4; // The number of bytes in a row of the merged image.
  		imageSize_merged = height_merged * rowSize_merged; // Image size of the merged image.
  		imageData_merged = (unsigned char *) malloc(imageSize_merged); // Allocate memory space for image pixel data of the merged image.
  		// Paint the merged image with the frame color.
  		for (i=0; i<height_merged; i++)
  			for (j=0; j<width_merged; j++) {
  				k = i * rowSize_merged + j * 3;
  				imageData_merged[k] = frame_B;
  				imageData_merged[k+1] = frame_G;
  				imageData_merged[k+2] = frame_R;
			}
			
		// Copy image pixels.
		for (i = 0; i < header.Height; i++) { // Go through all rows.
			for (j = 0; j < header.Width; j++) { // Go through all pixels on a row of the original image.
				k = i * rowSize + j * 3; // The index of the pixel in row i of the original image.
				// The index of the pixel on the left hlaf in row i of the merged image.
				k1 = (frame_width + i) * rowSize_merged + (frame_width + j) * 3; 
				// The index of the pixel on the right hlaf in row i of the merged image.
				k2 = (frame_width + i) * rowSize_merged + (header.Width * 2 + frame_width * 2 -1 - j) * 3; 
				// Copy blue level.
				imageData_merged[k1] = imageData[k];
				imageData_merged[k2] = imageData[k];
				// Copy green level.
				imageData_merged[k1+1] = imageData[k+1];
				imageData_merged[k2+1] = imageData[k+1];
				// Copy red level.
				imageData_merged[k1+2] = imageData[k+2];
				imageData_merged[k2+2] = imageData[k+2];
			}
		}		
		strcpy(fileName, "portrait.bmp"); // File name of the merged image.
	}
	else {
		// Perform transformation of mirror reflection along the horizontal line on the center of the image 
		// and attach the transformed on the bottom of the original image with a frame surrounding the merged 
		// image with a central horizontal bar.
		
		// Allocate memory for the merged image.
		width_merged = header.Width + frame_width * 2; // Width of the merged image with frame.
		height_merged = header.Height * 2 + frame_width * 3; // Height of the merged image with frame.
  		rowSize_merged = ceil((width_merged * 3) / 4.0) * 4; // The number of bytes in a row of the merged image.
  		imageSize_merged = height_merged * rowSize_merged; // Image size of the merged image.
  		imageData_merged = (unsigned char *) malloc(imageSize_merged); // Allocate memory space for image pixel data of the merged image.
  		// Paint the merged image with the frame color.
  		for (i=0; i<height_merged; i++)
  			for (j=0; j<width_merged; j++) {
  				k = i * rowSize_merged + j * 3;
  				imageData_merged[k] = frame_B;
  				imageData_merged[k+1] = frame_G;
  				imageData_merged[k+2] = frame_R;
			}
			
		// Copy image pixels.
		for (i = 0; i < header.Height; i++) { // Go through all rows.
			for (j = 0; j < header.Width; j++) { // Go through all pixels on a row of the original image.
				k = i * rowSize + j * 3; // The index of the pixel in row i of the original image.
				// The index of the pixel on the top hlaf in row i of the merged image.
				k1 = (header.Height + frame_width * 2 + i) * rowSize_merged + (j + frame_width) * 3; 
				// The index of the pixel on the bottom hlaf in row i of the merged image.
				k2 = (header.Height - 1 + frame_width - i) * rowSize_merged + (j + frame_width) * 3; 
				// Copy blue level.
				imageData_merged[k1] = imageData[k];
				imageData_merged[k2] = imageData[k];
				// Copy green level.
				imageData_merged[k1+1] = imageData[k+1];
				imageData_merged[k2+1] = imageData[k+1];
				// Copy red level.
				imageData_merged[k1+2] = imageData[k+2];
				imageData_merged[k2+2] = imageData[k+2];
			}
		}		
		strcpy(fileName, "landscape.bmp"); // File name of the merged image.
	} 

	// Open output the merged of fileName.
	fptr = fopen(fileName, "wb"); // Open the output file using binary mode.
  
	// Modify the bitmap file header.
	header.Size = header.Size - header.ImageSize + imageSize_merged;
	header.Width =  width_merged;
	header.Height = height_merged;
	header.ImageSize = imageSize_merged;
  
	// Write the file header and image information of the merged image.
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

	// Write the color palette and image data of the merged image.
	fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); // Write the palette.
	fwrite(imageData_merged, 1, header.ImageSize, fptr); // Write the image pixel data of the merged image.
  
	fclose(fptr); // Close the output file.
 
	// Print the file header and image information of the merged image.
	printf("\n>>>> File header and image information of the merged image: %s\n\n", fileName);
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

	// Free memory space of color palette, image data of the original image and the merged image.
	free(palette); // Release memory space of palette.
	free(imageData); // Release memory space of image pixel data.
	free(imageData_merged); // Release memory space of image pixel data of the merged image.
	return 0;
}
