#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
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
} Header;

void print_header(Header header){
    printf("Type:             %c%c\n", header.Type[0], header.Type[1]);
    printf("Size:             %u\n", header.Size);
    printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3]);
    printf("OffsetBits:       %u\n", header.OffsetBits);
    printf("InfoSize:         %u\n", header.InfoSize);
    printf("Width:            %u\n", header.Width);
    printf("Height:           %u\n", header.Height);
    printf("Planes:           %d\n", header.Planes);
    printf("BitPerPixel:      %d\n", header.BitPerPixel);
    printf("Compression:      %u\n", header.Compression);
    printf("ImageSize:        %u\n", header.ImageSize);
    printf("XResolution:      %u\n", header.XResolution);
    printf("YResolution:      %u\n", header.YResolution);
    printf("Colors:           %u\n", header.Colors);
    printf("ImportantColors:  %u\n", header.ImportantColors);
}
  
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
 	FILE *fptr;  
 	fptr = fopen(fname, "wb"); 
 	fwrite(&header.Type, 1, 2, fptr); 
 	fwrite(&header.Size, 4, 1, fptr); 
 	fwrite(&header.Reserved, 1, 4, fptr); 
 	fwrite(&header.OffsetBits, 4, 1, fptr); 
 	fwrite(&header.InfoSize, 4, 1, fptr); 
 	fwrite(&header.Width, 4, 1, fptr); 
 	fwrite(&header.Height, 4, 1, fptr); 
 	fwrite(&header.Planes, 2, 1, fptr); 
 	fwrite(&header.BitPerPixel, 2, 1, fptr); 
 	fwrite(&header.Compression, 4, 1, fptr); 
 	fwrite(&header.ImageSize, 4, 1, fptr); 
 	fwrite(&header.XResolution, 4, 1, fptr); 
  	fwrite(&header.YResolution, 4, 1, fptr); 
  	fwrite(&header.Colors, 4, 1, fptr); 
  	fwrite(&header.ImportantColors, 4, 1, fptr); 
  	fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); 
  	fwrite(imageData, 1, header.ImageSize, fptr);
  	fclose(fptr); 
}

