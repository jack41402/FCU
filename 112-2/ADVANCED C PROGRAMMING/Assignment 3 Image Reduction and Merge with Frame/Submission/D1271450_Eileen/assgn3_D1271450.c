#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct{
	char Type[2];//B,M
	unsigned Size;//file size
	char Reserved[4];//reserved field
	unsigned OffsetBits;//offset bits
	unsigned InfoSize;//information size
	unsigned Width;//image width
	unsigned Height;//image height
	unsigned short Planes;//image planes
	unsigned short BitPerPixel;//bit per pixel
	unsigned Compression;//type of compression
	unsigned ImageSize;//size of pixel data
	unsigned XResolution;//horizontal resolution of image
	unsigned YResolution;//vertical resolution of image
	unsigned Colors;//colors
	unsigned ImportantColors;//important colors
}Header;
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
    FILE *fptr;//file pointer
    fptr = fopen(fname, "wb");//open the output file
    fwrite(&header.Type, 1, 2, fptr);//B,M 
    fwrite(&header.Size, 4, 1, fptr);//file size
    fwrite(&header.Reserved, 1, 4, fptr);//reserved field
    fwrite(&header.OffsetBits, 4, 1, fptr);//offset bits
    fwrite(&header.InfoSize, 4, 1, fptr);//information size
    fwrite(&header.Width, 4, 1, fptr);//image width
    fwrite(&header.Height, 4, 1, fptr);//image height
    fwrite(&header.Planes, 2, 1, fptr);//image planes
    fwrite(&header.BitPerPixel, 2, 1, fptr);//bit per pixel
    fwrite(&header.Compression, 4, 1, fptr);//type of compression
    fwrite(&header.ImageSize, 4, 1, fptr);//size of pixel data
    fwrite(&header.XResolution, 4, 1, fptr);//horizontal resolution of image
    fwrite(&header.YResolution, 4, 1, fptr);//vertical resolution of image
    fwrite(&header.Colors, 4, 1, fptr);//colors
    fwrite(&header.ImportantColors, 4, 1, fptr);//important colors
    fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr);//write the palette
    fwrite(imageData, 1, header.ImageSize, fptr);//write the imagedata
    fclose(fptr);//close the output file
}
void print_header(Header header) {
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]);//print Type:             plug in header.Type[0] and header.Type[1], then go to the next line
  printf("Size:             %u\n", header.Size);//print Size:             plug in header.Size, then go to the next line
  printf("Reserved:         %c%c%c%c\n", header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3]);//print Reserved:         plug in header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3], then go to the next line
  printf("OffsetBits:       %u\n", header.OffsetBits);//print OffsetBits:       plug in header.OffsetBits, then go to the next line
  printf("InfoSize:         %u\n", header.InfoSize);//print InfoSize:              plug in header.InfoSize, then go to the next line
  printf("Width:            %u\n", header.Width);//print Width:             plug in header.Width, then go to the next line
  printf("Height:           %u\n", header.Height);//print Height:            plug in header.Height, then go to the next line
  printf("Planes:           %d\n", header.Planes);//print Planes:             plug in header.Planes, then go to the next line
  printf("BitPerPixel:      %d\n", header.BitPerPixel);//print BitPerPixel:      plug in eader.BitPerPixel, then go to the next line
  printf("Compression:      %u\n", header.Compression);//print Compression:      plug in header.Compression, then go to the next line
  printf("ImageSize:        %u\n", header.ImageSize);//print ImageSize:        plug in header.ImageSize, then go to the next line
  printf("XResolution:      %u\n", header.XResolution);//print XResolution:      plug in header.XResolution, then go to the next line
  printf("YResolution:      %u\n", header.YResolution);//print YResolution:      plug in header.YResolution, then go to the next line
  printf("Colors:           %u\n", header.Colors);//print Colors:           plug in header.Colors, then go to the next line
  printf("ImportantColors:  %u\n", header.ImportantColors);//print ImportantColors:  plug in header.ImportantColors, then go to the next line

}
void drawFrame(unsigned char *imageData, int width, int height, int frameSize, unsigned char frameColor[3], int rowSize_merge,int r_height,int r_width) {
    int i, j ;//loop variables
    int k;
    for (i = 0; i < height; ++i) {//run until the end of height
        for (j = 0; j < width; ++j) {//run until the end of width
        	k = i * rowSize_merge + j * 3;//pixel index 
            if (i < frameSize || i >= height - frameSize || i>=r_height+frameSize&&i<=r_height+frameSize*2||j < frameSize || j >= width - frameSize||j>=r_width+frameSize&&j<=r_width+frameSize*2) {//set boundries which the fame is going to appear
                imageData[k] = frameColor[0];//copy blue
                imageData[k + 1] = frameColor[1];//copy green
                imageData[k + 2] = frameColor[2];//copy red
            }
        }
    }
}

