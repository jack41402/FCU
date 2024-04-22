#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	char Type[2];
	unsigned Size;
	char Reserved[4];
	unsigned OffsetBits;
	unsigned InfoSize;
	unsigned Width;
	unsigned Height;
	unsigned short Planes;
	unsigned short BitPerPixel;  
	unsigned Compression;
	unsigned ImageSize;     
	unsigned XResolution;
	unsigned YResolution;  
	unsigned Colors;             
	unsigned ImportantColors;
}Header;

void print_header(Header header){ // Print the header of a file.
	printf("Type:             %c%c\n", header.Type[0], header.Type[1]);
	printf("Size:             %u\n", header.Size);
	printf("Reserved:         %c%c%c%c\n", header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3]);
	printf("OffsetBits:       %u\n", header.OffsetBits);
	printf("InfoSize:         %u\n", header.InfoSize);
	printf("Width:            %u\n", header.Width);
	printf("Height:           %u\n", header.Height);
	printf("Planes:           %u\n", header.Planes);
	printf("BitPerPixel:      %u\n", header.BitPerPixel);
	printf("Compression:      %u\n", header.Compression);
	printf("ImageSize:        %u\n", header.ImageSize);
	printf("XResolution:      %u\n", header.XResolution);
	printf("YResolution:      %u\n", header.YResolution);
	printf("Colors:           %u\n", header.Colors);
	printf("ImportantColors:  %u\n", header.ImportantColors);
}

void write_image(char *fname, Header header, unsigned char *palette, unsigned char *imageData){ // Write the image file.
	FILE *fptr;
	fptr = fopen(fname, "wb");
	fwrite(&header.Type, 1, 2, fptr);
	fwrite(&header.Size, 4, 1, fptr);
	fwrite(&header.Reserved, 1, 4, fptr);
	fwrite(&header.OffsetBits, 4, 1, fptr);
	fwrite(&header.InfoSize, 4, 1, fptr);
	fwrite(&header.Width, 4, 1, fptr);
	fwrite(&header.Height, 4, 1, fptr);
	fwrite(&header.Planes, 2, 1,fptr);
	fwrite(&header.BitPerPixel, 2, 1, fptr);
	fwrite(&header.Compression, 4, 1, fptr);
	fwrite(&header.ImageSize, 4, 1, fptr);
	fwrite(&header.XResolution, 4, 1, fptr);
	fwrite(&header.YResolution, 4, 1, fptr);
	fwrite(&header.Colors, 4, 1, fptr);
	fwrite(&header.ImportantColors, 4, 1, fptr);
	fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); // Write the palette.
	fwrite(imageData, 1, header.ImageSize, fptr); // Write the image pixel data.
	fclose(fptr);
}

