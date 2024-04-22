#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure for BMP file header
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

// Function to print the BMP file header
void print_header(Header header) {
  // Print various fields of the header structure
  printf("Type:             %c%c\n", header.Type[0], header.Type[1]);
  printf("Size:             %u\n", header.Size);
  printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1],
                                         header.Reserved[2], header.Reserved[3]);
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

// Function to write BMP image data to a file
void write_image_file(char *fname, Header header, unsigned char *palette, unsigned char *imageData) {
  FILE *fptr;
  // Open the file for writing in binary mode
  fptr = fopen(fname, "wb"); 
  // Write various fields of the header structure to the file
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

  // Write palette data to the file
  fwrite(palette, 1, header.OffsetBits - header.InfoSize - 14, fptr);
  // Write image data to the file
  fwrite(imageData, 1, header.ImageSize, fptr);
  fclose(fptr); // Close the file
}

int main(int argc, char *argv[]) {
  // Variable declarations
  FILE *fptr;
  Header io_header;
  unsigned char    *io_palette;
  unsigned char    *io_imageData;
  Header reduced_header;
  unsigned char    *reduced_imageData;
  char file_name[40];
  int rowSize;
  int rowSize_reduced;
  int fillings;
  int i, j; 
  int k; 
  int k_reduced;
  int k_1, k_2, k_3, k_4;
    
    Header aa;
    int s;
    int color[3];
    unsigned char    *f_imageData;
    
  // Check if the correct number of arguments is provided
  if (argc==1) {
    printf("Please enter an image file name without .bmp extension.\n");
    return 1;
  }
  else if (argc>2) { 
    printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
    return 1;
  }
  // Open the BMP image file for reading in binary mode
  fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb");
  // Check if the file exists
  if (fptr==NULL) { 
    printf("File %s does not exist.\n", strcat(argv[1], ".bmp"));
    return 1;
  }
  // Read various fields of the BMP file header
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
    
    // Prompt user to input frame size and color
    printf("Enter the size of frame in pixel (between 4 and 20): ");
    scanf("%d",&s);
    printf("Enter RGB value of the frame color: ");
    scanf("%d %d %d",&color[0],&color[1],&color[2]);
    

  // Allocate memory for palette and image data
  io_palette = (unsigned char *) malloc(io_header.OffsetBits - io_header.InfoSize - 14); 
  fread(io_palette, io_header.OffsetBits - io_header.InfoSize - 14, 1, fptr); 
  io_imageData = (unsigned char *) malloc(io_header.ImageSize);
  fread(io_imageData, io_header.ImageSize, 1, fptr); 
    
  fclose(fptr); // Close the file
  
  // Print the header of the input image
  printf(">>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp")); 
  print_header(io_header);
  printf("******************************************************************\n\n"); 
  

  // Compute header for the reduced image
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
  
  // Calculate row size with fillings for input and reduced images
  fillings = (4 - (io_header.Width * 3) % 4) % 4; 
  rowSize = io_header.Width * 3 + fillings; 
  
  fillings = (4 - (reduced_header.Width * 3) % 4) % 4; 
  rowSize_reduced = reduced_header.Width * 3 + fillings; 

  // Reduce the image data
  for (i = 0; i < reduced_header.Height; i++) 
    for (j = 0; j < reduced_header.Width; j++) { 
      k = i * 2 * rowSize + j * 2 * 3; 
      k_reduced = i * rowSize_reduced + j * 3; 
      reduced_imageData[k_reduced] = io_imageData[k]; 
      reduced_imageData[k_reduced+1] = io_imageData[k+1]; 
      reduced_imageData[k_reduced+2] = io_imageData[k+2];
    }

  // Print the header of the reduced image
  printf(">>>> File header of the reduced image, %s:\n\n",
         strcat(strcat(strcpy(file_name, argv[1]), "_reduced"), ".bmp")); 
  print_header(reduced_header);
  printf("******************************************************************\n\n"); 
  // Write the reduced image to a file
  write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
  
    // Calculate header for the merged image
    aa.Type[0] = 'B'; 
    aa.Type[1] = 'M';
    aa.Size = io_header.Size; 
    for (i=0; i<4; i++) 
      aa.Reserved[i] = io_header.Reserved[i];
    aa.OffsetBits = io_header.OffsetBits; 
    aa.InfoSize = io_header.InfoSize; 
    aa.Width = ceil((float) io_header.Width + (s*3)); 
    aa.Height = ceil((float) io_header.Height + (s*3)); 
    aa.Planes = io_header.Planes;
    aa.BitPerPixel = io_header.BitPerPixel; 
    aa.Compression = io_header.Compression;
    aa.ImageSize = ceil((float) aa.Width * 3.0 / 4.0) * 4 * aa.Height;
    aa.Size = io_header.Size - io_header.ImageSize + aa.ImageSize;
    aa.XResolution = io_header.XResolution; 
    aa.YResolution = io_header.YResolution;
    aa.Colors = io_header.Colors;
    aa.ImportantColors = io_header.ImportantColors;
    
    // Allocate memory for merged image data
    f_imageData = (unsigned char *) malloc(aa.ImageSize);
    
    // Calculate row size with fillings for merged image
    fillings = (4 - (aa.Width * 3) % 4) % 4;
    int rowSize2;
    rowSize2 = aa.Width * 3 + fillings;

  // Copy reduced image data to the merged image
  for (i = 0; i < reduced_header.Height; i++) {
    for (j = 0; j < reduced_header.Width; j++) { 
      k_reduced = i * rowSize_reduced + j * 3; 
      k_1 = (i + aa.Height-s-reduced_header.Height) * rowSize2 + (aa.Width - 1 - j-s) * 3; 
      k_2 = (i + aa.Height-s-reduced_header.Height) * rowSize2 + (j+s) * 3; 
      k_3 = (aa.Height - 1 - i - s*2 - reduced_header.Height) * rowSize2 + (j+s) * 3; 
      k_4 = (aa.Height - 1 - i - s*2 - reduced_header.Height) * rowSize2 + (aa.Width - 1 - j-s) * 3; 
        f_imageData[k_1] = reduced_imageData[k_reduced]; 
        f_imageData[k_1+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_1+2] = reduced_imageData[k_reduced+2];
        f_imageData[k_2] = reduced_imageData[k_reduced]; 
        f_imageData[k_2+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_2+2] = reduced_imageData[k_reduced+2];
        f_imageData[k_3] = reduced_imageData[k_reduced]; 
        f_imageData[k_3+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_3+2] = reduced_imageData[k_reduced+2];
        f_imageData[k_4] = reduced_imageData[k_reduced]; 
        f_imageData[k_4+1] = reduced_imageData[k_reduced+1];
        f_imageData[k_4+2] = reduced_imageData[k_reduced+2];
    }
  }
    // Add frame to the merged image
    int r ,w ,q;
    for(i=0;i<s;i++)
    {
        for(j=0;j<aa.Width;j++)
        {
            r = i*rowSize2+j*3;
            w = (i+reduced_header.Height+s) * rowSize2 +j*3;
            q = (i+reduced_header.Height*2+s*2) * rowSize2 +j*3;
            f_imageData[r] = color[2]; 
            f_imageData[r+1] = color[1];
            f_imageData[r+2] = color[0];
            f_imageData[w] = color[2]; 
            f_imageData[w+1] = color[1];
            f_imageData[w+2] = color[0];
            f_imageData[q] = color[2]; 
            f_imageData[q+1] = color[1];
            f_imageData[q+2] = color[0];
        }
    }
    for(i=0;i<s;i++)
    {
        for(j=0;j<aa.Height;j++)
        {
            r = j*rowSize2 + i*3;
            w = j*rowSize2 + (i+s+reduced_header.Width)*3;
            q = j*rowSize2 + (i+s*2+reduced_header.Width*2)*3;
            f_imageData[r] = color[2]; 
            f_imageData[r+1] = color[1];
            f_imageData[r+2] = color[0];
            f_imageData[w] = color[2]; 
            f_imageData[w+1] = color[1];
            f_imageData[w+2] = color[0];
            f_imageData[q] = color[2]; 
            f_imageData[q+1] = color[1];
            f_imageData[q+2] = color[0];
        }
    }
  // Print the header of the merged image
  printf(">>>> File header of the merged image, %s:\n\n",
         strcat(strcat(strcpy(file_name, argv[1]), "_merged"), ".bmp"));
  print_header(aa);
  printf("******************************************************************\n\n");
  // Write the merged image to a file
  write_image_file(file_name, aa, io_palette, f_imageData);
  // Free allocated memory
  free(io_palette); 
  free(f_imageData);
  free(reduced_imageData);
  system("pause"); // Pause the console
  return 0;
}


