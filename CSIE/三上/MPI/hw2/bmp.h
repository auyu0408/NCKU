typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef int LONG;
 
#pragma pack( push, 1 )                     //struct alignment§K BMPHEADER ³Qsizeof Ū¦¨16 
typedef struct tagBITMAPFILEHEADER {        //(14bytes)
        WORD bfType;                        //(2bytes)         File type, in BMP case, it¡¦ll be ¡¥BM¡¦(0x424D)
        DWORD bfSize;                       //(4bytes)        BMP file size
        WORD bfReserved1;                   //(2bytes)        Always 0
        WORD bfReserved2;                   //(2bytes)        Always 0
        DWORD bfOffbytes;                   //(4bytes)        Size of Headers + Palette, 14 + 40 + 4 * 28 in our case
} BMPHEADER; 
#pragma pack( pop )
 
typedef struct tagBITMAPINFOHEADER{         //(40bytes)
        DWORD biSize;                       //(4bytes)        After Windows 3.X, it¡¦s always 40, which is the structure size of BITMAPINFOHEADER
        LONG biWidth;                       //(4bytes)        The width of image
        LONG biHeight;                      //(4bytes)        The height of image
        WORD biPlanes;                      //(2bytes)        How many images in this file. For BMP, it¡¦s  always 1
        WORD biBitCount;                    //(2bytes)        How many bits stand for a pixel, 8 in our case
        DWORD biCompression;                //(4bytes)        0 is no compression, 1 is 8-bitRLE compression, 2 is 4-bitRLE compression.
                                            //        We only deal with no compression image.
        DWORD biSizeImage;                  //(4bytes)         The image size after compress. If no compression, it could be 0 or image size
        LONG biXPelsPerMeter;               //(4bytes)        horizontal dots per meter
        LONG biYPelsPerMeter;               //(4bytes)        vertical dots per meter 
        DWORD biClrUsed;                    //(4bytes)        How many colors used in palette, 0 for all colors
        DWORD biClrImportant;               //(4bytes)        How many colors are important, 0 for all
} BMPINFO; 
 
typedef struct tagRGBTRIPLE{                //(3bytes)
        BYTE rgbBlue;                       //(1bytes)        blue channel
        BYTE rgbGreen;                      //(1bytes)        green channel
        BYTE rgbRed;                        //(1bytes)        red channel
} RGBTRIPLE; 
