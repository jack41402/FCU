#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
  	//File header: 14 bytes.
  	char Type[2];         //Two fixed characters, "BM" for bitmap images.
  	unsigned Size;        //File size in bytes.
	char Reserved[4];     //Reserved field.
  	unsigned OffsetBits;  //Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
  	//Image information: 40 bytes.
  	unsigned InfoSize;    //Information size in byte.
  	unsigned Width;       //Image width in pixel.
  	unsigned Height;      //Image height in pixel.
  	unsigned short Planes;       //Number of image planes in the image, must be 1.
  	unsigned short BitPerPixel;  //Number of bits used to represent the data for each pixel.
  	unsigned Compression;        //Value indicating what type of compression, if any, is used, (0: uncompressed).
  	unsigned ImageSize;          //Size of the actual pixel data, in bytes.
  	unsigned XResolution;        //Preferred horizontal resolution of the image, in pixels per meter.
  	unsigned YResolution;        //Preferred vertical resolution of the image, in pixels per meter.
  	unsigned Colors;             //Value is zero except for indexed images using fewer than the maximum number of colors.
  	unsigned ImportantColors;    //Number of colors that are considered important when rendering the image.
} Header;

//Print the image file head.
void print_header(Header header) 
{
  
  	printf("Type:             %c%c\n", header.Type[0], header.Type[1]); //Two fixed characters, "BM".
  	printf("Size:             %u\n", header.Size); //File size in bytes.
  	// Reserved field
  	printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3]); 
	printf("OffsetBits:       %u\n", header.OffsetBits); //Offset.
  	printf("InfoSize:         %u\n", header.InfoSize); //Information size in byte.
  	printf("Width:            %u\n", header.Width); //Image width in pixel.
  	printf("Height:           %u\n", header.Height); //Image height in pixel.
  	printf("Planes:           %d\n", header.Planes); //Number of image planes in the image, must be 1.
  	printf("BitPerPixel:      %d\n", header.BitPerPixel); //Number of bits used to represent the data for each pixel.
  	printf("Compression:      %u\n", header.Compression); //Value indicating what type of compression.
  	printf("ImageSize:        %u\n", header.ImageSize); //Size of the actual pixel data, in bytes.
  	printf("XResolution:      %u\n", header.XResolution); //Preferred horizontal resolution of the image, in pixels per meter.
  	printf("YResolution:      %u\n", header.YResolution); //Preferred vertical resolution of the image, in pixels per meter.
  	printf("Colors:           %u\n", header.Colors); //Value is zero except for indexed images using fewer than the maximum number of colors.
  	printf("ImportantColors:  %u\n", header.ImportantColors); //Number of colors that are considered important when rendering the image.
}

//Write the image file.
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) 
{
  	FILE *fptr; //File pointer. 
  	fptr = fopen(fname, "wb"); //Open the output file using binary mode.
  	//Output the vertical mirror reflection image file. 
  	fwrite(&header.Type, 1, 2, fptr); //Two fixed characters, "BM".
  	fwrite(&header.Size, 4, 1, fptr); //File size in bytes.
  	fwrite(&header.Reserved, 1, 4, fptr); //Reserved field.
  	fwrite(&header.OffsetBits, 4, 1, fptr); //Offset.
  	fwrite(&header.InfoSize, 4, 1, fptr); //Information size in byte.
  	fwrite(&header.Width, 4, 1, fptr); //Image width in pixel.
  	fwrite(&header.Height, 4, 1, fptr); //Image height in pixel.
  	fwrite(&header.Planes, 2, 1, fptr); //Number of image planes in the image, must be 1.
  	fwrite(&header.BitPerPixel, 2, 1, fptr); //Number of bits used to represent the data for each pixel.
  	fwrite(&header.Compression, 4, 1, fptr); //Value indicating what type of compression.
  	fwrite(&header.ImageSize, 4, 1, fptr); //Size of the actual pixel data, in bytes.
  	fwrite(&header.XResolution, 4, 1, fptr); //Preferred horizontal resolution of the image, in pixels per meter.
  	fwrite(&header.YResolution, 4, 1, fptr); //Preferred vertical resolution of the image, in pixels per meter.
  	fwrite(&header.Colors, 4, 1, fptr); //Value is zero except for indexed images using fewer than the maximum number of colors.
  	fwrite(&header.ImportantColors, 4, 1, fptr); //Number of colors that are considered important when rendering the image.
  	fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); //Write the palette.
  	fwrite(imageData, 1, header.ImageSize, fptr); //Write the image pixel data.
  	fclose(fptr); //Close the output file.
}

