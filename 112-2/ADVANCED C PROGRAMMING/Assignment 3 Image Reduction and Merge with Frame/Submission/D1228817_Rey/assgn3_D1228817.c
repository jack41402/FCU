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

void read_header(Header* header, FILE* fptr){
	
  fread(&header->Type, 1, 2, fptr);
  fread(&header->Size, 4, 1, fptr);
  fread(&header->Reserved, 1, 4, fptr);
  fread(&header->OffsetBits, 4, 1, fptr);
  fread(&header->InfoSize, 4, 1, fptr);
  fread(&header->Width, 4, 1, fptr);
  fread(&header->Height, 4, 1, fptr);
  fread(&header->Planes, 2, 1, fptr);
  fread(&header->BitPerPixel, 2, 1, fptr);
  fread(&header->Compression, 4, 1, fptr);
  fread(&header->ImageSize, 4, 1, fptr);
  fread(&header->XResolution, 4, 1, fptr);
  fread(&header->YResolution, 4, 1, fptr);
  fread(&header->Colors, 4, 1, fptr);
  fread(&header->ImportantColors, 4, 1, fptr);
}

void write_header(Header* header, FILE* fptr){
	
  fwrite(&header->Type, 1, 2, fptr);
  fwrite(&header->Size, 4, 1, fptr);
  fwrite(&header->Reserved, 1, 4, fptr);
  fwrite(&header->OffsetBits, 4, 1, fptr);
  fwrite(&header->InfoSize, 4, 1, fptr);
  fwrite(&header->Width, 4, 1, fptr);
  fwrite(&header->Height, 4, 1, fptr);
  fwrite(&header->Planes, 2, 1, fptr);
  fwrite(&header->BitPerPixel, 2, 1, fptr);
  fwrite(&header->Compression, 4, 1, fptr);
  fwrite(&header->ImageSize, 4, 1, fptr);
  fwrite(&header->XResolution, 4, 1, fptr);
  fwrite(&header->YResolution, 4, 1, fptr);
  fwrite(&header->Colors, 4, 1, fptr);
  fwrite(&header->ImportantColors, 4, 1, fptr);
}

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
  // End of output commands
  printf("************************************************************\n");
}

int RGB_input_verify(unsigned B, unsigned G, unsigned R){//Verify if the input values of R G B are valid.
if(B<0||B>255) return -1;
else if(G<0||G>255) return -1;
else if(R<0||R>255) return -1;
else return 0;
}

void omit_bmp(char* file_name, char* argv){//Deleate ".bmp" at the end of the parameter.
	strcpy(file_name, argv);
	file_name[strlen(argv)-4]='\0';
}