int main(int argc,char*argv[]){
	//variables
	FILE *fptr;//file pointer
	Header io_header;
	Header reduced_header;
	Header merge_header;
	unsigned char *io_palette;
	unsigned char *io_imageData;
	unsigned char *reduced_imageData;
	unsigned char *merge_imageData;
	int rowSize;
	int fillings;
	int rowSize_merge;
	int rowSize_reduced;
	char file_name[60];
	int sofip,vfc1,vfc2,vfc3;//size of frame in pixels, R,B,G
	int i,j;//loop variables
	int k,k_1,k_2,k_3,k_4,k_reduced,k_merge;
	
	if(argc==1){//if there is only one arguement
		printf("Please enter the image file name.\n");//print please enter the image file name, then go to the next line
		system("pause");
		return 1;
	}
	else if(argc>3){//if the command has more than three strings, too many arguments are entered.
		printf("Too many image file names entered.\n");
		system("pause");
		return 1;
	}
		fptr=fopen(strcat(strcpy(file_name,argv[1]),".bmp"),"rb"); //open the file argv[1] concaternate by bmp.
		if(fptr==NULL){////if the file pointer is empty, the file does not exist
			printf("File %s does not exist.\n",strcat(argv[1],".bmp"));//print that this file does not exist
			return 1;
		}
	
fread(&io_header.Type, 1, 2, fptr);//B,M 
fread(&io_header.Size, 4, 1, fptr); //file size
fread(&io_header.Reserved, 1, 4, fptr);//reserved field
fread(&io_header.OffsetBits, 4, 1, fptr);//offset bits
fread(&io_header.InfoSize, 4, 1, fptr);//information size
fread(&io_header.Width, 4, 1, fptr);//image width
fread(&io_header.Height, 4, 1, fptr);//image height
fread(&io_header.Planes, 2, 1, fptr);//image planes
fread(&io_header.BitPerPixel, 2, 1, fptr);//bit per pixel
fread(&io_header.Compression, 4, 1, fptr);//type of compression
fread(&io_header.ImageSize, 4, 1, fptr);//size of pixel data
fread(&io_header.XResolution, 4, 1, fptr);//horizontal resolution of image
fread(&io_header.YResolution, 4, 1, fptr);//vertical resolution of image
fread(&io_header.Colors, 4, 1, fptr);//colors
fread(&io_header.ImportantColors, 4, 1, fptr);//important colors 
io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14); //allocate memory space for the palette
fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr);//read palette from the image file 
io_imageData = (unsigned char *) malloc(io_header.ImageSize); //allocate memory space for image pixel data.
fread(io_imageData, io_header.ImageSize, 1, fptr); //read image pixel data from the image file
fclose(fptr);//close the input file
do{//continue until the numerage is between four and twenty
printf("Enter the size of frame in pixel (between 4 and 20):\n");//print Enter the size of frame in pixel (between 4 and 20):, then go to the next line
scanf("%d",&sofip);}//scan the frame size
while(sofip<4||sofip>20);
printf("Enter RGB value of the frame color:\n");//print Enter RGB value of the frame color:, then go to the next line
scanf("%d%d%d",&vfc3,&vfc2,&vfc1);//scan R,B,G
printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp"));//print the file header message
print_header(io_header);
printf("******************************************************************\n\n");
  reduced_header.Type[0] = 'B';//B
  reduced_header.Type[1] = 'M';//M 
  reduced_header.Size = io_header.Size;//file size
  for (i=0; i<4; i++){//reserved field 
    reduced_header.Reserved[i] = io_header.Reserved[i];
   }
  reduced_header.OffsetBits = io_header.OffsetBits;//offset bits
  reduced_header.InfoSize = io_header.InfoSize;//information size 
 
  reduced_header.Width = ceil((float) io_header.Width / 2.0);//image width
  reduced_header.Height = ceil((float) io_header.Height / 2.0);//image height
  reduced_header.Planes = io_header.Planes;//image planes
  reduced_header.BitPerPixel = io_header.BitPerPixel;//bit per pixel
  reduced_header.Compression = io_header.Compression;//type of compression
  reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height;//size of pixel data
  reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize;//file size
  reduced_header.XResolution = io_header.XResolution; //horizontal resolution of image
  reduced_header.YResolution = io_header.YResolution;//vertical resolution of image
  reduced_header.Colors = io_header.Colors;//colors
  reduced_header.ImportantColors = io_header.ImportantColors;//important colors 
  reduced_imageData = (unsigned char *) malloc(reduced_header.ImageSize);//allocate memory space for image pixel data of the reduced image
  merge_header.Type[0] = 'B';//B
  merge_header.Type[1] = 'M';//M
  merge_header.Size = io_header.Size;//file size
  for (i=0; i<4; i++){//reserved field 
    merge_header.Reserved[i] = io_header.Reserved[i];
   }
  merge_header.OffsetBits = io_header.OffsetBits;//offset bits
  merge_header.InfoSize = io_header.InfoSize; //information size 
 
  merge_header.Width = io_header.Width + sofip*3;//merged image width, plus the frame
  merge_header.Height = io_header.Height + sofip*3;//merged image height, plus the frame
  merge_header.Planes = io_header.Planes;//image planes
  merge_header.BitPerPixel = io_header.BitPerPixel; //bit per pixel
  merge_header.Compression = io_header.Compression;//type of compression
  merge_header.ImageSize = ceil((float) merge_header.Width * 3.0 / 4.0) * 4 * merge_header.Height; //merged size of pixel data
  merge_header.Size = io_header.Size - io_header.ImageSize + merge_header.ImageSize;//merged file size
  merge_header.XResolution = io_header.XResolution;//horizontal resolution of image);
  merge_header.YResolution = io_header.YResolution;//vertical resolution of image
  merge_header.Colors = io_header.Colors;//colors
  merge_header.ImportantColors = io_header.ImportantColors;//important colors 
  merge_imageData=(unsigned char*)malloc(merge_header.ImageSize);//allocate memory space for image pixel data of the merged image
  fillings = (4 - (io_header.Width * 3) % 4) % 4;//the number of filling bytes at the end of a row
  rowSize = io_header.Width * 3 + fillings;//the number of bytes in a row of the original image
  fillings = (4 - (reduced_header.Width * 3) % 4) % 4;//the number of filling bytes at the end of a row 
  rowSize_reduced = reduced_header.Width * 3 + fillings;//the number of bytes in a row of the reduced image.
  fillings = (4 - (merge_header.Width * 3) % 4) % 4;//the number of filling bytes at the end of a row 
  rowSize_merge = merge_header.Width * 3 + fillings;//the number of bytes in a row of the merged image.
  for (i = 0; i < reduced_header.Height; i++)//go through the height of reduced image 
    for (j = 0; j < reduced_header.Width; j++) {//go through the width of reduced image 
      k = i * 2 * rowSize + j * 2 * 3;//pixel index of the original input image
      k_reduced = i * rowSize_reduced + j * 3;//pixel index of the reduced input image
      reduced_imageData[k_reduced] = io_imageData[k];//copy blue
      reduced_imageData[k_reduced+1] = io_imageData[k+1];//copy green
      reduced_imageData[k_reduced+2] = io_imageData[k+2]; //copy red
    }
  printf(">>>> File header of the reduced image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp"));
  print_header(reduced_header);//print the file header message
  printf("******************************************************************\n\n");
  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);//write image to file
 
  for (i = 0; i < reduced_header.Height; ++i) {//go through the height of reduced image 
    for (j = 0; j < reduced_header.Width; ++j) {//go through the width of reduced image
      k_reduced = i * rowSize_reduced + j * 3;//pixel index of the reduced input image
      k_1 = (i + merge_header.Height/ 2+sofip/2) * rowSize_merge + (merge_header.Width -1- j-sofip) * 3;//the first dimension's boundary 
      k_2 = (i + merge_header.Height / 2+sofip/2) * rowSize_merge + (j +sofip)* 3;//the second dimension's boundary
      k_3 = (merge_header.Height/2 -1 - i-sofip/2) * rowSize_merge + (j+sofip )* 3;//the third dimension's boundary
      k_4 = (merge_header.Height/2 -1 - i-sofip/2) * rowSize_merge + (merge_header.Width -1- j-sofip) * 3;//the fourth dimension's boundary
	  merge_imageData[k_1] = reduced_imageData[k_reduced];//copy blue of first dimension
	  merge_imageData[k_1+1] = reduced_imageData[k_reduced+1];//copy green of first dimension
	  merge_imageData[k_1+2] = reduced_imageData[k_reduced+2];//copy red of first dimension
	  merge_imageData[k_2] = reduced_imageData[k_reduced];//copy blue of second dimension
	  merge_imageData[k_2+1] = reduced_imageData[k_reduced+1];//copy green of second dimension
	  merge_imageData[k_2+2] = reduced_imageData[k_reduced+2];//copy red of second dimension
	  merge_imageData[k_3] = reduced_imageData[k_reduced];//copy blue of third dimension 
	  merge_imageData[k_3+1] = reduced_imageData[k_reduced+1];//copy green of third dimension 
	  merge_imageData[k_3+2] = reduced_imageData[k_reduced+2];//copy red of third dimension 
	  merge_imageData[k_4] = reduced_imageData[k_reduced];//copy blue of fourth dimension 
	  merge_imageData[k_4+1] = reduced_imageData[k_reduced+1];//copy green of fourth dimension
	  merge_imageData[k_4+2] = reduced_imageData[k_reduced+2];//copy red of fourth dimension
    }
  }
  drawFrame(merge_imageData, merge_header.Width, merge_header.Height, sofip, (unsigned char[]){vfc1, vfc2, vfc3},rowSize_merge,reduced_header.Height,reduced_header.Width);//draw the frame
  
  
  printf(">>>> File header of the merged image, %s:\n\n", 
         strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp"));
  print_header(merge_header);//print the file header message
  printf("******************************************************************\n\n"); 
  write_image_file(file_name, merge_header, io_palette, merge_imageData);//write image to file
  free(io_palette);//release memory space of palette
  free(io_imageData); //release memory space of imageData
  free(reduced_imageData);//release memory space of reduced_imageData 
  free(merge_imageData);//release memory space of merge_imageData
  system("pause"); 
  return 0;
}