int main(int argc, char *argv[]) {
  	FILE *fptr; 
  	Header io_header; 
  	Header frame_header; 
  	unsigned char	*io_palette; 
  	unsigned char	*io_imageData; 
  	Header reduced_header; 
  	unsigned char	*reduced_imageData , *frame_imageData; 
  	char file_name[40];
  	int rowSize; 
  	int rowSize_reduced; 
  	int rowSize_frame; 
  	int fillings; 
  	int i, j; 
  	int k; 
  	int k_reduced; 
  	int k_1, k_2, k_3, k_4; 
  	int framewidth; 
  	int rgb1, rgb2, rgb3; 
  	do{
  		printf("Input the size (width) of a frame between 4 and 20: ");
  		scanf("%d",&framewidth);
  	} while(framewidth<4 || framewidth>20);
  	printf("\nEnter RGB value of the frame color: ");
  	scanf("%d %d %d",&rgb1,&rgb2,&rgb3);
  	if (argc==1) { 
    	printf("Please enter an image file name without .bmp extension.\n");
    return 1;
  }
  	else if (argc>2) { 
    	printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    return 1;
  }
  	fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb"); 
  	if (fptr==NULL) { 
    	printf("File %s does not exist.\n", strcat(argv[1], ".bmp")); 
    return 1;
  }  

  	fread(&io_header.Type, 1, 2, fptr); 
  	fread(&io_header.Size, 4, 1, fptr); 
  	fread(&io_header.Reserved, 1, 4, fptr); 
  	fread(&io_header.OffsetBits, 4, 1, fptr); 
  	fread(&io_header.InfoSize, 4, 1, fptr); 
  	fread(&io_header.Width, 4, 1, fptr); 
  	fread(&io_header.Height, 4, 1, fptr); 
  	fread(&io_header.Planes, 2, 1, fptr); 
  	fread(&io_header.BitPerPixel, 2, 1, fptr); 
  	fread(&io_header.Compression, 4, 1, fptr); 
  	fread(&io_header.ImageSize, 4, 1, fptr); 
  	fread(&io_header.XResolution, 4, 1, fptr); 
  	fread(&io_header.YResolution, 4, 1, fptr); 
  	fread(&io_header.Colors, 4, 1, fptr); 
  	fread(&io_header.ImportantColors, 4, 1, fptr); 
  	io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14);
  	fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);  
	
  	io_imageData = (unsigned char *) malloc(io_header.ImageSize); 
  	fread(io_imageData, io_header.ImageSize, 1, fptr); 
	
  	fclose(fptr);
   
  	printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); 
  	print_header(io_header);
  	printf("******************************************************************\n\n"); 
  
  	reduced_header.Type[0] = 'B'; 
  	reduced_header.Type[1] = 'M';
  	reduced_header.Size = io_header.Size; 
  	for (i=0; i<4; i++) 
    reduced_header.Reserved[i] = io_header.Reserved[i];
	reduced_header.OffsetBits = io_header.OffsetBits; 
  	reduced_header.InfoSize = io_header.InfoSize;
  	reduced_header.Width = ceil((float) io_header.Width / 2.0); 
  	reduced_header.Height = ceil((float) io_header.Height / 2.0); 
  	reduced_header.Planes = io_header.Planes;
  	reduced_header.BitPerPixel = io_header.BitPerPixel;
  	reduced_header.Compression = io_header.Compression; 
  	reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height; 
  
  	reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;
  	reduced_header.XResolution = io_header.XResolution; 
  	reduced_header.YResolution = io_header.YResolution; 
  	reduced_header.Colors = io_header.Colors; 
  	reduced_header.ImportantColors = io_header.ImportantColors; 
  	reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);
  
  
  	fillings = (4 - (io_header.Width * 3) % 4) % 4;
  	rowSize = io_header.Width * 3 + fillings;
  	fillings = (4 - (reduced_header.Width * 3) % 4) % 4; 
  	rowSize_reduced = reduced_header.Width * 3 + fillings; 
  	for (i = 0; i < reduced_header.Height; i++) 
  	  for (j = 0; j < reduced_header.Width; j++) { 
  	    k = i * 2 * rowSize + j * 2 * 3; 
  	    k_reduced = i * rowSize_reduced + j * 3; 
  	    reduced_imageData[k_reduced] = io_imageData[k]; 
  	    reduced_imageData[k_reduced+1] = io_imageData[k+1]; 
  	    reduced_imageData[k_reduced+2] = io_imageData[k+2]; 
    }

  
  	printf(">>>> File header of the reduced image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); 
  	print_header(reduced_header);
  	printf("******************************************************************\n\n"); 
  
  
  	write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  
  	frame_header.Type[0] = 'B'; 
  	frame_header.Type[1] = 'M';
  	frame_header.Size = io_header.Size; 
  	for (i=0; i<4; i++) 
    frame_header.Reserved[i] = io_header.Reserved[i];
  	frame_header.OffsetBits = io_header.OffsetBits; 
  	frame_header.InfoSize = io_header.InfoSize; 
  	frame_header.Width = ceil((float) reduced_header.Width*2 + framewidth*3); 
  	frame_header.Height = ceil((float) reduced_header.Height*2 + framewidth*3); 
  	frame_header.Planes = io_header.Planes; 
  	frame_header.BitPerPixel = io_header.BitPerPixel; 
  	frame_header.Compression = io_header.Compression; 
  	frame_header.Size = io_header.Size - io_header.ImageSize + frame_header.ImageSize;
  	frame_header.XResolution = io_header.XResolution; 
  	frame_header.YResolution = io_header.YResolution; 
  	frame_header.Colors = io_header.Colors;
  	frame_header.ImportantColors = io_header.ImportantColors; 
  	fillings = (4 - frame_header.Width * 3 % 4) % 4;
  	rowSize_frame = frame_header.Width * 3 + fillings;
  	frame_header.ImageSize = rowSize_frame*frame_header.Height;
  	frame_imageData = (unsigned char *) malloc(frame_header.ImageSize);
	for (i = 0; i < reduced_header.Height; i++) { 
    	for (j = 0; j < reduced_header.Width; j++) {
        	k_reduced = i * rowSize_reduced + j * 3; 
        	k_1 = (2*framewidth+i + io_header.Height / 2) * rowSize_frame + (io_header.Width - 1 - j+2*framewidth) * 3; 
        	k_2 = (2*framewidth+i + io_header.Height / 2) * rowSize_frame + (j+framewidth) * 3; 
        	k_3 = (reduced_header.Height - 1 - i+framewidth) * rowSize_frame + (j+framewidth) * 3; 
        	k_4 = (reduced_header.Height - 1 - i+framewidth) * rowSize_frame + (io_header.Width - 1 - j+2*framewidth) * 3; 
        	    frame_imageData[k_1] = reduced_imageData[k_reduced]; 
        	    frame_imageData[k_1 + 1] = reduced_imageData[k_reduced + 1];
        	    frame_imageData[k_1 + 2] = reduced_imageData[k_reduced + 2];

        	    frame_imageData[k_2] = reduced_imageData[k_reduced];
        	    frame_imageData[k_2 + 1] = reduced_imageData[k_reduced + 1];
        	    frame_imageData[k_2 + 2] = reduced_imageData[k_reduced + 2];
	
        	    frame_imageData[k_3] = reduced_imageData[k_reduced];
            	frame_imageData[k_3 + 1] = reduced_imageData[k_reduced + 1];
            	frame_imageData[k_3 + 2] = reduced_imageData[k_reduced + 2];
	
    	        frame_imageData[k_4] = reduced_imageData[k_reduced]; 
        	    frame_imageData[k_4 + 1] = reduced_imageData[k_reduced + 1];
            	frame_imageData[k_4 + 2] = reduced_imageData[k_reduced + 2];
    }	
}
    for(i=0;i<frame_header.Height;i++){
        for(j=0;j<frame_header.Width;j++){
            k = i*rowSize_frame+j*3;
            if((i>=0 && i<framewidth) || (i>=framewidth+reduced_header.Height && i<2*framewidth+reduced_header.Height)
			   || (i>=2*framewidth+2*reduced_header.Height && i<3*framewidth+2*reduced_header.Height) ||
               (j>=0 && j<framewidth) || (j>=framewidth+reduced_header.Width && j<2*framewidth+reduced_header.Width) 
			   || (j>=2*framewidth+2*reduced_header.Width && j<3*framewidth+2*reduced_header.Width)){
                frame_imageData[k] = rgb3;
                frame_imageData[k+1] = rgb2;
                frame_imageData[k+2] = rgb1;
        }
        }
    }

  	printf(">>>> File header of the frame merged image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_frame_merged"), ".bmp")); 
  	print_header(frame_header);
  	printf("******************************************************************\n\n"); 
  	write_image_file(file_name, frame_header, io_palette, frame_imageData);
  	free(io_palette); 
  	free(io_imageData); 
  	free(reduced_imageData); 
  	free(frame_imageData); 
   
  	system("pause"); 
  	return 0;
}
