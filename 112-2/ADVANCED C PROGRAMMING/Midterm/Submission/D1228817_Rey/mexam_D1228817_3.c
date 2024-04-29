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
	char* fileName;
	fileName=malloc(sizeof(char)*100);
	FILE *fptr; // File pointer 
	Header	header; // Bitmap file header
	unsigned char	*palette; // Pointer: palette.
	unsigned char	*imageData, *merged_imageData; // Pointer: Image pixel data.
	unsigned long imageSize_merged; // Size of the merged image.
	unsigned width_merged; // Width of the merged image.
	unsigned height_merged; // Height of the merged image.
	unsigned char *imageData_merged;  // Image data of the merged image.
	unsigned frame_width = 15; // Frame width is 15 pixels.
	unsigned char R = 20; // Frame color of R.
	unsigned char G = 240; // Frame color of G.
	unsigned char B = 240; // Frame color of B.frame_
	int fillings;
	int merged_fillings;
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
  
	fread(&header.Type, 1, 2, fptr); 
	fread(&header.Size, sizeof(unsigned), 1, fptr); 
	fread(&header.Reserved, 1, 4, fptr); 
	fread(&header.OffsetBits, sizeof(unsigned), 1, fptr); 
	fread(&header.InfoSize, sizeof(unsigned), 1, fptr); 
	fread(&header.Width, sizeof(unsigned), 1, fptr); 
	fread(&header.Height, sizeof(unsigned), 1, fptr);  
	fread(&header.Planes, sizeof(unsigned short), 1, fptr); 
	fread(&header.BitPerPixel, sizeof(unsigned short), 1, fptr);  
	fread(&header.Compression, sizeof(unsigned), 1, fptr); 
	fread(&header.ImageSize, sizeof(unsigned), 1, fptr); 
	fread(&header.XResolution, sizeof(unsigned), 1, fptr); 
	fread(&header.YResolution, sizeof(unsigned), 1, fptr);  
	fread(&header.Colors, sizeof(unsigned), 1, fptr); 
	fread(&header.ImportantColors, sizeof(unsigned), 1, fptr); 
  
	palette=malloc(header.OffsetBits-14-header.InfoSize);
	fread(palette, header.OffsetBits-14-header.InfoSize, 1, fptr);

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
	imageData=malloc(header.ImageSize);
	fread(imageData, header.ImageSize, 1, fptr);
	
	fclose(fptr); // Close the input file.
	
	fillings=(4-(header.Width*3)%4)%4;
	rowSize=header.Width*3+fillings;
	
	if (header.Height>header.Width){
		orientation = 0; // Portrait orientation.
		fileName="portrait.bmp";
	} 
	else{
		orientation = 1; // Landscape orientation.
		fileName="landscape.bmp";
	} 
	
	fptr=fopen(fileName, "wb");
	/* 2. Depending whether the image is a portrait or a landscape, perform the following image processing:
          2.1. If the image is a portrait, perform transformation of mirror reflection along the vertical line 
		       on the center of the image and attach the transformed on the right-hand-side of the original 
			   image with a frame surrounding the merged image and a central vertical bar.
          2.2. If the image is a landscape, perform transformation of mirror reflection along the horizontal line 
		       on the center of the image and attach the transformed on the bottom of the original image with a 
			   frame surrounding the merged image with a central horizontal bar.*/ 

	if(orientation == 0){
		width_merged=header.Width*2+frame_width*3;
		height_merged=header.Height+frame_width*2;
		merged_fillings=(4-(width_merged*3)%4)%4;
		imageSize_merged=(width_merged*3+merged_fillings)*height_merged;
		merged_imageData=(unsigned char *)malloc(imageSize_merged);
		rowSize_merged=width_merged*3+merged_fillings;
		

		
		for(i=0; i<height_merged; i++){
			for(j=0; j<width_merged; j++){
				k=rowSize_merged*i+j*3;
				// The index of the pixel on the left hlaf in row i of the merged image.
				k1 = (frame_width + i) * rowSize_merged + (frame_width + j) * 3; 
				// The index of the pixel on the right hlaf in row i of the merged image.
				k2 = (frame_width + i) * rowSize_merged + (header.Width * 2 + frame_width * 2 -1 - j) * 3; 
				
				if(i>frame_width-1&&i<(header.Height+frame_width)&&j>frame_width-1&&j<(2*frame_width+header.Width*2)){
					if(j<frame_width+header.Width-1){
						merged_imageData[k]=imageData[k1];
						merged_imageData[k+1]=imageData[k1+1];
						merged_imageData[k+2]=imageData[k1+2];
						
					}
					else if(j>frame_width*2+header.Width){
						merged_imageData[k]=imageData[k2];
						merged_imageData[k+1]=imageData[k2+1];
						merged_imageData[k+2]=imageData[k2+2];
					}

					else{
						merged_imageData[k]=B;
						merged_imageData[k+1]=G;
						merged_imageData[k+2]=R;
					}
				}
				
				else{
					merged_imageData[k]=B;
					merged_imageData[k+1]=G;
					merged_imageData[k+2]=R;
				}

			}
		}
	}
	
	else{
		
		width_merged=header.Width+frame_width*2;
		height_merged=header.Height*2+frame_width*3;
		merged_fillings=(4-(width_merged*3)%4)%4;
		imageSize_merged=(width_merged*3+merged_fillings)*height_merged;
		merged_imageData=(unsigned char *)malloc(imageSize_merged);
		rowSize_merged=width_merged*3+merged_fillings;
		
		for(i=0; i<height_merged; i++){
	 		for(j=0; j<width_merged; j++){
	 			
				k=rowSize_merged*i+j*3;
				k1=(i-(header.Height+frame_width*2-1))*rowSize+(j-(frame_width-1))*3;
				k2=(i-(frame_width-1))*rowSize+(j-(frame_width-1))*3;
				
				if(i<frame_width*2+header.Height&&i>frame_width-1&&j>frame_width-1&&j<frame_width+header.Width){
					if(i<frame_width+header.Height){
						merged_imageData[k]=imageData[k1];
						merged_imageData[k+1]=imageData[k1+1];
						merged_imageData[k+2]=imageData[k1+2];
						
					}
					else if(i>frame_width&&i<(header.Height*2+frame_width*2)&&j>frame_width&&j<(frame_width+header.Width)){
						merged_imageData[k]=imageData[k2];
						merged_imageData[k+1]=imageData[k2+1];
						merged_imageData[k+2]=imageData[k2+2];
					}
					else{
						merged_imageData[k]=B;
						merged_imageData[k+1]=G;
						merged_imageData[k+2]=R;
					}
				}
				else{
					merged_imageData[k]=B;
					merged_imageData[k+1]=G;
					merged_imageData[k+2]=R;
				}
			}
		}
	}
	
	/* 3. Output the merged image to disk using file name portrait.bmp or landscape.bmp for a portrait or a
		   landscape of the original image, respectively.
	*/