int main(int argc, char *argv[]){
  FILE *fptr; // File pointer 
  Header	header, output_header; // Bitmap file header
  unsigned char	*palette; // Pointer: palette.
  unsigned char	*imageData; // Pointer: Image pixel data.
  unsigned char *rimageData;// Pointer: Reduced image pixel data.
  unsigned char *merged_imageData;// Pointer: Merged image pixel data.
  char file_name[40];
  int rowSize; // Number of bytes in a row (Original image). 
  int r_rowSize;// Number of bytes in a row (Reduced image). 
  int fillings; // Number of bytes of padding 0's (Original image).
  int r_fillings;// Number of bytes of padding 0's (Reduced image).
  unsigned B, G, R, frame_size;
  unsigned rSize;// File size of reduced image in bytes.
  unsigned rWidth;// Reduced image width in pixel.
  unsigned rHeight;// Reduced image height in pixel.
  unsigned rImageSize;// Size of the actual pixel data of reduced image, in bytes.
  int i, j, k, k_reduced; // Loop variable.
  int k1, k2, k3, k4;// Loop variable.
  
  if (argc==1) { // One argument in the command line. This argument must "image_vertical_mirror_reflection", the executable code.
    printf("Please enter an image file name.\n");
    return -1;
  }
  
  else if (argc>2) { // If the command has more than three strings, too many arguments are entered.
    printf("Too many image file names entered. Input an image file .\n");
    return 1;
  }
  
  fptr=fopen(argv[1], "rb");
  
  if(fptr==NULL){
  	printf("File does not exist.");
  	return -1;
  }
  
  printf("Enter the size of frame in pixel (between 4 and 20): ");
  do{
  	scanf("%u", &frame_size);
  	if(frame_size<=4||frame_size>=20) printf("Input out of bound. Try again: ");
  }while(frame_size<=4||frame_size>=20);
  
  printf("\nEnter the RGB value of the frame color: ");
  do{
  	scanf("%u %u %u", &R, &G, &B);
  	if(RGB_input_verify( B,  G,  R)==-1) printf("Input out of bound. Try again: ");
  }while(RGB_input_verify( B,  G,  R)==-1);
  

  read_header(&header, fptr);//Reads the header of the original image.
  output_header=header;//Copy the contents of header to output_header.
  
  printf("\n>>>> File header of the input image, %s:\n\n", argv[1]);
  print_header(header);//Prints the header of the original image.
  
  rWidth=ceil(header.Width/2.0);//Calculate the width of the reduced image.
  rHeight=ceil(header.Height/2.0);//Calculate the height of the reduced image.
  r_fillings=(4-(rWidth*3)%4)%4;//Calculate the fillings of the reduced image.
  rImageSize=(rWidth*3+r_fillings)*rHeight;//Calculate the image size of the reduced image.
  rSize=header.Size-header.ImageSize+rImageSize;//Calculate the size of the reduced image.

  
  palette= (unsigned char*) malloc(header.OffsetBits-header.InfoSize-14);//Alocate space for original image palette.
  fread(palette, header.OffsetBits-header.InfoSize-14, 1, fptr);//Read data of original image palette.
  
  imageData= (unsigned char*) malloc(header.ImageSize);//Alocate space for original image pixel data.
  fread(imageData, header.ImageSize, 1, fptr);//Read data of original image pixel data.
  
  rimageData= (unsigned char*) malloc(rImageSize);//Alocate space for reduced image pixel data.
  
  fillings=(4-(header.Width*3)%4)%4;//Calculate the fillings for the original image.
  rowSize=header.Width*3+fillings;//Calculate the row size of the original image.
  r_rowSize=rWidth*3+r_fillings;//Calculate the row size of the reduced image.
  
  for(i=0; i<rHeight; i++){
  	for(j=0; j<rWidth; j++){
  		k=i*2*rowSize+j*2*3;// Pixel index of the original input image.
  		k_reduced=i*(r_rowSize)+j*3;// Pixel index of the reduced image.
  		
  		rimageData[k_reduced]=imageData[k];// Copy blue level.
  		rimageData[k_reduced+1]=imageData[k+1];// Copy green level.
  		rimageData[k_reduced+2]=imageData[k+2];// Copy red level.
	  }
  }
  
  fclose(fptr);
  
  
  omit_bmp(file_name, argv[1]);
  
  fptr=fopen(strcat(file_name, "_reduced.bmp"), "wb");
  
  output_header.Width=rWidth;
  output_header.Height=rHeight;
  output_header.ImageSize=rImageSize;
  output_header.Size=rSize;
  
  printf("\n>>>> File header of the reduced image, %s:\n\n", file_name);
  print_header(output_header);
  write_header(&output_header, fptr);//output_header is used to store and write the header of the reduced image.
  
  fwrite(palette, header.OffsetBits-header.InfoSize-14, 1, fptr);//Write data of reduced image palette.
  fwrite(rimageData, rImageSize, 1, fptr);//Write data of reduced image pixel data.
  fclose(fptr);
  
  
  omit_bmp(file_name, argv[1]);
  
  fptr=fopen(strcat(file_name, "_frame_merged.bmp"), "wb");
  
  output_header.Width=rWidth*2+frame_size*3;//Calculate the width of the merged image.
  output_header.Height=rHeight*2+frame_size*3;//Calculate the height of the merged image.
  
  fillings=(4-(output_header.Width*3)%4)%4;//Calculate the fillings for the merged image.
  output_header.ImageSize=output_header.Height*(output_header.Width*3+fillings);//Calculate the image size of the merged image.
  output_header.Size=header.Size - header.ImageSize + output_header.ImageSize;//Calculate the size of the merged image.
  
  printf("\n>>>> File header of the merged image, %s:\n\n", file_name);
  print_header(output_header);
  
  merged_imageData= (unsigned char*) malloc(output_header.ImageSize);//Alocate space for merged image pixel data.
  
  
  rowSize=output_header.Width*3+fillings;
  
  for(i=0; i<output_header.Height; i++){
  	for(j=0; j<output_header.Width; j++){
  		k=i*rowSize+j*3;// Pixel index of the merged image.
   		k1=(i-frame_size*2-rHeight+1)*r_rowSize+((rWidth-1)-(j-2*frame_size-rWidth))*3;// Pixel index for the 1st quadrant. 		
  		k2=(i-frame_size*2-rHeight+1)*r_rowSize+(j-frame_size+1)*3;// Pixel index for the 2nd quadrant.
  		k3=((rHeight-1)-(i-frame_size))*r_rowSize+(j-frame_size+1)*3;// Pixel index for the 3rd quadrant.
  		k4=((rHeight-1)-(i-frame_size))*r_rowSize+((rWidth-1)-(j-2*frame_size-rWidth))*3;// Pixel index for the 4th quadrant.
  		
		
		if(i>rHeight+frame_size*2-1&&i<rHeight*2+frame_size*2-1&&j>rWidth+frame_size*2-1&&j<rWidth*2+frame_size*2-1){//1st quadrant.
			merged_imageData[k]=rimageData[k1];
			merged_imageData[k+1]=rimageData[k1+1];
			merged_imageData[k+2]=rimageData[k1+2];
		}
		else if(i>rHeight+frame_size*2-1&&i<rHeight*2+frame_size*2-1&&j>frame_size-1&&j<rWidth+frame_size-1){//2nd quadrant.
			merged_imageData[k]=rimageData[k2];
			merged_imageData[k+1]=rimageData[k2+1];
			merged_imageData[k+2]=rimageData[k2+2];
		}
		else if(i>frame_size-1&&i<rHeight+frame_size-1&&j>frame_size-1&&j<rWidth+frame_size-1){//3rd quadrant.
			merged_imageData[k]=rimageData[k3];
			merged_imageData[k+1]=rimageData[k3+1];
			merged_imageData[k+2]=rimageData[k3+2];
		}
		else if(i>frame_size-1&&i<rHeight+frame_size-1&&j>rWidth+frame_size*2-1&&j<rWidth*2+frame_size*2-1){//4th quadrant.
			merged_imageData[k]=rimageData[k4];
			merged_imageData[k+1]=rimageData[k4+1];
			merged_imageData[k+2]=rimageData[k4+2];
		}
		else{//Print the frame.
			merged_imageData[k]=B;
			merged_imageData[k+1]=G;
			merged_imageData[k+2]=R;
		}
	  }
  }
  
  write_header(&output_header, fptr);//output_header is used to store and write the header of the merged image.
  fwrite(palette, header.OffsetBits-header.InfoSize-14, 1, fptr);//Write data of merged image palette.
  fwrite(merged_imageData, output_header.ImageSize, 1, fptr);//Write data of merged image pixel data.

  fclose(fptr);
  
  free(palette);
  free(imageData);
  free(rimageData);
  free(merged_imageData);
  
  return 0;
  }
