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

void setRGB(unsigned char* buffer, int rowsize, int x, int y, int r, int g, int b){
	buffer[x * rowsize + y * 3] = b;
	buffer[x * rowsize + y * 3 + 1] = g;
	buffer[x * rowsize + y * 3 + 2] = r;
}
int main() {
	char fileName[100];
	FILE *fptr; // File pointer 
	Header	header, merged_header; // Bitmap file header
	unsigned char	*palette; // Pointer: palette.
	unsigned char	*imageData; // Pointer: Image pixel data.
	unsigned long imageSize_merged; // Size of the merged image.
	unsigned width_merged; // Width of the merged image.
	unsigned height_merged; // Height of the merged image.
	unsigned char *merged_imageData;  // Image data of the merged image.
	unsigned frame_width = 15; // Frame width is 15 pixels.
	unsigned char frame_R = 20; // Frame color of R.
	unsigned char frame_G = 240; // Frame color of G.
	unsigned char frame_B = 240; // Frame color of B.
	int rowSize; // Number of bytes in a row. 
	int merged_rowSize; // Number of bytes in a row of the merged image. 
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
	fread(&header.Type, 1, 2, fptr);         // Two fixed characters, "BM" for bitmap images.
	fread(&header.Size, 4, 1, fptr);        // File size in bytes.
	fread(&header.Reserved, 1, 4, fptr);     // Reserved field.
	fread(&header.OffsetBits, 4, 1, fptr);  // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
	// Image information: 40 bytes.
	fread(&header.InfoSize, 4, 1, fptr);   // Information size in byte.
	fread(&header.Width, 4, 1, fptr);       // Image width in pixel.
	fread(&header.Height, 4, 1, fptr);     // Image height in pixel.
	fread(&header.Planes, 2, 1, fptr);       // Number of image planes in the image, must be 1.
	fread(&header.BitPerPixel, 2, 1, fptr);  // Number of bits used to represent the data for each pixel.
	fread(&header.Compression, 4, 1, fptr);       // Value indicating what type of compression, if any, is used, (0: uncompressed).
	fread(&header.ImageSize, 4, 1, fptr);          // Size of the actual pixel data, in bytes.
	fread(&header.XResolution, 4, 1, fptr);        // Preferred horizontal resolution of the image, in pixels per meter.
	fread(&header.YResolution, 4, 1, fptr);       // Preferred vertical resolution of the image, in pixels per meter.
	fread(&header.Colors, 4, 1, fptr);          // Value is zero except for indexed images using fewer than the maximum number of colors.
	fread(&header.ImportantColors, 4, 1, fptr);
  
	// Allocate memory space for color palette and read color palette. 
    palette = (unsigned char*) malloc(header.OffsetBits - header.InfoSize - 14);
    fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr); 
	// Allocate memory space for image data and read image data. 
	imageData = (unsigned char*) malloc(header.ImageSize);
	fread(imageData, header.ImageSize, 1, fptr);
	
	fclose(fptr); // Close the input file.
	
	if (header.Height>header.Width) orientation = 0; // Portrait orientation.
	else orientation = 1; // Landscape orientation.
	merged_header.Type[0] = 'B'; 
	merged_header.Type[1] = 'M';
	merged_header.Size =  header.Size;// Two fixed characters, "BM" for bitmap images.       // File size in bytes.
	for(i=0; i<4; i++){
		merged_header.Reserved[i] = header.Reserved[i];        // Reserved field.
	}
	merged_header.OffsetBits = header.OffsetBits;  // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
	// Image information: 40 bytes.
	merged_header.InfoSize = header.InfoSize;  // Information size in byte.    
	merged_header.Planes =  header.Planes;      // Number of image planes in the image, must be 1.
	merged_header.BitPerPixel = header.BitPerPixel; // Number of bits used to represent the data for each pixel.
	merged_header.Compression = header.Compression;       // Value indicating what type of compression, if any, is used, (0: uncompressed).
	merged_header.XResolution = header.XResolution;        // Preferred horizontal resolution of the image, in pixels per meter.
	merged_header.YResolution = header.YResolution;       // Preferred vertical resolution of the image, in pixels per meter.
	merged_header.Colors = header.Colors;          // Value is zero except for indexed images using fewer than the maximum number of colors.
	merged_header.ImportantColors = header.ImportantColors;
	
	/* 2. Depending whether the image is a portrait or a landscape, perform the following image processing:
          2.1. If the image is a portrait, perform transformation of mirror reflection along the vertical line 
		       on the center of the image and attach the transformed on the right-hand-side of the original 
			   image with a frame surrounding the merged image and a central vertical bar.
          2.2. If the image is a landscape, perform transformation of mirror reflection along the horizontal line 
		       on the center of the image and attach the transformed on the bottom of the original image with a 
			   frame surrounding the merged image with a central horizontal bar.*/
	if(orientation == 0){
		merged_header.Width = header.Width * 2 + 45;     
		merged_header.Height =  header.Height + 30;
		merged_header.ImageSize = merged_header.Width * merged_header.Height * 3;
		merged_imageData = (unsigned char *) malloc(merged_header.ImageSize);
		
		
		//image1 and 2
		int fillings;
		fillings = (4 - header.Width * 3 % 4) % 4;
		rowSize = header.Width * 3 + fillings;
		fillings = (4 - merged_header.Width * 3 % 4) % 4;
		merged_rowSize = merged_header.Width * 3 + fillings;
		for(i=0; i<header.Height; i++){
			for(j=0; j<header.Width; j++){
				k = i * rowSize + j * 3; 
				k1 = (i + 15) * merged_rowSize + (j + 15) * 3;
				k2 = (i + 15) * merged_rowSize + (merged_header.Width - j - 15 - 1) * 3;
				merged_imageData[k1] = imageData[k];
				merged_imageData[k1+1] = imageData[k+1];
				merged_imageData[k1+2] = imageData[k+2];
				merged_imageData[k2] = imageData[k];
				merged_imageData[k2+1] = imageData[k+1];
				merged_imageData[k2+2] = imageData[k+2];
			}
		}
//		//horizontal line
//		for(i=0; i<15; i++){
//			for(j=0; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		for(i=header.Height+15; i<header.Height+30; i++){
//			for(j=0; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		//verticle line
//		for(i=0; i<merged_header.Height; i++){
//			for(j=0; j<15; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		for(i=0; i<merged_header.Height; i++){
//			for(j=header.Width+15; j<header.Width+30; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		for(i=0; i<merged_header.Height; i++){
//			for(j=(header.Width+15)*2; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}

	
	}
	if(orientation == 1){
		merged_header.Width = header.Width + 30;     
		merged_header.Height =  header.Height * 2 + 45;
		merged_header.ImageSize = merged_header.Width * merged_header.Height * 3;
		merged_imageData = (unsigned char *) malloc(merged_header.ImageSize);
		
		//image1 and 2
		int fillings;
		fillings = (4 - header.Width * 3 % 4) % 4;
		rowSize = header.Width * 3 + fillings;
		fillings = (4 - merged_header.Width * 3 % 4) % 4;
		merged_rowSize = merged_header.Width * 3 + fillings;
		for(i=0; i<header.Height; i++){
			for(j=0; j<header.Width; j++){
				k= i * rowSize + j * 3;
				k1 = (i + header.Height + 30) * merged_rowSize + (j + 15) * 3;
				k2 = (header.Height - i + 15) * merged_rowSize + (j + 15) * 3;
				merged_imageData[k1] = imageData[k];
				merged_imageData[k1+1] = imageData[k+1];
				merged_imageData[k1+2] = imageData[k+2];
				merged_imageData[k2] = imageData[k];
				merged_imageData[k2+1] = imageData[k+1];
				merged_imageData[k2+2] = imageData[k+2];
			}
		}
//		//horizontal line
//		for(i=0; i<15; i++){
//			for(j=0; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		for(i=header.Height+15; i<header.Height+30; i++){
//			for(j=0; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		for(i=(header.Height+15)*2; i<merged_header.Height; i++){
//			for(j=0; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		//verticle line
//		for(i=0; i<merged_header.Height; i++){
//			for(j=0; j<15; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
//		for(i=0; i<merged_header.Height; i++){
//			for(j=header.Width+30; j<merged_header.Width; j++){
//				setRGB(merged_imageData, merged_rowSize, i, j, 20, 240, 240);
//			}
//		}
		
	}
			

	/* 3. Output the merged image to disk using file name portrait.bmp or landscape.bmp for a portrait or a
		   landscape of the original image, respectively.*/
		// Read file header and image information.
	if(orientation == 0){
		fptr = fopen(strcpy(fileName, "portrait.bmp"), "w");  	
	}
	if(orientation == 1){
		fptr = fopen(strcpy(fileName, "landscape.bmp"), "w");  
	}

	fwrite(&merged_header.Type, 1, 2, fptr);         // Two fixed characters, "BM" for bitmap images.
	fwrite(&merged_header.Size, 4, 1, fptr);        // File size in bytes.
	fwrite(&merged_header.Reserved, 1, 4, fptr);     // Reserved field.
	fwrite(&merged_header.OffsetBits, 4, 1, fptr);  // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
	// Image information: 40 bytes.
	fwrite(&merged_header.InfoSize, 4, 1, fptr);   // Information size in byte.
	fwrite(&merged_header.Width, 4, 1, fptr);       // Image width in pixel.
	fwrite(&merged_header.Height, 4, 1, fptr);     // Image height in pixel.
	fwrite(&merged_header.Planes, 2, 1, fptr);       // Number of image planes in the image, must be 1.
	fwrite(&merged_header.BitPerPixel, 2, 1, fptr);  // Number of bits used to represent the data for each pixel.
	fwrite(&merged_header.Compression, 4, 1, fptr);       // Value indicating what type of compression, if any, is used, (0: uncompressed).
	fwrite(&merged_header.ImageSize, 4, 1, fptr);          // Size of the actual pixel data, in bytes.
	fwrite(&merged_header.XResolution, 4, 1, fptr);        // Preferred horizontal resolution of the image, in pixels per meter.
	fwrite(&merged_header.YResolution, 4, 1, fptr);       // Preferred vertical resolution of the image, in pixels per meter.
	fwrite(&merged_header.Colors, 4, 1, fptr);          // Value is zero except for indexed images using fewer than the maximum number of colors.
	fwrite(&merged_header.ImportantColors, 4, 1, fptr);
    fwrite(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr); 
	fwrite(merged_imageData, merged_header.ImageSize, 1, fptr);
	
	fclose(fptr); // Close the output file.
 
	// 4. Print the file header and the image information of the merged image on the monitor.
	printf("\n>>>> File header and image information of the merged image: %s\n\n", fileName);
	printf("Type:             %c%c\n", merged_header.Type[0], header.Type[1]); // Two fixed characters, "BM".
	printf("Size:             %u\n", header.Size); // File size in bytes.
	printf("Resserved:        %c%c%c%c\n", merged_header.Reserved[0], merged_header.Reserved[1], 
                                           merged_header.Reserved[2], merged_header.Reserved[3]); // Reserved field.
	printf("OffsetBits:       %u\n", merged_header.OffsetBits); // Offset.
	printf("InfoSize:         %u\n", merged_header.InfoSize); // Information size in byte.
	printf("Width:            %u\n", merged_header.Width); // Image width in pixel.
	printf("Height:           %u\n", merged_header.Height); // Image height in byte.
	printf("Planes:           %d\n", merged_header.Planes); // Number of image planes in the image, must be 1.
	printf("BitPerPixel:      %d\n", merged_header.BitPerPixel); // Number of bits used to represent the data for each pixel.
	printf("Compression:      %u\n", merged_header.Compression); // Value indicating what type of compression.
	printf("ImageSize:        %u\n", merged_header.ImageSize); // Size of the actual pixel data, in bytes.
	// Preferred horizontal resolution of the image, in pixels per meter.
	printf("XResolution:      %u\n", merged_header.XResolution);
	// Preferred vertical resolution of the image, in pixels per meter.
	printf("YResolution:      %u\n", merged_header.YResolution);
	// Value is zero except for indexed images using fewer than the maximum number of colors.
	printf("Colors:           %u\n", merged_header.Colors);
	// Number of colors that are considered important when rendering the image.
	printf("ImportantColors:  %u\n", merged_header.ImportantColors);

	// Free memory space of color palette, image data of the original image and the extended image.
	free(palette);
	free(imageData);
	free(merged_imageData);
	return 0;
}