int main(int argc, char *argv[]) 
{
  	FILE *fptr; //File pointer 
  	Header io_header; //Bitmap file header of the input/output (original/merged) image.
  	Header merged_header;
  	unsigned char	*io_palette; //Pointer: input/output image palette.
  	unsigned char	*io_imageData; //Pointer: input/output image pixel data.
  	Header reduced_header; //Bitmap file header of the reduced image.
  	//The reduced image will use the same palette of input/output image.
  	unsigned char	*reduced_imageData; //Pointer: reduced image pixel data.
  	unsigned char *merged_imageData; //Pointer: merged image pixel data.
  	char file_name[40]; // Declaration of a character array to store the file name.
  	int rowSize; //Number of bytes in a row of the input image. 
  	int rowSize_reduced; //Number of bytes in a row of the reduced image.
  	int rowSize_merged; //Number of bytes in a row of the merged image.
  	int fillings; //Number of bytes of padding 0's.
  	int merged;  //Result of merging operation or to indicate whether merging was successful.
  	int i, j; //Loop variable.
  	int k; //Index of the pixel in the orignal image.
  	int k_reduced; //Index of the pixel in the reduced image.
  	int k_merged; //Index of the pixel in the merged image.
  	int k_1, k_2, k_3, k_4; //k_i is the index of the pixel in the i-th quadrant of the merged image.
  	int frameSize; //Thickness of the code.
  	int frameColorR, frameColorG, frameColorB; //RGB color value.
  	
  	printf("Enter the size of frame in pixels (between 4 and 20): \n"); //Enter the size of the frame.
    scanf("%d", &frameSize);
    
  	printf("Enter RGB value of the frame color: \n"); //Enter the RGB color value.
    scanf("%d %d %d", &frameColorR, &frameColorG, &frameColorB);
  	
  	if (argc==1) //One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
	{ 
    	printf("Please enter an image file name without .bmp extension.\n");
    	return 1;
  	}
  	else if (argc>2) //If the command has more than three strings, too many arguments are entered.
	{ 
    	printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    	return 1;
  	}

  	fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); //Open the input file using binary mode.
  	if (fptr==NULL) //If the file pointer is empty, it means the file does not exist.
	{ 
    	printf("File %s does not exist.\n", strcat(argv[1], ".bmp")); //Print error message.
    	return 1; //Terminate the program.
  	}	  

 	//Input the colored image file.
  	fread(&io_header.Type, 1, 2, fptr); //Two fixed characters, "BM".
  	fread(&io_header.Size, 4, 1, fptr); //File size in bytes.
  	fread(&io_header.Reserved, 1, 4, fptr); //Reserved field.
  	fread(&io_header.OffsetBits, 4, 1, fptr); //Offset.
  	fread(&io_header.InfoSize, 4, 1, fptr); //Information size in byte.
  	fread(&io_header.Width, 4, 1, fptr); //Image width in pixel.
  	fread(&io_header.Height, 4, 1, fptr); //Image height in pixel.
  	fread(&io_header.Planes, 2, 1, fptr); //Number of image planes in the image, must be 1.
  	fread(&io_header.BitPerPixel, 2, 1, fptr); //Number of bits used to represent the data for each pixel.
  	fread(&io_header.Compression, 4, 1, fptr); //Value indicating what type of compression.
  	fread(&io_header.ImageSize, 4, 1, fptr); //Size of the actual pixel data, in bytes.
  	fread(&io_header.XResolution, 4, 1, fptr); //Preferred horizontal resolution of the image, in pixels per meter.
  	fread(&io_header.YResolution, 4, 1, fptr); //Preferred vertical resolution of the image, in pixels per meter.
  	fread(&io_header.Colors, 4, 1, fptr); //Value is zero except for indexed images using fewer than the maximum number of colors.
  	fread(&io_header.ImportantColors, 4, 1, fptr); //Number of colors that are considered important when rendering the image.

  	io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14); //Allocate memory space for the palette.
  	fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);  // Read palette from the image file.

  	io_imageData = (unsigned char *) malloc(io_header.ImageSize); //Allocate memory space for image pixel data.
  	fread(io_imageData, io_header.ImageSize, 1, fptr); //Read image pixel data from the image file.
	
  	fclose(fptr); //Close the input file.
   
  	//Print the input image file head.
  	printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); //Print the file header message.
  	print_header(io_header);
  	printf("******************************************************************\n\n"); //Print a separate line.
  
  	//Create file head of the quaterly reduced image.
  	//Copy the fields of the input image header.
  	//Two fixed characters, "BM".
  	reduced_header.Type[0] = 'B'; 
  	reduced_header.Type[1] = 'M';
  	reduced_header.Size = io_header.Size; //File size in bytes.
  	for(i = 0; i < 4; i++) //Reserved field, four characters.
    reduced_header.Reserved[i] = io_header.Reserved[i];
  	reduced_header.OffsetBits = io_header.OffsetBits; // Offset.
  	reduced_header.InfoSize = io_header.InfoSize; //Information size in byte.
  	reduced_header.Width = ceil((float) io_header.Width / 2.0); //Image width in pixel.
  	reduced_header.Height = ceil((float) io_header.Height / 2.0); //Image height in pixel.
  	reduced_header.Planes = io_header.Planes; //Number of image planes in the image, must be 1.
  	reduced_header.BitPerPixel = io_header.BitPerPixel; //Number of bits used to represent the data for each pixel.
  	reduced_header.Compression = io_header.Compression; //Value indicating what type of compression.
  	reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height;//Size of the actual pixel data, in bytes.
  	reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;//Compute the file size in bytes.
  	reduced_header.XResolution = io_header.XResolution; //Preferred horizontal resolution of the image, in pixels per meter.
  	reduced_header.YResolution = io_header.YResolution; //Preferred vertical resolution of the image, in pixels per meter.
  	reduced_header.Colors = io_header.Colors; //Value is zero except for indexed images using fewer than the maximum number of colors.
  	reduced_header.ImportantColors = io_header.ImportantColors; // Number of colors that are considered important when rendering the image.
  
  	//Allocate memory space for image pixel data of the reduced image.
  	reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  	
  	merged_header.Type[0] = 'B'; //Two fixed characters, "BM".
  	merged_header.Type[1] = 'M';
  	merged_header.Size = io_header.Size; //File size in bytes.
  	for (i = 0; i < 4; i++) //Reserved field, four characters.
    merged_header.Reserved[i] = io_header.Reserved[i];
  	merged_header.OffsetBits = io_header.OffsetBits; //Offset.
  	merged_header.InfoSize = io_header.InfoSize; //Information size in byte.
  	merged_header.Width =  reduced_header.Width * 2 + 3 * frameSize;//Image width in pixel.
  	merged_header.Height = reduced_header.Height * 2 + 3 * frameSize; //Image height in pixel.
  	merged_header.Planes = io_header.Planes; //Number of image planes in the image, must be 1.
  	merged_header.BitPerPixel = io_header.BitPerPixel; //Number of bits used to represent the data for each pixel.
  	merged_header.Compression = io_header.Compression; //Value indicating what type of compression.
  	merged_header.ImageSize = ceil((float) merged_header.Width * 3.0 / 4.0) * 4 * merged_header.Height; 
  	merged_header.Size = io_header.Size - io_header.ImageSize + merged_header.ImageSize;//Compute the file size in bytes.
  	merged_header.XResolution = io_header.XResolution; //Preferred horizontal resolution of the image, in pixels per meter.
  	merged_header.YResolution = io_header.YResolution; //Preferred vertical resolution of the image, in pixels per meter.
  	merged_header.Colors = io_header.Colors; //Value is zero except for indexed images using fewer than the maximum number of colors.
  	merged_header.ImportantColors = io_header.ImportantColors; //Number of colors that are considered important when rendering the image.
  	merged_imageData = (unsigned char *) malloc(merged_header.ImageSize);//Allocate memory space for image pixel data of the merged image.
  	
  	
  	
  
 	//Perform image reduction.// Copy even rows and enen columns of the original input image data to the reduced image.
  	//Compute the row size of the original image.
  	fillings = (4 - (io_header.Width * 3) % 4) % 4; //The number of filling bytes at the end of a row.
  	rowSize = io_header.Width * 3 + fillings; //The number of bytes in a row of the original image.
  
  	//Compute the row size of the reduced image.
  	fillings = (4 - (reduced_header.Width * 3) % 4) % 4; //The number of filling bytes at the end of a row.
  	rowSize_reduced = reduced_header.Width * 3 + fillings; //The number of bytes in a row of the reduced image.
  	
  	fillings = (4 - (merged_header.Width * 3) % 4) % 4; //The number of filling bytes at the end of a row.
  	rowSize_merged = merged_header.Width * 3 + fillings; //The number of bytes in a row of the merged image.
  	
  	//Copy even rows and enen columns of the original input image data to the reduced image.
  	for (i = 0; i < reduced_header.Height; i++) //Go through all rows of the reduced image.
  	{
  		for (j = 0; j < reduced_header.Width; j++) //Go through all pixels in each of the reduced image.
		{ 	
      		k = i * 2 * rowSize + j * 2 * 3; // Pixel index of the original input image.
      		k_reduced = i * rowSize_reduced + j * 3; //Pixel index of the reduced image.
      		reduced_imageData[k_reduced] = io_imageData[k]; //Copy blue level.
      		reduced_imageData[k_reduced + 1] = io_imageData[k + 1]; //Copy green level.
      		reduced_imageData[k_reduced + 2] = io_imageData[k + 2]; //Copy red level
    	}
	}
    
  	//Print the reduced image file head.
  	//Print the file header message.
  	printf(">>>> File header of the reduced image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); 
  	print_header(reduced_header);
  	printf("******************************************************************\n\n"); //Print a separate line.
  
  	//Write image to file "AAA_reduced.bmp"
  	//The file name is reused and the palette is the same as the original image.
  	write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  
  	//Peform the merge operation.
  	//Reuse rowSize and rowSize_reduced computed earlier.
  	for(i = 0; i < reduced_header.Height; i++) //Go through all rows of the reduced image.
	{ 
    	for(j = 0; j < reduced_header.Width; j++) //Go through all pixels in each row of the reduced image.
		{ 
	       	//Pixel index of the reduced image.
	      	k_reduced = i * rowSize_reduced + j * 3;
	      	//Computer pixel index of the merged image.
	      	//Note that row 0 is the bottom row and column 0 is the left-most column.
	      	
	      	//1st quadrant.
	      	k_1 = (i + merged_header.Height / 2 + frameSize / 2) * rowSize_merged + (merged_header.Width - 1 - j - frameSize) * 3; 
	      	//2nd quadrant. 
	      	k_2 = (i + merged_header.Height / 2 + frameSize / 2) * rowSize_merged + (j + frameSize) * 3; 
	      	//3rd quadrant.
	      	k_3 = (merged_header.Height / 2 - 1 - i - frameSize / 2) * rowSize_merged + (j + frameSize) * 3;
	      	//4th quadrant.
	      	k_4 = (merged_header.Height / 2 - 1 - i - frameSize / 2) * rowSize_merged + (merged_header.Width - 1 - j - frameSize) * 3;
			
			//Copy the pixel in the 1st quadrant.
		  	merged_imageData[k_1] = reduced_imageData[k_reduced];
		  	merged_imageData[k_1 + 1] = reduced_imageData[k_reduced + 1];
		  	merged_imageData[k_1 + 2] = reduced_imageData[k_reduced + 2];
		  	//Copy the pixel in the 2nd quadrant.
		  	merged_imageData[k_2] = reduced_imageData[k_reduced];
		  	merged_imageData[k_2 + 1] = reduced_imageData[k_reduced + 1];
		  	merged_imageData[k_2 + 2] = reduced_imageData[k_reduced + 2];
		  	//Copy the pixel in the 3rd quadrant.
		  	merged_imageData[k_3] = reduced_imageData[k_reduced]; 
		  	merged_imageData[k_3 + 1] = reduced_imageData[k_reduced + 1];
		  	merged_imageData[k_3 + 2] = reduced_imageData[k_reduced + 2];
		  	//Copy the pixel in the 4th quadrant.
		  	merged_imageData[k_4] = reduced_imageData[k_reduced]; 
		  	merged_imageData[k_4 + 1] = reduced_imageData[k_reduced + 1];
		  	merged_imageData[k_4 + 2] = reduced_imageData[k_reduced + 2];
    	}
  	}
  	
  	
  	for (i = 0; i < merged_header.Height; i++)//Go through all rows of the merged image.
	{
	    for (j = 0; j < merged_header.Width; j++)//Go through all pixels in each row of the merged image.
		{
			k = i * rowSize_merged + j * 3;
	        //Outer frame
	        if (i < frameSize || i >= merged_header.Height - frameSize || j < frameSize || j >= merged_header.Width - frameSize) 
			{
	            merged_imageData[k] = frameColorB;
	            merged_imageData[k + 1] = frameColorG;
	            merged_imageData[k + 2] = frameColorR;
	        }
	        //Horizontal central line
	        if (i >= merged_header.Height / 2 - frameSize / 2 && i <= merged_header.Height / 2 + frameSize / 2) 
			{
	            merged_imageData[k] = frameColorB;
	            merged_imageData[k + 1] = frameColorG;
	            merged_imageData[k + 2] = frameColorR;
	        }
	        //Vertical central line
	        if (j >= merged_header.Width / 2 - frameSize / 2 && j <= merged_header.Width / 2 + frameSize / 2) 
			{
	           	merged_imageData[k] = frameColorB;
	            merged_imageData[k + 1] = frameColorG;
	            merged_imageData[k + 2] = frameColorR;
	        }
	    }
	}
  	
  	//Print the merged image file head.
  	//Print the file header message.
  	printf(">>>> File header of the merged image, %s:\n\n", strcat(strcat(strcpy(file_name, argv[1]), "_frame_merged"), ".bmp")); 
  	print_header(merged_header);
  	printf("******************************************************************\n\n"); //Print a separate line.
  
  	//Write image to file.
  	//The merged file reuse the header, palette, image_Data of the input image.
  	write_image_file(file_name, merged_header, io_palette, merged_imageData);

  	free(io_palette); //Release memory space of palette of the input image.
  	free(io_imageData); //Release memory space of image pixel data of the input image.
  	free(merged_imageData); //Release memory space of image pixel data of the merged image.
  	free(reduced_imageData); //Release memory space of image pixel data of the reduced image.
  
  	system("pause");
  	return 0; 
}
