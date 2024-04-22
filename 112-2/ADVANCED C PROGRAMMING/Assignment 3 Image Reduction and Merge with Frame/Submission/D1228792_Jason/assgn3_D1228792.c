#include <stdio.h>
#include <stdlib.h>
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
void Write_data(char *fname, Header header , unsigned char *palette, unsigned char *imageData){
	FILE *fptr;
	fptr = fopen(fname, "wb");
	if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    printf("File %s does not exist.\n", fname); // Print error message.
    system("pause"); // Terminate the program.
  } 
	fwrite(&header.Type, 1, 2, fptr); // Two fixed characters, "BM".
  fwrite(&header.Size, 4, 1, fptr); // File size in bytes.
  fwrite(&header.Reserved, 1, 4, fptr); // Reserved field.
  fwrite(&header.OffsetBits, 4, 1, fptr); // Offset.
  fwrite(&header.InfoSize, 4, 1, fptr); // Information size in byte.
  fwrite(&header.Width, 4, 1, fptr); // Image width in pixel.
  fwrite(&header.Height, 4, 1, fptr); // Image height in pixel.
  fwrite(&header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
  fwrite(&header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
  fwrite(&header.Compression, 4, 1, fptr); // Value indicating what type of compression.
  fwrite(&header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  fwrite(&header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
  fwrite(&header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
  fwrite(&header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
  fwrite(&header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

  fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr); // Write the palette.
  fwrite(imageData, 1, header.ImageSize, fptr); // Write the image pixel data.
  fclose(fptr); // Close the output file.
}
void print_data(Header header){
  printf("\nType:             %c%c\n", header.Type[0], header.Type[1]); // Two fixed characters, "BM".
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
  printf("ImportantColors:  %u\n", header.ImportantColors); // Close the output file.
  printf("******************************************************************\n\n");
}
int main(int argc, char *argv[]){
	FILE *fptr;
	Header heaori,heared,heafin;
	unsigned char *palette;
	unsigned char *imageData, *reimageData, *finimageData;
	char *reduce_fname, *merge_fname;
	int rowSize,rerowsize,finrowsize;
	int fillings;
	int i,j,k,n,kr,ko,kfin;
	int fcol1,fcol2,fcol3; //variables of the RGB of the frame.
	if (argc==1) { // One argument in the command line. This argument must "image_color_to_gray", the executable code.
    	printf("Please enter the image file name.\n");
    	system("pause");
    	return 1;
  	}
  	else if (argc==2){
  		reduce_fname = "abraham_lake_reduced.bmp";
  		merge_fname = "abraham_lake_frame_merged.bmp";
	}
	else if (argc==3){
		printf("Please enter one more image file name.\n");
    	system("pause");
    	return 1;
	}
	else if (argc==4){
		reduce_fname = argv[2];
		merge_fname = argv[3];
	}
  	else if (argc>4) { // If the command has more than three strings, too many arguments are entered.
    	printf("Too many image file names entered.\n");
    	system("pause");
    	return 1;
  	}
  	fptr = fopen(argv[1], "rb"); // Open the input file using binary mode.
  	if (fptr==NULL) { // If the file pointer is empty, it means the file does not exist.
    	printf("File %s does not exist.\n", argv[1]); // Print error message.
    	return 1; // Terminate the program.
  	} 
  	fread(&heaori.Type, 1, 2, fptr); // Two fixed characters, "BM".
  	fread(&heaori.Size, 4, 1, fptr); // File size in bytes.
  	fread(&heaori.Reserved, 1, 4, fptr); // Reserved field.
  	fread(&heaori.OffsetBits, 4, 1, fptr); // Offset.
  	fread(&heaori.InfoSize, 4, 1, fptr); // Information size in byte.
  	fread(&heaori.Width, 4, 1, fptr); // Image width in pixel.
  	fread(&heaori.Height, 4, 1, fptr); // Image height in pixel.
  	fread(&heaori.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
  	fread(&heaori.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
  	fread(&heaori.Compression, 4, 1, fptr); // Value indicating what type of compression.
  	fread(&heaori.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
  	fread(&heaori.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
  	fread(&heaori.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
  	fread(&heaori.Colors, 4, 1, fptr); 
  	fread(&heaori.ImportantColors, 4, 1, fptr);
  	palette = (unsigned char *) malloc(heaori.OffsetBits - heaori.InfoSize - 14); // Allocate memory space for the palette.
  	fread(palette, heaori.OffsetBits - heaori.InfoSize - 14, 1, fptr);
  	imageData = (unsigned char *) malloc(heaori.ImageSize); // Allocate memory space for image pixel data.
  	fread(imageData, heaori.ImageSize, 1, fptr); // Read image pixel data from the image file. 
  	fclose(fptr);
  	printf("Enter the size of the frame in pixel (between 4 and 20): ");
  	scanf("%d",&n);
  	printf("\nEnter RGB value of the frame color: ");
  	scanf("%d %d %d",&fcol1,&fcol2,&fcol3);
  	printf("\n>>>> File header of the input image, %s:\n",argv[1]);
  	print_data(heaori);//print the information of the image.
  	//write the information of the reduce_image.
  	heared.Type[0] = heaori.Type[0];
  	heared.Type[1] = heaori.Type[1];
  	for(i=0;i<4;i++) heared.Reserved[i] = heaori.Reserved[i];
  	heared.OffsetBits = heaori.OffsetBits;
  	heared.InfoSize = heaori.InfoSize;
  	heared.Width = ceil((float) heaori.Width / 2.0);
  	heared.Height = ceil((float) heaori.Height / 2.0);
  	heared.Planes = heaori.Planes;
  	heared.BitPerPixel = heaori.BitPerPixel;
  	heared.Compression = heaori.Compression;
  	heared.ImageSize = ceil((float) heared.Width *3.0 / 4.0) * 4 * heared.Height;
  	heared.Size = heaori.Size - heaori.ImageSize + heared.ImageSize;
  	heared.XResolution = heaori.XResolution;
  	heared.YResolution = heaori.YResolution;
  	heared.Colors = heaori.Colors;
  	heared.ImportantColors = heaori.ImportantColors;
  	reimageData = (unsigned char *) malloc(heared.ImageSize);
  	fillings = (4 - (heaori.Width * 3) % 4) % 4; // The number of filling bytes at the end of a row.
  	rowSize = heaori.Width * 3 + fillings;
  	fillings = (4-(heared.Width*3)%4)%4;
  	rerowsize = heared.Width*3+fillings;
  	for(i=0;i<heared.Height;i++){
  		for(k=0;k<heared.Width;k++){
  			ko=i*rowSize*2+k*2*3;
  			kr=i*rerowsize+k*3;
  			reimageData[kr] = imageData[ko];
  			reimageData[kr+1] = imageData[ko+1];
  			reimageData[kr+2] = imageData[ko+2];
	  	}
  	}//reduce the image
  	Write_data(reduce_fname,heared,palette,reimageData);// write the data in to the file.
  	printf(">>>> File header of the reduce image, %s:\n",reduce_fname);
  	//write the information of merge_image.
  	print_data(heared);//print the information of the image.
  	heafin.Type[0] = heared.Type[0];
  	heafin.Type[1] = heared.Type[1];
  	for(i=0;i<4;i++) heafin.Reserved[i] = heared.Reserved[i];
  	heafin.OffsetBits = heared.OffsetBits;
  	heafin.InfoSize = heared.InfoSize;
 	heafin.Width = heared.Width * 2 + n * 3;
  	heafin.Height = heared.Height * 2 + n * 3;
  	heafin.Planes = heared.Planes;
  	heafin.BitPerPixel = heared.BitPerPixel;
  	heafin.Compression = heared.Compression;
  	heafin.XResolution = heared.XResolution;
  	heafin.YResolution = heared.YResolution;
  	heafin.Colors = heared.Colors;
  	heafin.ImportantColors = heared.ImportantColors;
  	fillings = (4 - heafin.Width * 3 % 4) % 4;
  	finrowsize = heafin.Width * 3 + fillings;
  	heafin.ImageSize = finrowsize * heafin.Height;
  	heafin.Size =  heafin.ImageSize + heafin.OffsetBits;
  	finimageData = (unsigned char *) malloc(heafin.ImageSize);
  	for(i=0;i<heafin.Height;i++){
  		for(k=0;k<heafin.Width;k++){
  			kfin = i * finrowsize + k * 3;
  			// for the vertical frame.
			if(k>=0&&k<n||k>=heared.Width+n&&k<heared.Width+2*n||k>=heared.Width*2+2*n&&k<heared.Width*2+3*n){
  				finimageData[kfin] = fcol3;
  				finimageData[kfin+1] = fcol2;
  				finimageData[kfin+2] = fcol1;
			}
			// for the horizontal frame.
			else if(i>=0&&i<n||i>=heared.Height+n&&i<heared.Height+2*n||i>=heared.Height*2+2*n&&i<heared.Height*2+3*n){
				finimageData[kfin] = fcol3;
  				finimageData[kfin+1] = fcol2;
  				finimageData[kfin+2] = fcol1;
			}
			// for the down left corner.
			else if(i>=n&&i<heared.Height+n&&k>=n&&k<heared.Width+n){
				kr = (i - n) * rerowsize + (k - n) * 3;
				finimageData[kfin] = reimageData[kr + (heared.Height - (i-n)*2) * rerowsize];
				finimageData[kfin+1] = reimageData[kr + (heared.Height - (i-n)*2) * rerowsize+1];
				finimageData[kfin+2] = reimageData[kr + (heared.Height - (i-n)*2) * rerowsize+2];
			}
			// for the down right corner.
			else if(i>=n&&i<heared.Height+n&&k>=heared.Width+2*n&&k<heared.Width*2+2*n){
				kr = (i - n) * rerowsize + (k - 2 * n - heared.Width) * 3;
				finimageData[kfin] = reimageData[kr + (heared.Height - (i-n)*2) * rerowsize + (heared.Width - (k - 2 * n - heared.Width)*2) * 3];
				finimageData[kfin+1] = reimageData[kr + (heared.Height - (i-n)*2) * rerowsize + (heared.Width - (k - 2 * n - heared.Width)*2) * 3+1];
				finimageData[kfin+2] = reimageData[kr + (heared.Height - (i-n)*2) * rerowsize + (heared.Width - (k - 2 * n - heared.Width)*2) * 3+2];
			}
			// for the up left corner.
			else if(i>=heared.Height+2*n&&i<heared.Height*2+2*n&&k>=n&&k<heared.Width+n){
				kr = (i-2*n-heared.Height) * rerowsize + (k - n) * 3;
				finimageData[kfin] = reimageData[kr];
				finimageData[kfin+1] = reimageData[kr+1];
				finimageData[kfin+2] = reimageData[kr+2];
			}
			// for the up right corner.
			else{
				kr = (i-2*n-heared.Height) * rerowsize + (k - 2 * n - heared.Width) * 3;
				finimageData[kfin] = reimageData[kr + (heared.Width - (k-2*n-heared.Width)*2)*3];
				finimageData[kfin+1] = reimageData[kr + (heared.Width - (k-2*n-heared.Width)*2)*3+1];
				finimageData[kfin+2] = reimageData[kr + (heared.Width - (k-2*n-heared.Width)*2)*3+2];
			}
	  	}
	}
  	Write_data(merge_fname,heafin,palette,finimageData);// write the data in to the file.
  	printf(">>>> File header of the frame merged image, %s:\n",merge_fname);
  	print_data(heafin);//print the information of the image.
  	free(palette); // Release memory space of palette.
  	free(imageData); // Release memory space of imageData.
  	free(reimageData); // Release memory space of reimageData.
  	free(finimageData); // Release memory space of finimageData.
}
