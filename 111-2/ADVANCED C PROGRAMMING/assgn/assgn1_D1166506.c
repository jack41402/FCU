    /* This program reads a bitmap image file. It performs horizontal mirror relfection transformation. */
    #include <stdio.h>
    #include <stdlib.h>
    #define swap(a , b) temp=a ; a=b ; b=temp

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


int main(int argc, char *argv[])
{
    FILE *fptr; // File pointer
    Header	header; // Bitmap file header
    unsigned char	*palette; // Pointer: palette.
    unsigned char	*imageData; // Pointer: Image pixel data.
    unsigned char	*newImage ;
    int rowSize; // Number of bytes in a row.
    int fillings; // Number of bytes of padding 0's.
//    int i, j; // Loop variable.
    int k_low , k_up; // Index of the upper-half pixel.
    int rotate , newFillings , newRowSize , now , RotateNow ;
    unsigned int temp , a , b ; // Temporary memory for pixel swapping.

    if (argc==1)
    { // One argument in the command line. This argument must "image_horizontal_mirror_reflection", the executable code.
        printf("Please enter the image file name.\n");
        system("pause");
        return 1;
    }
    else if (argc>2)
    { // If the command has more than three strings, too many arguments are entered.
        printf("Too many image file names entered.\n");
        system("pause");
        return 1;
    }

    // The input command has two or three strings, the 2nd one is the name of the input file.
    fptr = fopen(argv[1], "rb"); // Open the input file using binary mode.
    if (fptr==NULL)
    { // If the file pointer is empty, it means the file does not exist.
        printf("File %s does not exist.\n", argv[1]); // Print error message.
        return 1; // Terminate the program.
    }

    // Input the colored image file.
    fread(&header.Type, 1, 2, fptr); // Two fixed characters, "BM".
    fread(&header.Size, 4, 1, fptr); // File size in bytes.
    fread(&header.Reserved, 1, 4, fptr); // Reserved field.
    fread(&header.OffsetBits, 4, 1, fptr); // Offset.
    fread(&header.InfoSize, 4, 1, fptr); // Information size in byte.
    fread(&header.Width, 4, 1, fptr); // Image width in pixel.
    fread(&header.Height, 4, 1, fptr); // Image height in pixel.
    fread(&header.Planes, 2, 1, fptr); // Number of image planes in the image, must be 1.
    fread(&header.BitPerPixel, 2, 1, fptr); // Number of bits used to represent the data for each pixel.
    fread(&header.Compression, 4, 1, fptr); // Value indicating what type of compression.
    fread(&header.ImageSize, 4, 1, fptr); // Size of the actual pixel data, in bytes.
    fread(&header.XResolution, 4, 1, fptr); // Preferred horizontal resolution of the image, in pixels per meter.
    fread(&header.YResolution, 4, 1, fptr); // Preferred vertical resolution of the image, in pixels per meter.
    fread(&header.Colors, 4, 1, fptr); // Value is zero except for indexed images using fewer than the maximum number of colors.
    fread(&header.ImportantColors, 4, 1, fptr); // Number of colors that are considered important when rendering the image.

    palette = (unsigned char *) malloc(header.OffsetBits - header.InfoSize - 14); // Allocate memory space for the palette.
    fread(palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);  // Read palette from the image file.

    imageData = (unsigned char *) malloc(header.ImageSize); // Allocate memory space for image pixel data.
    fread(imageData, header.ImageSize, 1, fptr); // Read image pixel data from the image file.

    fclose(fptr); // Close the input file.

    do
    {
        printf ("Enter the level of rotation(0~3): ") ;
        scanf ("%d" , &rotate) ;
    }
    while (rotate<0 || rotate>3) ;

    fillings = (4 - (header.Width * 3) % 4) % 4 ; // The number of filling bytes at the end of a row.
    rowSize = header.Width * 3 + fillings ; // The number of bytes in a row.
    if (rotate&1)
    {
        newFillings = (4 - (header.Height * 3) % 4) % 4 ;
        newRowSize = header.Height * 3 + newFillings ;
        header.ImageSize = newRowSize * header.Width ;
        newImage = (unsigned char *) malloc(header.ImageSize) ;
        header.Size = header.ImageSize + header.OffsetBits ;
        swap (header.Height , header.Width) ;
//        swap (header.XResolution , header.YResolution) ;
    }
    else if (rotate==2)
    {
        newRowSize = rowSize ;
        newImage = (unsigned char *) malloc(header.ImageSize) ;
    }

    switch (rotate)
    {
        // Rotate 90 degrees
        case 1 :
        {
            for (int i=0 ; i<header.Width ; ++i)
            {
                for (int j=0 ; j<header.Height ; ++j)
                {
                    now = i * rowSize + j * 3 ;
                    RotateNow = (header.Height - j - 1) * newRowSize + i * 3 ;
                    newImage[RotateNow] = imageData[now] ;
                    newImage[RotateNow+1] = imageData[now+1] ;
                    newImage[RotateNow+2] = imageData[now+2] ;
                }
            }
            break ;
        }
        // Rotate 180 degrees
        case 2 :
        {
            for (int i=header.Height-1 ; i>=0 ; --i)
            {
                for (int j=header.Width-1 ; j>=0 ; --j)
                {
                    now = i * rowSize + j * 3 ;
                    RotateNow = (header.Height - 1 - i) * newRowSize + (header.Width - 1 - j) * 3 ;
                    newImage[RotateNow] = imageData[now] ;
                    newImage[RotateNow+1] = imageData[now+1] ;
                    newImage[RotateNow+2] = imageData[now+2] ;
                }
            }
            break ;
        }
        // Rotate 270 degrees
        case 3 :
        {
            for (int i=0 ; i<header.Width ; ++i)
            {
                for (int j=0 ; j<header.Height ; ++j)
                {
                    now = i * rowSize + j * 3 ;
                    RotateNow = j * newRowSize + (header.Width - i - 1) * 3 ;
                    newImage[RotateNow] = imageData[now] ;
                    newImage[RotateNow+1] = imageData[now+1] ;
                    newImage[RotateNow+2] = imageData[now+2] ;
                }
            }
            break ;
        }
        // Rotate 0 degree
        default :
        {
            newImage = imageData ;
            break ;
        }
    }


    // Default output file name.
    fptr = fopen("rotation_image.bmp", "wb"); // Open the output file using binary mode.
    printf("\nThe rotation image is \"rotation_image.bmp\".\n\n"); // Print the output file name message.

    // Output the horizontal mirror reflection image file.
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
    fwrite(newImage, 1, header.ImageSize, fptr); // Write the image pixel data.
    fclose(fptr); // Close the output file.

    // Print the horizontal mirror reflection image file head.
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
    /* End of output commands */

    free(palette); // Release memory space of palette.
    free(imageData); // Release memory space of image pixel data.
    if (rotate) free(newImage) ;
    return 0;
}
