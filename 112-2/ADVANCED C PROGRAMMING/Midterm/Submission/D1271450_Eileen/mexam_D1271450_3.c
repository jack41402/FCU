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
	Header pm_header;
	Header lm_header;
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
	int lm_rowSize; // Number of bytes in a row of the merged image. 
	int pm_rowSize;
	int orientation; // Orientation of the original image, 0: portrait, 1: landscape.
	int filling;
	int pm_filling;
	int lm_filling;
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
  fread(&header.Type,1,2,fptr);
  fread(&header.Size,1,2,fptr);
  fread(&header.Reserved,1,2,fptr);
  fread(&header.OffsetBits,1,2,fptr);
  fread(&header.InfoSize,1,2,fptr);
  fread(&header.Width,1,2,fptr);
  fread(&header.Height,1,2,fptr);
  fread(&header.Planes,1,2,fptr);
  fread(&header.BitPerPixel,1,2,fptr);
  fread(&header.Compression,1,2,fptr);
  fread(&header.ImageSize,1,2,fptr);
  fread(&header.XResolution,1,2,fptr);
  fread(&header.YResolution,1,2,fptr);
  fread(&header.Colors,1,2,fptr);
  fread(&header.ImportantColors,1,2,fptr);
  palette=(unsigned char*)malloc(sizeof(header.OffsetBits-header.InfoSize-14));
  fread(&palette,header.OffsetBits-header.InfoSize-14,1,fptr);
  imageData=(unsigned char*)malloc(sizeof(header.ImageSize));
  fread(&imageData,header.ImageSize,1,fptr);
	// Read file header and image information.  
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
  
	// Allocate memory space for color palette and read color palette. 
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  

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
	
	fclose(fptr); // Close the input file.
	filling=((header.Width*3)%4)*4;
    rowsize=header.Width*3+rowsize;
	
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
	if(orientation==0){
		lm_header.Type=header.Type;
        lm_header.Size=lm_header.Width*lm_header.Height;
        lm_header.Reserved=header.Reserved;
        lm_header.OffsetBits=header.OffsetBits;
        lm_header.InfoSize=header.InfoSize;
        lm_header.Width=header.Width*2+30;
        lm_header.Height=header.Height*2+45;
        lm_header.Planes=header.Planes;
        lm_header.BitPerPixel=header.BitPerPixel;
        lm_header.Compression=header.Compression;
        lm_header.ImageSize=header.ImageSize*2;
        lm_header.XResolution=header.XResolution;
        lm_header.YResolution=header.YResolution;
        lm_header.Colors=header.Colors;
        lm_header.ImportantColors=header.ImportantColors;
        lm_filling=((lm_header.Width*3)%4)*4;
        lm_rowsize=lm_header.Width*3+rowsize;
        for(i=0;i<lm_header.height;++i){
        	for(j=0;j<lm_header.Width;++j){
        		lm_rowsize=header.Width*3+filling;
        		lm_up=((lm_header.Height/2+15/2)*lm_rowsize,(lm_header.Width+15)*3);
        		lm_low=((lm_header.Height/2-15/2)*lm_rowsize,(lm_header.Width+15)*3);
        		lm_up[k]=header[k]
        		lm_up[k+1]=header[k+1]
        		lm_up[k+2]=header[k+2]
        		lm_low[k]=header[k]
        		lm_low[k+1]=header[k+1]
        		lm_low[k+2]=header[k+2]
        		
        		if(i<15&&i>=lm_Height-15&&i<=lm_Height/2+15/2||i>=lm_Height/2-15/2&&j<15&&j>=lm_Width-15){
        			lm.header[k]=B
        			lm.header[k+1]=G
        			lm.header[k+2]=R
				}
			}
		}
	printf("\n>>>> File header and image information of the merged image: %s\n\n", fileName);
	printf("Type:             %c%c\n", lm_header.Type[0], lm_header_Type[1]); // Two fixed characters, "BM".
	printf("Size:             %u\n", lm_header_Size); // File size in bytes.
	printf("Resserved:        %c%c%c%c\n", lm_header_Reserved[0], lm_header.Reserved[1], 
                                           lm_header_Reserved[2], lm_header.Reserved[3]); // Reserved field.
	printf("OffsetBits:       %u\n", lm_header.OffsetBits); // Offset.
	printf("InfoSize:         %u\n", lm_header.InfoSize); // Information size in byte.
	printf("Width:            %u\n", lm_header.Width); // Image width in pixel.
	printf("Height:           %u\n", lm_header.Height); // Image height in byte.
	printf("Planes:           %d\n", lm_header.Planes); // Number of image planes in the image, must be 1.
	printf("BitPerPixel:      %d\n", lm_header.BitPerPixel); // Number of bits used to represent the data for each pixel.
	printf("Compression:      %u\n", lm_header.Compression); // Value indicating what type of compression.
	printf("ImageSize:        %u\n", lm_header.ImageSize); // Size of the actual pixel data, in bytes.
	// Preferred horizontal resolution of the image, in pixels per meter.
	printf("XResolution:      %u\n", lm_header.XResolution);
	// Preferred vertical resolution of the image, in pixels per meter.
	printf("YResolution:      %u\n", lm_header.YResolution);
	// Value is zero except for indexed images using fewer than the maximum number of colors.
	printf("Colors:           %u\n", lm_header.Colors);
	// Number of colors that are considered important when rendering the image.
	printf("ImportantColors:  %u\n", lm_header.ImportantColors);
	
			fptr=fopen(Filename,"wb");
  fwrite(&lm_header.Type,1,2,fptr);
  fwrite(&lm_header.Size,1,2,fptr);
  fwrite(&lm_header.Reserved,1,2,fptr);
  fwrite(&lm_header.OffsetBits,1,2,fptr);
  fwrite(&lm_header.InfoSize,1,2,fptr);
  fwrite(&lm_header.Width,1,2,fptr);
  fwrite(&lm_header.Height,1,2,fptr);
  fwrite(&lm_header.Planes,1,2,fptr);
  fwrite(&lm_header.BitPerPixel,1,2,fptr);
  fwrite(&lm_header.Compression,1,2,fptr);
  fwrite(&lm_header.ImageSize,1,2,fptr);
  fwrite(&lm_header.XResolution,1,2,fptr);
  fwrite(&lm_header.YResolution,1,2,fptr);
  fwrite(&lm_header.Colors,1,2,fptr);
  fwrite(&lm_header.ImportantColors,1,2,fptr);
  lm_palette=(unsigned char*)malloc(sizeof(lm_header.OffsetBits-lm_header.InfoSize-14));
  fwrite(&palette,1,pm_header.OffsetBits-pm_header.InfoSize-14,fptr);
  lm_imageData=(unsigned char*)malloc(sizeof(lm_header.ImageSize));
  fread(&imageData,1,header.ImageSize,fptr);
	}
	else{
		pm_header.Type=header.Type;
        pm_header.Size=pm_header.Width*pm_header.Height;
        pm_header.Reserved=header.Reserved;
        pm_header.OffsetBits=header.OffsetBits;
        pm_header.InfoSize=header.InfoSize;
        pm_header.Width=header.Width*2+45;
        pm_header.Height=header.Height*2+30;
        pm_header.Planes=header.Planes;
        pm_header.BitPerPixel=header.BitPerPixel;
        pm_header.Compression=header.Compression;
        pm_header.ImageSize=header.ImageSize*2;
        pm_header.XResolution=header.XResolution;
        pm_header.YResolution=header.YResolution;
        pm_header.Colors=header.Colors;
        pm_header.ImportantColors=header.ImportantColors;
        pm_filling=((pm_header.Width*3)%4)*4;
        pm_rowsize=pm_header.Width*3+rowsize;
        
        pm_filling=((pm_header.Width*3)%4)*4;
        pm_rowsize=pm_header.Width*3+rowsize;
        for(i=0;i<pm_header.height;++i){
        	for(j=0;j<pm_header.Width;++j){
        		pm_rowsize=header.Width*3+filling;
        		pm_right=((pm_header.Height+15)*pm_rowsize,(pm_header.Width-15)*3);
        		pm_left=((pm_header.Height+15)*pm_rowsize,(pm_header.Width+15)*3);
        		pm_right[k]=header[k]
        		pm_right[k+1]=header[k+1]
        		pm_right[k+2]=header[k+2]
        		pm_left[k]=header[k]
        		pm_left[k+1]=header[k+1]
        		pm_left[k+2]=header[k+2]
        		
        		if(i<15&&i>=pm_Height-15&&j<15&&j>=pm_Width-15&&j<=pm_Width/2+15/2||j>=pm_Width/2-15/2){
        			pm.header[k]=B
        			pm.header[k+1]=G
        			pm.header[k+2]=R
				}
			}
		}
	printf("\n>>>> File header and image information of the merged image: %s\n\n", fileName);
	printf("Type:             %c%c\n", pm_header.Type[0], pm_header.Type[1]); // Two fixed characters, "BM".
	printf("Size:             %u\n", header.Size); // File size in bytes.
	printf("Resserved:        %c%c%c%c\n", pm_header.Reserved[0], pm_header.Reserved[1], 
                                           pm_header.Reserved[2], pm_header.Reserved[3]); // Reserved field.
	printf("OffsetBits:       %u\n", pm_header.OffsetBits); // Offset.
	printf("InfoSize:         %u\n", pm_header.InfoSize); // Information size in byte.
	printf("Width:            %u\n", pm_header.Width); // Image width in pixel.
	printf("Height:           %u\n", pm_header.Height); // Image height in byte.
	printf("Planes:           %d\n", pm_header.Planes); // Number of image planes in the image, must be 1.
	printf("BitPerPixel:      %d\n", pm_header.BitPerPixel); // Number of bits used to represent the data for each pixel.
	printf("Compression:      %u\n", pm_header.Compression); // Value indicating what type of compression.
	printf("ImageSize:        %u\n", pm_header.ImageSize); // Size of the actual pixel data, in bytes.
	// Preferred horizontal resolution of the image, in pixels per meter.
	printf("XResolution:      %u\n", pm_header.XResolution);
	// Preferred vertical resolution of the image, in pixels per meter.
	printf("YResolution:      %u\n", pm_header.YResolution);
	// Value is zero except for indexed images using fewer than the maximum number of colors.
	printf("Colors:           %u\n", pm_header.Colors);
	// Number of colors that are considered important when rendering the image.
	printf("ImportantColors:  %u\n", pm_header.ImportantColors);
	
		fptr=fopen(Filename,"wb");
  fwrite(&pm_header.Type,1,2,fptr);
  fwrite(&pm_header.Size,1,2,fptr);
  fwrite(&pm_header.Reserved,1,2,fptr);
  fwrite(&pm_header.OffsetBits,1,2,fptr);
  fwrite(&pm_header.InfoSize,1,2,fptr);
  fwrite(&pm_header.Width,1,2,fptr);
  fwrite(&pm_header.Height,1,2,fptr);
  fwrite(&pm_header.Planes,1,2,fptr);
  fwrite(&pm_header.BitPerPixel,1,2,fptr);
  fwrite(&pm_header.Compression,1,2,fptr);
  fwrite(&pm_header.ImageSize,1,2,fptr);
  fwrite(&pm_header.XResolution,1,2,fptr);
  fwrite(&pm_header.YResolution,1,2,fptr);
  fwrite(&pm_header.Colors,1,2,fptr);
  fwrite(&pm_header.ImportantColors,1,2,fptr);
  pm_palette=(unsigned char*)malloc(sizeof(pm_header.OffsetBits-pm_header.InfoSize-14));
  fwrite(&palette,1,pm_header.OffsetBits-pm_header.InfoSize-14,fptr);
  pm_imageData=(unsigned char*)malloc(sizeof(pm_header.ImageSize));
  fread(&imageData,1,header.ImageSize,fptr);
	}

	/*****  Complete this code segment.  *****/
	/*****************************************/  
	
	/* 3. Output the merged image to disk using file name portrait.bmp or landscape.bmp for a portrait or a
		   landscape of the original image, respectively.
	*/
	/*****************************************/
	/*****  Complete this code segment.  *****/
	/*****************************************/  
	
	fclose(fptr); // Close the output file.
 
	// 4. Print the file header and the image information of the merged image on the monitor.
	

	// Free memory space of color palette, image data of the original image and the extended image.
	/*****************************************/
	free(palette);
	free(imagesize);
	free(lm_palette);
	free(lm_imagesize);
	free(pm_palette);
	free(pm_imagesize);
	/*****  Complete this code segment.  *****/
	/*****************************************/
	return 0;
}
