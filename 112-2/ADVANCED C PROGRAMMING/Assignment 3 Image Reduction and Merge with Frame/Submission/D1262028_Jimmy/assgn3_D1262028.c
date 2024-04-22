#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the Header structure for storing BMP file header information
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

// Function to print the image file header
void print_header(Header header) {
    printf("Type:             %c%c\n", header.Type[0], header.Type[1]);
    printf("Size:             %u\n", header.Size);
    printf("Reserved:         %c%c%c%c\n", header.Reserved[0], header.Reserved[1], header.Reserved[2], header.Reserved[3]);
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

// Function to write the image file
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

int main() {
    FILE *fptr;
    Header header;
    unsigned char *io_palette;
    unsigned char *io_imageData;
    unsigned char *reduced_imageData;
    int fillings;
    int reduced_fillings;
    int rowSize;
    int reduced_rowSize;
    int i, j;
    int frame_size;
    int frame_color[3];

    // User input: frame size and RGB color
    printf("Enter the size of frame in pixel (between 4 and 20): ");
    scanf("%d", &frame_size);
    printf("\nEnter RGB value of the frame color: ");
    scanf("%d %d %d", &frame_color[0], &frame_color[1], &frame_color[2]);
    
    // Read the BMP file
    fptr = fopen("abraham_lake.bmp", "rb");
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
    io_palette = (unsigned char *)malloc(header.OffsetBits - header.InfoSize - 14);
    fread(io_palette, header.OffsetBits - header.InfoSize - 14, 1, fptr);
    io_imageData = (unsigned char *)malloc(header.ImageSize);
    fread(io_imageData, header.ImageSize, 1, fptr);
    fclose(fptr);

    // Print original image header
    printf("\n>>>> File header of the input image, abraham_lake.bmp:\n\n");
    print_header(header);

    // Perform quarter reduction transformation
    Header reduced_header;
    reduced_header = header;
    reduced_header.Width = (reduced_header.Width + 1) / 2;
    reduced_header.Height = (reduced_header.Height + 1) / 2;
    reduced_header.ImageSize = reduced_header.Width * reduced_header.Height * 3;
    reduced_header.Size = reduced_header.ImageSize + header.OffsetBits;
    reduced_imageData = (unsigned char *)malloc(reduced_header.ImageSize);

	fillings = (4 - (header.Width * 3) % 4) % 4;
    reduced_fillings = (4 - (reduced_header.Width * 3) % 4) % 4;
    rowSize = header.Width * 3+fillings;
    reduced_rowSize =  reduced_header.Width * 3 + fillings;

    for (i = 0; i < reduced_header.Height; i++) {
        for (j = 0; j < reduced_header.Width; j++) {
            int k = i * 2 * rowSize + j * 2 * 3;
            reduced_imageData[i * reduced_header.Width * 3 + j * 3] = io_imageData[k];
            reduced_imageData[i * reduced_header.Width * 3 + j * 3 + 1] = io_imageData[k + 1];
            reduced_imageData[i * reduced_header.Width * 3 + j * 3 + 2] = io_imageData[k + 2];
        }
    }

    // Write reduced image to file
    write_image_file("abraham_lake_reduced.bmp", reduced_header, io_palette, reduced_imageData);
    fclose(fptr);

    // Perform frame merge transformation
    // Calculate merged image size and allocate memory
    Header merged_header;
    merged_header = header;
    merged_header.Width += 3 * frame_size;
    merged_header.Height += 3 * frame_size;
    fillings = (4 - (merged_header.Width * 3) % 4) % 4;
    merged_header.ImageSize = (merged_header.Width * 3 + fillings) * merged_header.Height;
    merged_header.Size = merged_header.ImageSize + header.OffsetBits;
    rowSize = merged_header.Width * 3 + fillings;
    unsigned char *merged_imageData = (unsigned char *)malloc(merged_header.ImageSize);

    // Fill merged image with frame color
    for (i = 0; i < merged_header.Height; i++) {
        for (j = 0; j < merged_header.Width; j++) {
        	int k = i * rowSize + j * 3;
        	int k2 = (i - frame_size * 2 - reduced_header.Height+ 1) * reduced_rowSize + (j - frame_size + 1) * 3;
        	int k1 = (i - frame_size * 2 - reduced_header.Height + 1) * reduced_rowSize + ((reduced_header.Width - 1) - (j - 2 * frame_size - reduced_header.Width)) * 3;
        	int k3 = ((reduced_header.Height - 1) - (i - frame_size)) * reduced_rowSize + (j - frame_size + 1) * 3;
        	int k4 = ((reduced_header.Height - 1) - (i - frame_size)) * reduced_rowSize + ((reduced_header.Width - 1) - (j - 2 * frame_size - reduced_header.Width)) * 3;
        	
            if(i > reduced_header.Height + frame_size * 2 - 1 && i < reduced_header.Height * 2 + frame_size * 2 - 1 && j > reduced_header.Width + frame_size * 2 - 1 && j < reduced_header.Width * 2 + frame_size * 2 - 1){//1st quadrant.
				merged_imageData[k] = reduced_imageData[k1];
			    merged_imageData[k + 1] = reduced_imageData[k1 + 1];
			    merged_imageData[k + 2] = reduced_imageData[k1 + 2];
			}
			else if(i > reduced_header.Height + frame_size * 2 - 1 && i < reduced_header.Height * 2 + frame_size * 2 - 1 && j > frame_size - 1 && j < reduced_header.Width + frame_size - 1){//2nd quadrant.
			    merged_imageData[k] = reduced_imageData[k2];
			    merged_imageData[k + 1] = reduced_imageData[k2 + 1];
			    merged_imageData[k + 2] = reduced_imageData[k2 + 2];
			}
			else if(i > frame_size - 1 && i < reduced_header.Height + frame_size - 1 && j > frame_size - 1 && j < reduced_header.Width + frame_size - 1){//3rd quadrant.
			    merged_imageData[k] = reduced_imageData[k3];
			    merged_imageData[k + 1] = reduced_imageData[k3 + 1];
			    merged_imageData[k + 2] = reduced_imageData[k3 + 2];
			}
			else if(i > frame_size - 1 && i < reduced_header.Height + frame_size - 1 && j > reduced_header.Width + frame_size * 2 - 1 && j < reduced_header.Width * 2 + frame_size * 2 - 1){//4th quadrant.
				merged_imageData[k] = reduced_imageData[k4];
			    merged_imageData[k + 1] = reduced_imageData[k4 + 1];
			    merged_imageData[k + 2] = reduced_imageData[k4 + 2];
			}
			else{//Print the frame.
			    merged_imageData[k] = frame_color[2];
			    merged_imageData[k + 1] = frame_color[1];
			    merged_imageData[k + 2] = frame_color[0];
			}
        }
    }

    // Write merged image to file
    write_image_file("abraham_lake_frame_merged.bmp", merged_header, io_palette, merged_imageData);
    printf("******************************************************************\n");
    // Print reduced image header
    printf("\n>>>> File header of the reduced image, abraham_lake_reduced.bmp:\n\n");
    print_header(reduced_header);
    printf("******************************************************************\n");
    // Print merged image header
    printf("\n>>>> File header of the frame merged image, abraham_lake_frame_merged.bmp:\n\n");
    print_header(merged_header);
    printf("******************************************************************\n");
    // Free allocated memory
    free(io_palette);
    free(io_imageData);
    free(reduced_imageData);
    free(merged_imageData);

    return 0;
}

