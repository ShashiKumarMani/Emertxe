/*
 
    StackOverflow
 */ 

#include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #pragma pack(1)

/*  The following is to access the DIB information
https://msdn.microsoft.com/en-us/library/cc230309.aspx
https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx
https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx */

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
}BITMAPFILEHEADER;

typedef struct
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
}BITMAPINFOHEADER;


typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
}RGBTRIPLE;

int main(void)
{
    char *infile = "beautiful.bmp";
    char *outfile = "testout.bmp";

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int i, j, k, biHeight;

    for(i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for(j = 0; j < bi.biWidth; j++)
        {
        RGBTRIPLE triple;

        fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
    }

    fseek(inptr, padding, SEEK_CUR);

    for(k = 0; k < padding; k++)
    {
        fputc(0x00, outptr);
    }

fclose(inptr);

fclose(outptr);

return 0;

}
