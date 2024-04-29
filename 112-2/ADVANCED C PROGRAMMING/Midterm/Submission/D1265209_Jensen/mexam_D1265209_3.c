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
  
	// Read file header and image information.  
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
  	fread(&header.Type,1,2,fptr);
  	fread(&header.Size,4,1,fptr);
  	fread(&header.Reserved,2,1,fptr);
  	fread(&header.OffsetBits,4,1,fptr);
  	fread(&header.InfoSize,4,1,fptr);
  	fread(&header.Width,4,1,fptr);
  	fread(&header.Height,4,1,fptr);
  	fread(&header.Planes,1,4,fptr);
  	fread(&header.BitPerPixel,1,4,fptr);
  	fread(&header.Compression,4,1,fptr);
  	fread(&header.ImageSize,4,1,fptr);
  	fread(&header.XResolution,4,1,fptr);
  	fread(&header.YResolution,4,1,fptr);
  	fread(&header.Colors,4,1,fptr);
  	fread(&header.ImportantColors,4,1,fptr);
  	
	// Allocate memory space for color palette and read color palette. 
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
	palette = (unsigned char*) malloc(header.Size);
	fread(palette, 1, header.Size, fptr);
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
	imageData = (unsigned char*) malloc(header.OffsetBits-header.InfoSize-14);
	fread(imageData,1,header.OffsetBits-header.InfoSize-14,fptr); 
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
	
	if(orientation=1){
		width_merged = ceil((float)header.Width + frame_width *2 );
		height_merged = ceil((float)header.Height *2 + frame_width *2);
		rowSize_merged = (4-(header.Width*3)%4)%4;  
		
		for(i=0; i<width_merged; i++){
			for(j=0; j<height_merged; j++){
				k = i*rowSize_merged+j*3;
				imageData_merged[k] = frame_R;
				imageData_merged[k+1] = frame_G;
				imageData_merged[k+2] = frame_B;
			}
		}
		
		for(i=0; i<header.Width; i++){
			for(j=0; j<header.Height; j++){
				k1 = (frame_width + i) * rowSize + (frame_width) + j*3;
				k2 = (frame_width*2 + header.Height + i) * rowSize + (frame_width) + j*3;
			}
		}
		
		for(i=0; i<header.Width; i++){
			for(j=0; j<header.Height; j++){
				k=i*rowSize+j*3;
				imageData_merged[k1]=imageData[k];
				imageData_merged[k1+1]=imageData[k+1];
				imageData_merged[k1+2]=imageData[k+2];
				imageData_merged[k2]=imageData[k];
				imageData_merged[k2+1]=imageData[k+1];
				imageData_merged[k2+2]=imageData[k+2];
			}
		}
	}
	
	else if(orientation=0){
		width_merged = ceil((float)header.Width *2 + frame_width *2);
		height_merged = ceil((float)header.Height + frame_width *2);
		rowSize_merged = (4-(header.Width*3)%4)%4;  
		
		for(i=0; i<width_merged; i++){
			for(j=0; j<height_merged; j++){
				k =i*rowSize_merged+j*3;
				imageData_merged[k] = frame_R;
				imageData_merged[k+1] = frame_G;
				imageData_merged[k+2] = frame_B;
			}
		}
		
		for(i=0; i<header.Width; i++){
			for(j=0; j<header.Height; j++){
				k1 = (frame_width + i) * rowSize + (frame_width) + j*3;
				k2 = (frame_width * 2 + header.Width + i) * rowSize + (frame_width) + j*3;
			}
		}
		
		for(i=0; i<header.Width; i++){
			for(j=0; j<header.Height; j++){
				k=i*rowSize+j*3;
				imageData_merged[k1]=imageData[k];
				imageData_merged[k1+1]=imageData[k+1];
				imageData_merged[k1+2]=imageData[k+2];
				imageData_merged[k2]=imageData[k];
				imageData_merged[k2+1]=imageData[k+1];
				imageData_merged[k2+2]=imageData[k+2];
			}
		}
	}

		
	/* 3. Output the merged image to disk using file name portrait.bmp or landscape.bmp for a portrait or a
		   landscape of the original image, respectively.
	*/
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/ 
	fwrite(&header.Type,1,2,fptr);
  	fwrite(&header.Size,4,1,fptr);
  	fwrite(&header.Reserved,2,1,fptr);
  	fwrite(&header.OffsetBits,4,1,fptr);
  	fwrite(&header.InfoSize,4,1,fptr);
  	fwrite(&header.Width,4,1,fptr);
  	fwrite(&header.Height,4,1,fptr);
  	fwrite(&header.Planes,1,4,fptr);
  	fwrite(&header.BitPerPixel,1,4,fptr);
  	fwrite(&header.Compression,4,1,fptr);
  	fwrite(&header.ImageSize,4,1,fptr);
  	fwrite(&header.XResolution,4,1,fptr);
  	fwrite(&header.YResolution,4,1,fptr);
  	fwrite(&header.Colors,4,1,fptr);
  	fwrite(&header.ImportantColors,4,1,fptr);
  	
	fclose(fptr); // Close the output file.
 
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
	free(imageData);
	free(imageData_merged);
	free(palette);
	return 0;
	
}
