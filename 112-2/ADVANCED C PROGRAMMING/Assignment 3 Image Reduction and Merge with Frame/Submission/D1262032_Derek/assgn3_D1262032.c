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
    fwrite(palette, 1, header.OffsetBits-header.InfoSize-14, fptr);
    fwrite(imageData, 1, header.ImageSize, fptr);
    fclose(fptr);
}

int main(int argc, char *argv[]){
    Header io_header, reduced_header, merged_header;
    FILE *fptr;
    unsigned char *io_palette, *io_imageData, *reduced_imageData, *merged_imageData;
    char file_name[40];
    int rowSize, rowSize_reduced, rowSize_merged, fillings, i, j, k, k_reduced, k_1, k_2, k_3, k_4, size_frame, R, G, B; // R=red; G=green; B = blue;
    
    if (argc==1) {
        printf("Please enter an image file name without .bmp extension.\n");
        return 1;
    }
    else if (argc>2) {
        printf("Too many image file names entered. Input the an image file without .bmp extension.\n");
        return 1;
    }
    fptr = fopen(strcat(strcpy(file_name, argv[1]), ".bmp"), "rb");
    if(fptr==NULL){
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
    io_palette = (unsigned char *)malloc(io_header.OffsetBits-io_header.InfoSize-14);
    fread(io_palette, io_header.OffsetBits-io_header.InfoSize-14, 1, fptr);
    io_imageData = (unsigned char *)malloc(io_header.ImageSize);
    fread(io_imageData, io_header.ImageSize, 1, fptr);
    fclose(fptr);
    printf("Enter the size of frame in pixel (between 4 and 20): ");
    scanf("%d", &size_frame);
    printf("\n\nEnter RGB value of the frame color: ");
    scanf("%d%d%d", &R, &G, &B);
    printf("\n\n>>>> File header of the input image, %s:\n\n", strcat(strcpy(file_name, argv[1]), ".bmp"));
    print_header(io_header);
    printf("******************************************************************\n\n");
    reduced_header.Type[0] = 'B';
    reduced_header.Type[1] = 'M';
    reduced_header.Size = io_header.Size;
    for(i=0;i<4;i++) reduced_header.Reserved[i] = io_header.Reserved[i];
    reduced_header.OffsetBits = io_header.OffsetBits;
    reduced_header.InfoSize = io_header.InfoSize;
    reduced_header.Width = ceil((float) io_header.Width/2.0);
    reduced_header.Height = ceil((float) io_header.Height/2.0);
    reduced_header.Planes = io_header.Planes;
    reduced_header.BitPerPixel = io_header.BitPerPixel;
    reduced_header.Compression = io_header.Compression;
    fillings = (4-reduced_header.Width*3%4)%4;
    rowSize_reduced = reduced_header.Width*3+fillings;// The number of bytes in a row of the reduced image.
    reduced_header.ImageSize = rowSize_reduced*reduced_header.Height;
    reduced_header.Size = io_header.Size-io_header.ImageSize+reduced_header.ImageSize;
    reduced_header.XResolution = io_header.XResolution;
    reduced_header.YResolution = io_header.YResolution;
    reduced_header.Colors = io_header.Colors;
    reduced_header.ImportantColors = io_header.ImportantColors;
    reduced_imageData = (unsigned char *)malloc(reduced_header.ImageSize);
    fillings = (4-io_header.Width*3%4)%4;
    rowSize = io_header.Width*3+fillings;// The number of bytes in a row of the original image.
    // Copy even rows and even columns of the original input image data to the reduced image.
    for(i=0; i<reduced_header.Height; i++)
        for(j=0; j<reduced_header.Width; j++){
            k_reduced = i*rowSize_reduced+j*3;
            k = i*2*rowSize+j*2*3;
            reduced_imageData[k_reduced] = io_imageData[k];
            reduced_imageData[k_reduced+1] = io_imageData[k+1];
            reduced_imageData[k_reduced+2] = io_imageData[k+2];
        }
    printf(">>>> File header of the reduced image, %s:\n\n", strcat(strcpy(file_name, argv[1]), "_reduced.bmp"));
    print_header(reduced_header);
    printf("******************************************************************\n\n");
    write_image_file(file_name, reduced_header, io_palette, reduced_imageData);
    merged_header.Type[0] = 'B';
    merged_header.Type[1] = 'M';
    merged_header.Size = io_header.Size;
    for(i=0;i<4;i++) merged_header.Reserved[i] = io_header.Reserved[i];
    merged_header.OffsetBits = io_header.OffsetBits;
    merged_header.InfoSize = io_header.InfoSize;
    merged_header.Width = 2*reduced_header.Width+3*size_frame;
    merged_header.Height = 2*reduced_header.Height+3*size_frame;
    merged_header.Planes = io_header.Planes;
    merged_header.BitPerPixel = io_header.BitPerPixel;
    merged_header.Compression = io_header.Compression;
    fillings = (4-merged_header.Width*3%4)%4;
    rowSize_merged = merged_header.Width*3+fillings;
    merged_header.ImageSize = rowSize_merged*merged_header.Height;
    merged_header.Size = io_header.Size-io_header.ImageSize+merged_header.ImageSize;
    merged_header.XResolution = io_header.XResolution;
    merged_header.YResolution = io_header.YResolution;
    merged_header.Colors = io_header.Colors;
    merged_header.ImportantColors = io_header.ImportantColors;
    merged_imageData = (unsigned char *)malloc(merged_header.ImageSize);
    // Peform the merge operation.
    for(i=0; i<reduced_header.Height; i++){
        for(j=0; j<reduced_header.Width ;j++){
            k_reduced = i*rowSize_reduced+j*3;
            k_1 = (2*size_frame+i+io_header.Height/2)*rowSize_merged+(io_header.Width-j-1+2*size_frame)*3;
            k_2 = (2*size_frame+i+io_header.Height/2)*rowSize_merged+(j+size_frame)*3;
            k_3 = (reduced_header.Height-1-i+size_frame)*rowSize_merged+(j+size_frame)*3;
            k_4 = (reduced_header.Height-1-i+size_frame)*rowSize_merged+(io_header.Width-j-1+2*size_frame)*3;
            merged_imageData[k_1] = reduced_imageData[k_reduced];
            merged_imageData[k_1+1] = reduced_imageData[k_reduced+1];
            merged_imageData[k_1+2] = reduced_imageData[k_reduced+2];
            merged_imageData[k_2] = reduced_imageData[k_reduced];
            merged_imageData[k_2+1] = reduced_imageData[k_reduced+1];
            merged_imageData[k_2+2] = reduced_imageData[k_reduced+2];
            merged_imageData[k_3] = reduced_imageData[k_reduced];
            merged_imageData[k_3+1] = reduced_imageData[k_reduced+1];
            merged_imageData[k_3+2] = reduced_imageData[k_reduced+2];
            merged_imageData[k_4] = reduced_imageData[k_reduced];
            merged_imageData[k_4+1] = reduced_imageData[k_reduced+1];
            merged_imageData[k_4+2] = reduced_imageData[k_reduced+2];
        }
    }
    //Add the framed area
    for(i=0;i<merged_header.Height;i++){
        for(j=0;j<merged_header.Width;j++){
            k = i*rowSize_merged+j*3;
            if((i>=0 && i<size_frame) || (i>=size_frame+reduced_header.Height && i<2*size_frame+reduced_header.Height) || (i>=2*size_frame+2*reduced_header.Height && i<3*size_frame+2*reduced_header.Height) ||
               (j>=0 && j<size_frame) || (j>=size_frame+reduced_header.Width && j<2*size_frame+reduced_header.Width) || (j>=2*size_frame+2*reduced_header.Width && j<3*size_frame+2*reduced_header.Width)){
                merged_imageData[k] = B;
                merged_imageData[k+1] = G;
                merged_imageData[k+2] = R;}
        }
    }
    printf(">>>> File header of the merged image, %s:\n\n", strcat(strcpy(file_name, argv[1]), "_frame_merged.bmp"));
    print_header(merged_header);
    printf("******************************************************************\n\n");
    write_image_file(file_name, merged_header, io_palette, merged_imageData);
    free(io_palette);
    free(io_imageData);
    free(reduced_imageData);
    free(merged_imageData);
    system("pause");
    
    return 0;
}