int main(int argc, char *argv[]){
	FILE *fptr;
	Header header; // Bitmap file header of the input image.
	unsigned char *palette; // Pointer: input/output image palette.
	unsigned char *imageData;// Pointer: input/output image pixel data.
	unsigned char *reduced_imageData;// Pointer: reduced image pixel data.
	char file_name[40];
	int rowSize; // Number of bytes in a row of the input image. 
	int rowSize_reduced; // Number of bytes in a row of the reduced image.
	int fillings; // Number of bytes of padding 0's.
	int frameSize;
	unsigned char frameColor[3] = {255, 255, 255}; // Store the RGB value of the frame
	int i, j, k, l;
	int k_reduced, k_1, k_2, k_3, k_4;
	
	if(argc==1){
		printf("Please enter the image file name.\n");
    	system("pause");
    	return 1;
	}
	
	else if(argc>3){
		printf("Too many image file names entered.\n");
    	system("pause");
    	return 1;
	}
	
	fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); // Open the input file.
	if(fptr==NULL){ // Terminate the program if the inpput file does not exist. 
		printf("File %s does not exist.\n", argv[1]);
		return 1;
	}

 	// Input the colored image file.	
	fread(&header.Type, 1, 2, fptr);
	fread(&header.Size, 4, 1, fptr);
	fread(&header.Reserved, 1, 4, fptr);
	fread(&header.OffsetBits, 4, 1, fptr);
	fread(&header.InfoSize, 4, 1, fptr);
	fread(&header.Width, 4, 1, fptr);
	fread(&header.Height, 4, 1, fptr);
	fread(&header.Planes, 2, 1,fptr);
	fread(&header.BitPerPixel, 2, 1, fptr);
	fread(&header.Compression, 4, 1, fptr);
	fread(&header.ImageSize, 4, 1, fptr);
	fread(&header.XResolution, 4, 1, fptr);
	fread(&header.YResolution, 4, 1, fptr);
	fread(&header.Colors, 4, 1, fptr);
	fread(&header.ImportantColors, 4, 1, fptr);

	do{ // Input the size of a frame between 4 and 20
		printf("Enter the size of frame in pixel (between 4 and 20): ");
		scanf("%d", &frameSize);
	}while(frameSize<4 || frameSize>20);
	printf("\nEnter RGB value of the frame color: "); // Input the RGB value of the frame color.
	scanf("%hhu %hhu %hhu", &frameColor[0], &frameColor[1], &frameColor[2]);

	palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14); // Allocate memory space for the palette.
	fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr); // Read palette from the image file.
	imageData = (unsigned char *) malloc(header.ImageSize); // Allocate memory space for the image pixel data.
	fread(imageData, header.ImageSize, 1, fptr); // Read image pixel data from the image file.
	fclose(fptr);
	printf("\n>>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp"));
	print_header(header);// Print the header
	printf("******************************************************************\n\n");

	Header reduced_header = header;// Bitmap file header of the reduced image.
	reduced_header.Width = ceil((float) header.Width / 2.0); //Image width in pixel of the reduced image.
	reduced_header.Height = ceil((float) header.Height / 2.0); //Image height in pixel of the reduced image.
	reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; // Compute the image size of the reduced image.
	reduced_header.Size = header.Size - header.ImageSize + reduced_header.ImageSize; // Compute the file size in bytes.
	
	reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize); // Allocate memory space for image pixel data of the reduced image.
	fillings = (4 - (header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
	rowSize = header.Width * 3 + fillings; // Original image
	fillings = (4 - (reduced_header.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
	rowSize_reduced = reduced_header.Width * 3 + fillings; // Reduced image
	for (i = 0; i < reduced_header.Height; i++)
		for (j = 0; j < reduced_header.Width; j++){
			k = i * 2 * rowSize + j * 2 * 3; // Pixel index of the original input image.
			k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
			reduced_imageData[k_reduced] = imageData[k]; // Blue
			reduced_imageData[k_reduced+1] = imageData[k+1]; // Green
			reduced_imageData[k_reduced+2] = imageData[k+2]; // Red
		}
	printf(">>>> File header of the reduced image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp"));
	print_header(reduced_header);
	printf("******************************************************************\n\n");
	write_image(file_name, reduced_header, palette, reduced_imageData); 
	
	int newWidth = header.Width + 3 * frameSize; // The width of the merged image.
	int newHeight = header.Height + 3 * frameSize; // The height of the merged image.
	int newRowSize = (newWidth * 3 + 3) & ~3;
	int newImageSize = newRowSize * newHeight; // The image size of the merged image.
	Header merged_header = header;
	merged_header.Size = header.Size + newImageSize - header.ImageSize;
	merged_header.Width = newWidth;
	merged_header.Height = newHeight;
	merged_header.ImageSize = newImageSize;
	
	unsigned char *merged_imageData = (unsigned char *)malloc(newImageSize); // Allocate memory space for image pixel data of the merged image.
	for (i = 0; i < reduced_header.Height; i++) { // Peform the merge operation.
	    for (j = 0; j < reduced_header.Width; j++) { 
	        k_reduced = i * rowSize_reduced + j * 3; // Pixel index of the reduced image.
	        k_1 = (i + merged_header.Height / 2 + frameSize / 2) * newRowSize + (merged_header.Width - 1 - j - frameSize) * 3; // 1st quadrant
	        k_2 = (i + merged_header.Height / 2 + frameSize / 2)  * newRowSize + (j + frameSize) * 3; // 2rd quadrant. 
	        k_3 = (merged_header.Height / 2 - 1 - i - frameSize / 2) * newRowSize + (j + frameSize) * 3; // 3rd quadrant .
	        k_4 = (merged_header.Height / 2 - 1 - i - frameSize / 2) * newRowSize + (merged_header.Width - 1 - j - frameSize) * 3; // 4th quadrant. 
	        merged_imageData[k_1] = reduced_imageData[k_reduced]; // Copy the pixel in the 1st quadrant.
	        merged_imageData[k_1 + 1] = reduced_imageData[k_reduced + 1];
	        merged_imageData[k_1 + 2] = reduced_imageData[k_reduced + 2];
	        merged_imageData[k_2] = reduced_imageData[k_reduced]; // Copy the pixel in the 2nd quadrant.
	        merged_imageData[k_2 + 1] = reduced_imageData[k_reduced + 1];
	        merged_imageData[k_2 + 2] = reduced_imageData[k_reduced + 2];
	        merged_imageData[k_3] = reduced_imageData[k_reduced]; // Copy the pixel in the 3rd quadrant.
	        merged_imageData[k_3 + 1] = reduced_imageData[k_reduced + 1];
	        merged_imageData[k_3 + 2] = reduced_imageData[k_reduced + 2];
			merged_imageData[k_4] = reduced_imageData[k_reduced]; // Copy the pixel in the 4th quadrant.
	    	merged_imageData[k_4 + 1] = reduced_imageData[k_reduced + 1];
	        merged_imageData[k_4 + 2] = reduced_imageData[k_reduced + 2];
	    }
	}
	for (i = 0; i < newHeight; i++) { // Peform the frame operation.
	    for (j = 0; j < newWidth; j++) { 
	        int index = (i * newRowSize + j * 3); // Pixel index of the merged image.
	        if (i <= frameSize || i >= newHeight - frameSize || j <= frameSize || j >= newWidth - frameSize ||
	            (i >= newHeight / 2 - frameSize / 2 && i <= newHeight / 2 + frameSize / 2) ||
	            (j >= newWidth / 2 - frameSize / 2 && j <= newWidth / 2 + frameSize / 2)) { // When it comes to the frame
	            merged_imageData[index] = frameColor[2]; // Copy the blue level of the frame. 
	            merged_imageData[index + 1] = frameColor[1]; // Copy the green level of the frame. 
	            merged_imageData[index + 2] = frameColor[0]; // Copy the red level of the frame. 
	        }
	    }
	}
	printf(">>>> File header of the merged image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_frame_merged"), ".bmp"));
	print_header(merged_header);
	printf("******************************************************************\n\n");
	write_image(file_name, merged_header, palette, merged_imageData);
	
	free(palette);
	free(imageData);
	free(reduced_imageData);
	free(merged_imageData);
	
	system("pause"); 
	return 0;
}

