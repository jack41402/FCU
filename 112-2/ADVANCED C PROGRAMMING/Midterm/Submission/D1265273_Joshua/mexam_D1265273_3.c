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
	int fillings;
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
  
	// Read file header and image information.  
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
  fread(&header.Type, 1, 2, fptr);
  fread(&header.Size, 4, 1, fptr);
  fread(&header.Reserved, 1, 4, fptr);
  fread(&header.OffsetBits, 4, 1, fptr);
  fread(&header.InfoSize, 4, 1, fptr);
  fread(&header.Width, 4, 1, fptr);
  fread(&header.Height, 4, 1, fptr);
  fread(&header.Planes, 2, 1, fptr);
  fread(&header.BitPerPixel, 2, 1, fptr);
  fread(&header.Compression, 4, 1, fptr);
  fread(&header.ImageSize, 4, 1, fptr);
  fread(&header.XResolution, 4, 1, fptr);
  fread(&header.YResolution, 4, 1, fptr);
  fread(&header.Colors, 4, 1, fptr);
  fread(&header.ImportantColors, 4, 1, fptr);
	// Allocate memory space for color palette and read color palette. 
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
  palette = (unsigned char*)malloc(header.OffsetBits - header.InfoSize - 14);
  fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);
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
	// Allocate memory space for image data and read image data. 
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
  imageData = (unsigned char*)malloc(header.ImageSize);
  fread(imageData, header.ImageSize, 1, fptr);
	fclose(fptr); // Close the input file.
	
	if (header.Height>header.Width) orientation = 0; // Portrait orientation.
	else orientation = 1; // Landscape orientation.
	/* 2. Depending whether the image is a portrait or a landscape, perform the following image processing:
          2.1. If the image is a portrait, perform transformation of mirror reflection along the vertical line 
		       on the center of the image and attach the transformed on the right-hand-side of the original 
			   image with a frame surrounding the merged image and a central vertical bar.
          2.2. If the image is a landscape, perform transformation of mirror reflection along the horizontal line 
		       on the center of the image and attach the transformed on the bottom of the original image with a 
			   frame surrounding the merged image with a central horizontal bar.
	*/ 
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
		
	if (orientation == 1)
	{
		width_merged = header.Width + 2 * frame_width;
		printf("%d\n", width_merged);
		height_merged = header.Height * 2 + 3 * frame_width;
		printf("%d\n", height_merged);
		rowSize = header.Width * 3 ;
		rowSize_merged = width_merged * 3 ;
		imageSize_merged = width_merged*3 * height_merged*rowSize_merged;
		header.Size = header.Size - header.ImageSize + imageSize_merged;
		imageData_merged = (unsigned char*)malloc(imageSize_merged);
		for (i=0; i<height_merged; i++)
		{
			k = i * rowSize + j * 3;
			for (j=0; j<width_merged; j++)
			{
				if (i<frame_width || i>=frame_width+header.Height && i<header.Height + frame_width*2 || i>=2*frame_width+2*header.Height )
				{
					k1 = i* rowSize_merged + j*3;
					imageData_merged[k1] = frame_B ;
					imageData_merged[k1 + 1]= frame_G;
					imageData_merged[k1+2] = frame_R;
				}
				else if (i>=frame_width &&i<frame_width+header.Height && j<frame_width || i>=frame_width &&i<frame_width+header.Height && j>=frame_width+header.Width || i>=frame_width*2+header.Height && i<frame_width*2+header.Height*2 &&j<frame_width || i>=frame_width*2+header.Height && i<frame_width*2+header.Height*2 &&j>=frame_width+header.Width)
				{
					k1 = i* rowSize_merged + j*3;
					imageData_merged[k1] = frame_B ;
					imageData_merged[k1+1]= frame_G;
					imageData_merged[k1+2] = frame_R;
				}
				else if (i>=frame_width && i<frame_width+header.Height &&j>=frame_width && j<frame_width+header.Width)
				{
					for (i=0; i<header.Height; i++)
					{
						k = i * rowSize + j * 3;
						for (j=0; j<header.Width; j++)
						{
							k2 = (frame_width + header.Height - i)*rowSize + j*3+frame_width;
							imageData_merged[k2] = imageData[k];
							imageData_merged[k2+1] = imageData[k+1];
							imageData_merged[k2+2] = imageData[k+2];
						}
					}
				}
				else if (i>=2*frame_width + header.Height && i<2*frame_width + 2*header.Height && j>=frame_width && j<frame_width+header.Width)
				{
					for (i=0; i<header.Height; i++)
					{
						k = i * rowSize + j * 3;
						for (j=0; j<header.Width; j++)
						{
							k2 = (2*frame_width + header.Height + i)*rowSize + j*3+frame_width;
							imageData_merged[k2] = imageData[k];
							imageData_merged[k2+1] = imageData[k+1];
							imageData_merged[k2+2] = imageData[k+2];
						}
					}
				}
			}
		}	
	} 
	else if (orientation == 0)
	{
		width_merged = header.Width*2 + 3 * frame_width;
		height_merged = header.Height + 2 * frame_width;
		fillings = (4-(header.Width * 3)%4)%4;
		rowSize = header.Width * 3 + fillings;
		rowSize_merged = width_merged * 3 + fillings;
		imageSize_merged = width_merged*3 * height_merged*rowSize_merged;
		header.Size = header.Size - header.ImageSize + imageSize_merged;
		imageData_merged = (unsigned char*)malloc(imageSize_merged);
		for (i=0; i<height_merged; i++)
		{
			for (j=0; j<width_merged; j++)
			{
				if (i<frame_width || i>=frame_width+header.Height )
				{
					k1 = i* rowSize_merged + j*3;
					imageData_merged[k1] = frame_B ;
					imageData_merged[k1 + 1]= frame_G;
					imageData_merged[k1+2] = frame_R;
				}
				else if (i>=frame_width &&i<frame_width + header.Height &&j<frame_width || i>=frame_width &&i<frame_width + header.Height &&j>=frame_width+header.Width &&j<frame_width*2+header.Width || i>=frame_width &&i<frame_width + header.Height &&j>=frame_width*2+header.Width*2 )
				{
					k1 = i* rowSize_merged + j*3;
					imageData_merged[k1] = frame_B ;
					imageData_merged[k1+1]= frame_G;
					imageData_merged[k1+2] = frame_R;
				}
				else if (i>=frame_width &&i<frame_width + header.Height &&j>=frame_width && j<frame_width+header.Width)
				{
					for (i=0; i<header.Height; i++)
					{
						k = i * rowSize + j * 3;
						for (j=0; j<header.Width; j++)
						{
							k2 = (i+frame_width)*rowSize + (j+frame_width)*3;
							imageData_merged[k2] = imageData[k];
							imageData_merged[k2+1] = imageData[k+1];
							imageData_merged[k2+2] = imageData[k+2];
						}
					}
				}
				else if (j>=2*frame_width + header.Width && j<2*frame_width + 2*header.Width && i>=frame_width && i<frame_width+header.Height)
				{
					for (i=0; i<header.Height; i++)
					{
						k = i * rowSize + j * 3;
						for (j=0; j<header.Width; j++)
						{
							k2 = (i+frame_width)*rowSize + (frame_width*2 + header.Width-j)*3;
							imageData_merged[k2] = imageData[k];
							imageData_merged[k2+1] = imageData[k+1];
							imageData_merged[k2+2] = imageData[k+2];
						}
					}
				}
			}
		}
	}
	/* 3. Output the merged image to disk using file name portrait.bmp or landscape.bmp for a portrait or a
		   landscape of the original image, respectively.
	*/
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
  if (orientation == 0)
  {
  	fptr = fopen("portrait.bmp", "wb");
    fwrite(&header.Type, 1, 2, fptr);
    fwrite(&header.Size, 4, 1, fptr);
    fwrite(&header.Reserved, 1, 4, fptr);
    fwrite(&header.OffsetBits, 4, 1, fptr);
    fwrite(&header.InfoSize, 4, 1, fptr);
    fwrite(&width_merged, 4, 1, fptr);
    fwrite(&height_merged, 4, 1, fptr);
    fwrite(&header.Planes, 2, 1, fptr);
    fwrite(&header.BitPerPixel, 2, 1, fptr);
    fwrite(&header.Compression, 4, 1, fptr);
    fwrite(&imageSize_merged, 4, 1, fptr);
    fwrite(&header.XResolution, 4, 1, fptr);
    fwrite(&header.YResolution, 4, 1, fptr);
    fwrite(&header.Colors, 4, 1, fptr);
    fwrite(&header.ImportantColors, 4, 1, fptr);
    fwrite(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);
    fwrite(imageData_merged, imageSize_merged, 1, fptr);
	fclose(fptr); // Close the output file.
  }
  else if (orientation == 1)
  {
  	fptr = fopen("portrait.bmp", "wb");
    fwrite(&header.Type, 1, 2, fptr);
    fwrite(&header.Size, 4, 1, fptr);
    fwrite(&header.Reserved, 1, 4, fptr);
    fwrite(&header.OffsetBits, 4, 1, fptr);
    fwrite(&header.InfoSize, 4, 1, fptr);
    fwrite(&width_merged, 4, 1, fptr);
    fwrite(&height_merged, 4, 1, fptr);
    fwrite(&header.Planes, 2, 1, fptr);
    fwrite(&header.BitPerPixel, 2, 1, fptr);
    fwrite(&header.Compression, 4, 1, fptr);
    fwrite(&header.ImageSize, 4, 1, fptr);
    fwrite(&header.XResolution, 4, 1, fptr);
     fwrite(&header.YResolution, 4, 1, fptr);
    fwrite(&header.Colors, 4, 1, fptr);
    fwrite(&header.ImportantColors, 4, 1, fptr);
    fwrite(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);
    fwrite(imageData_merged, imageSize_merged, 1, fptr);
	fclose(fptr); // Close the output file.
  }
  
 
	// 4. Print the file header and the image information of the merged image on the monitor.
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

	// Free memory space of color palette, image data of the original image and the extended image.
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/
	free(palette);
	free(imageData);
	free(imageData_merged);
	return 0;
}