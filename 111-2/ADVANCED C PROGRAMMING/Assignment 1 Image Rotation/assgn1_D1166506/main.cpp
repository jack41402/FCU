#include <stdio.h>
#include <stdlib.h>
#define swap(a , b) temp=b ; b=a ; a=temp ;


typedef struct
{
    char Type[2] ;
    unsigned Size ;
    char Reserved[4] ;
    unsigned OffsetBits ;
    unsigned InfoSize ;
    unsigned Width ;
    unsigned Height ;
    unsigned short Planes ;
    unsigned short BitPerPixel ;
    unsigned Compression ;
    unsigned ImageSize ;
    unsigned XResolution ;
    unsigned YResolution ;
    unsigned Colors ;
    unsigned ImportantColors ;
} Header ;

void WriteFile (char *filename , Header header , unsigned char *palette , unsigned char *imageData)
{
    FILE *fptr ;
    fptr = fopen("Rotate_Image.bmp" , "wb") ;
    printf("\nThe horizontal mirror reflection image is \"horizontal_mirror_reflection.bmp\".\n\n") ;
    fwrite(&header.Type , 1 , 2 , fptr) ;
    fwrite(&header , 4 , 1 , fptr) ;
    fwrite(palette , 1 , header.OffsetBits - header.InfoSize - 14 , fptr) ;
    fwrite(imageData , 1 , header.ImageSize , fptr) ;
    fclose(fptr) ;
}

int main(int argc , char *argv[])
{
    FILE *fptr ;
    Header header ;
    unsigned char *palette ;
    unsigned char *imageData , *RotateImage ;
    int rotate ;
    int rowSize , RotateRowSize ;
    int fillings , RotateFillings ;
    int k_low , k_up ;
    unsigned int temp , now , RotateNow ;

    if (argc==1)
    {
        printf("Please enter the image file name.\n") ;
        system("pause") ;
        return 1 ;
    }
    else if (argc>3)
    {
        printf("Too many image file names entered.\n") ;
        system("pause") ;
        return 1 ;
    }
    
    fptr = fopen(argv[1] , "rb") ;
    if (fptr==NULL)
    {
        printf("File %s does not exist.\n" , argv[1]) ;
        return 1 ;
    }

    scanf ("%d" , &rotate) ;

    fread(&header.Type , 1 , 2 , fptr) ;
    fread(&header.Size , 4 , 1 , fptr) ;
    fread(&header.Reserved , 1 , 4 , fptr) ;
    fread(&header.OffsetBits , 4 , 1 , fptr) ;
    fread(&header.InfoSize , 4 , 1 , fptr) ;
    fread(&header.Width , 4 , 1 , fptr) ;
    fread(&header.Height , 4 , 1 , fptr) ;
    fread(&header.Planes , 2 , 1 , fptr) ;
    fread(&header.BitPerPixel , 2 , 1 , fptr) ;
    fread(&header.Compression , 4 , 1 , fptr) ;
    fread(&header.ImageSize , 4 , 1 , fptr) ;
    fread(&header.XResolution , 4 , 1 , fptr) ;
    fread(&header.YResolution , 4 , 1 , fptr) ;
    fread(&header.Colors , 4 , 1 , fptr) ;
    fread(&header.ImportantColors , 4 , 1 , fptr) ;


    palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14) ;
    fread(palette , header.OffsetBits - header.InfoSize - 14 , 1 , fptr) ;

    imageData = (unsigned char *) malloc(header.ImageSize) ;
    fread(imageData , header.ImageSize , 1 , fptr) ;

    fclose(fptr) ;

    if (rotate==1 || rotate==3)
    {
        fillings = (4 - (header.Width * 3) % 4) % 4 ;
        RotateFillings = (4 - (header.Height * 3) % 4) % 4 ;
        rowSize = header.Width * 3 + fillings ;
        RotateRowSize = header.Height * 3 + RotateFillings ;
        RotateImage = (unsigned char *) malloc(RotateRowSize*header.Height) ;
        printf ("%d" , RotateRowSize*header.Width) ;
    }
    else if (rotate==2)
    {
        fillings = (4 - (header.Width * 3) % 4) % 4 ;
        rowSize = header.Width * 3 + fillings ;
    }
    switch (0<=rotate && rotate<=3)
    {
        case (1) :
        {
            for (int i=0 ; i<header.Height ; ++i)
            {
                for (int j=0 ; j<header.Width ; ++j)
                {
                    now = i * rowSize + j * 3 ;
                    RotateNow = (header.Width - j) * RotateRowSize + i * 3 ;
                    RotateImage[RotateNow] = imageData[now] ;
                    RotateImage[RotateNow+1] = imageData[now+1] ;
                    RotateImage[RotateNow+2] = imageData[now+2] ;
                }
            }
            break ;
        }
        case (2) :
        {
            for (int i=0 ; i<header.Height / 2 ; ++i)
            {
                for (int j=0 ; j<header.Width ; j++)
                {
                    k_low = i * rowSize + j * 3 ;
                    k_up = (header.Height - 1 - i) * rowSize + j * 3 ;
                    swap (imageData[k_low] , imageData[k_up]) ;
                    swap (imageData[k_low+1] , imageData[k_up+1]) ;
                    swap (imageData[k_low+2] , imageData[k_up+2]) ;
                }
            }
            break ;
        }
        case (3) :
        {
            for (int i=0 ; i<header.Height ; ++i)
            {
                for (int j=0 ; j<header.Width ; j++)
                {
                    now = i * rowSize + j * 3 ;
                    RotateNow = (header.Height - j) * RotateRowSize + i * 3 ;
                    RotateImage[RotateNow] = imageData[now] ;
                    RotateImage[RotateNow+1] = imageData[now+1] ;
                    RotateImage[RotateNow+2] = imageData[now+2] ;
                }
            }
            break ;
        }
        // Remember to test the case '0'
    }

    if (rotate==1 || rotate==3) swap (header.Width , header.Height) ;
    WriteFile ("RotateImage.bmp" , header , palette , imageData) ;

    printf("Type:             %c%c\n" , header.Type[0] , header.Type[1]) ;
    printf("Size:             %u\n" , header.Size) ;
    printf("Resserved:        %c%c%c%c\n" , header.Reserved[0] , header.Reserved[1] , header.Reserved[2] , header.Reserved[3]) ;
    printf("OffsetBits:       %u\n" , header.OffsetBits) ;
    printf("InfoSize:         %u\n" , header.InfoSize) ;
    printf("Width:            %u\n" , header.Width) ;
    printf("Height:           %u\n" , header.Height) ;
    printf("Planes:           %d\n" , header.Planes) ;
    printf("BitPerPixel:      %d\n" , header.BitPerPixel) ;
    printf("Compression:      %u\n" , header.Compression) ;
    printf("ImageSize:        %u\n" , header.ImageSize) ;
    printf("XResolution:      %u\n" , header.XResolution) ;
    printf("YResolution:      %u\n" , header.YResolution) ;
    printf("Colors:           %u\n" , header.Colors) ;
    printf("ImportantColors:  %u\n" , header.ImportantColors) ;

    free(palette) ;
    free(imageData) ;
    return 0 ;
}