//	header.Size = header.Size - header.ImageSize + imageSize_merged;
	    header.Width=  width_merged;
		header.Height= height_merged;

		header.ImageSize= imageSize_merged;
	
	fwrite(&header.Type, 1, 2, fptr); 
	fwrite(&header.Size, sizeof(unsigned), 1, fptr); 
	fwrite(&header.Reserved, 1, 4, fptr); 
	fwrite(&header.OffsetBits, sizeof(unsigned), 1, fptr); 
	fwrite(&header.InfoSize, sizeof(unsigned), 1, fptr); 
	fwrite(&header.Width, sizeof(unsigned), 1, fptr); 
	fwrite(&header.Height, sizeof(unsigned), 1, fptr);  
	fwrite(&header.Planes, sizeof(unsigned short), 1, fptr); 
	fwrite(&header.BitPerPixel, sizeof(unsigned short), 1, fptr);  
	fwrite(&header.Compression, sizeof(unsigned), 1, fptr); 
	fwrite(&header.ImageSize, sizeof(unsigned long), 1, fptr); 
	fwrite(&header.XResolution, sizeof(unsigned), 1, fptr); 
	fwrite(&header.YResolution, sizeof(unsigned), 1, fptr);  
	fwrite(&header.Colors, sizeof(unsigned), 1, fptr); 
	fwrite(&header.ImportantColors, sizeof(unsigned), 1, fptr); 
	
	fwrite(palette, header.OffsetBits-14-header.InfoSize, 1, fptr);
	fwrite(merged_imageData, imageSize_merged, 1, fptr);
	
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
	return 0;
}
