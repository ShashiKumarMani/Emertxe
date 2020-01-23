#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in case of RGB color image)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 * bpp is at offset 28, size is 2 bytes
 */
long get_image_size_for_bmp(EncodeInfo *encInfo)
{
    FILE *fptr_src_image = encInfo->fptr_src_image; // Copy to local var. Just to shorten the code
    uint width, height, size;
    unsigned short bpp;
    long img_size;

    //Seek to 34 byte return image size in bytes.

    // Seek to 18th byte
    fseek(fptr_src_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_src_image);
    
    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_src_image);

    // Get bits per pixel
    fseek(fptr_src_image, 28, SEEK_SET);
    fread(&bpp, sizeof(short), 1, fptr_src_image);

    // Store values in encInfo
    encInfo->width = width;
    encInfo->height = height;
    encInfo->bpp = bpp;


    //fseek(encInfo->fptr_src_image, 34, SEEK_SET);
    //fread(&size, sizeof(int), 1, encInfo->fptr_src_image);

    img_size = width * height * bpp / 8; // Calculate image size
    
    return img_size;
}

/* Description: Open files
 * Inputs: Source image filename, Secret filename and Stego Image file name
 * Output: FILE pointers for above files
 * Return Value:
 *  e_success - If all files are opened,
 *  e_failure - On file errors
 */
Status open_encode_files(EncodeInfo *encInfo)
{
    printf("INFO : Opening required files.\n");

    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "rb");
    //Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);
    	return e_failure;
    }

    printf("INFO : Opened Source file.\n");

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "rb");
    //Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
    	return e_failure;
    }

    printf("INFO : Secret file opened\n");

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "wb");
    //Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
    	return e_failure;
    }
    printf("INFO : Steg file opened\n");

    // All files opened, return e_success
    return e_success;
}
 

/*
    Check type of operation
    Input:Array of command line arguments
    Ouput:Integer indicating type of operation
*/
OperationType check_operation_type(char *argv[])
{
    //If first argument is encode
    if(strcmp(argv[1],"-e") == 0)
    {
	return e_encode;
    }	
    else if(strcmp(argv[1], "-d") == 0)
    {
	return e_decode;
    }
    else
    {
	return e_unsupported;
    }
}

/*
    Read and validate command line arguments.
    Input: Command line arguments, Structure pointer.
    Output: Validate args and return -e_success/e_failure.
 
*/
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    // Encoding - ./a.out -e beautiful.bmp secret.txt [steg.bmp]
    char *ptr = NULL, *str = NULL, arr[2];
    printf("INFO : Validating encode arguments...\n");

    //Input image
    if(argv[2])
    {
	encInfo->src_image_fname = argv[2];

	ptr = strchr(argv[2], '.');

	//If extension is not entered
	if(ptr == NULL)
	{
	    return e_failure;
	}

	//Check if file is bmp
	if(strcmp(".bmp", ptr) != 0)
	{
	    return e_failure;
	}
    }
    //If no arg
    else
    {
	return e_failure;
    }

    if(argv[3])
    {
	int i = 0;

	encInfo->secret_fname = argv[3];

	ptr = strchr(argv[3], '.');

	//Assuming file extn is always less than 4 bytes - given value
	for(i = 0;*(ptr + i) != '\0';i++)
	{
	    encInfo->extn_secret_file[i] = *(ptr + i);
	}
	
	//Extension length
	encInfo->extn_size = i;
    }
    else
    {
	return e_failure;
    }
    
    if(argv[4])
    {
	encInfo->stego_image_fname = argv[4];

        ptr = strchr(argv[4], '.');
 
        if(strcmp(".bmp", ptr) != 0)
	{
	    //If output file is not bmp
             return e_failure;
        }
	return e_success;

    }
    else
    {	
	//Default name assuming output file is always a bmp
	encInfo->stego_image_fname = "steg_def.bmp";
	return e_success;
    }

}

/*
   Check image capacity to hold secret file
   Input: Structure pointer
   Output: validate and return success/failure.
*/  
Status check_capacity(EncodeInfo *encInfo)
{
    printf("INFO : Checking image capacity.\n");

    //Find image size
    long image_size = get_image_size_for_bmp(encInfo);

    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    // If image size >= all_data * 8
    if(image_size >= ((strlen(MAGIC_STRING) + sizeof(encInfo->extn_size) + strlen(encInfo->extn_secret_file) + sizeof(encInfo->size_secret_file) + encInfo->size_secret_file + 2)* 8))
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }

}

/*
   Get secret file size
   Input: File pointer of secret file
   Output: Length of the file.
 */
uint get_file_size(FILE *fptr)
{
    char ch;
    uint count = 0;

    //Loop till EOF
    while((ch = fgetc(fptr)) != EOF)
    {
	count++;
    }

    return count;
}

/*
    Copy 54 bytes header to destination file.
    Input: File pointer to source and destination files.
    Output: Copy header and return success/failure.
 */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    printf("INFO : Encoding bmp header.\n");

    char ch[54];

    if(fseek(fptr_src_image, 0L, SEEK_SET) == -1 && fseek(fptr_dest_image, 0L, SEEK_SET) == -1)
    {
	return e_failure;
    }

    fread(ch, 54, 1, fptr_src_image);
    fwrite(ch, 54, 1, fptr_dest_image);

    return e_success;
}

/*
    Function to encode 1byte into lsb's of 8bytes
    Input: Data to be encoded, 8 byte image data.
    Output: The data is encoded into 8 bytes.
 */
Status encode_byte_to_lsb(char data, char *image_buffer)
{
    unsigned char mask = 1;

    //Loop through the bits of data and encode it in lsbs of image data
    for(int i = 0;i < 8;i++)
    {	
	//                                       clear lsb	
	image_buffer[i] = (data >> 7 - i) & 1 | (image_buffer[i] & ~mask);
    }
}

/*
    Encode magic string.
    Input: Magic string and structure pointer.
    Output: magic string is encoded. 
 */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    printf("INFO : Encoding magic string.\n");

    //If the source and dest file are not in same location
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_stego_image))
    {
	return e_failure;
    }

    //Encode magic string 
    for(int i = 0;i < (int)strlen(magic_string);i++)
    {
	//Read 8 bytes
	fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
	encode_byte_to_lsb(*(magic_string + i), encInfo->image_data);
	fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    }
    return e_success;
}
/*
    Encode secret file extension.
    Input: File extension, structure pointer.
    Output: Encode extn into destination file.
 */
Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    printf("INFO : Encoding secret file extension.\n");

     //If the source and dest file are not in same location
     if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_stego_image))
     {
         return e_failure;
     }

    //Encode extension length - max len - 255
    fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
    encode_byte_to_lsb((char)encInfo->extn_size, encInfo->image_data);
    fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);

    //Encode magic string 
    for(int i = 0;i < encInfo->extn_size;i++)
    {
        //Read 8 bytes
        fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
        encode_byte_to_lsb(*(file_extn + i), encInfo->image_data);
        fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    }

    return e_success;
}

/*
    Encode secret file size.
    Input: Long integer -file size, Structure pointer.
    Ouput: Encode file size and return e_success/e_failure.
 */
Status encode_secret_file_size(uint file_size, EncodeInfo *encInfo)
{
    printf("INFO : Encoding file size.\n");

    //If file is empty
    if(file_size <= 0)
    {
	printf("ERROR : File empty\n");
	return e_failure;
    }

    //Error
    char *ptr = (char *)&file_size;

    //If the source and dest file are not in same location
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_stego_image))
    {
        return e_failure;
    }

    for(int i = 0;i < (int)sizeof(int);i++)
    {
	fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
	encode_byte_to_lsb(*(ptr + i), encInfo->image_data);
	fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    }

    return e_success;
}

/*
    Encode secret file data into the destination image
Input : Structure pointer.
Output: Encode secret data into destination file and return e_success/e_failure.
 
 */
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    printf("INFO : Encoding secret file data.\n");

    char ch;
    fseek(encInfo->fptr_secret, 0L, SEEK_SET);

    //If the source and dest file are not in same location
    if(ftell(encInfo->fptr_src_image) != ftell(encInfo->fptr_stego_image))
    {
        return e_failure;
    }
    
    //Loop and encode file into destination file
    for(int i = 0;i < encInfo->size_secret_file;i++)
    {
	//Read char from secret file
	ch = fgetc(encInfo->fptr_secret);

	//Read byte 8 bytes from image, encode char, write to steg file
	fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
	encode_byte_to_lsb(ch, encInfo->image_data);
	fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    }

    return e_success;

}

Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image)
{

}

/*
    Copy remaing data into destination image
    Input : File pointers to source and destination images.
    Output: Copy remaining image data into destination image.

 */

Status copy_remaining_imag_data(FILE *fptr_src, FILE *fptr_dest)
{
    printf("INFO : Copying remainging image data.\n");

    long pres, end, i;
    char ch;

    //If the source and dest file are not in same location
    if(ftell(fptr_src) != ftell(fptr_dest))
    {
        return e_failure;
    }

    //Find the length of remaining bytes
    pres = ftell(fptr_src);

    fseek(fptr_src, 0L, SEEK_END);
    end = ftell(fptr_src);
    
    //Bring the pointer to the previous location
    fseek(fptr_src, pres, SEEK_SET);

    //Copy byte- from current pos to end
    for(i = pres;i < end;i++)
    {
	fread(&ch, 1, 1, fptr_src);
	fwrite(&ch, 1, 1, fptr_dest);
    }

    return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
    printf("INFO : Encoding started.\n");

    //Open files
    if(open_encode_files(encInfo) == e_success)
    {
	printf("INFO : Done. Open_files success\n");
    }
    else
    {
	printf("ERROR : Open_files failure\n");
	return e_failure;
    }	

    if(check_capacity(encInfo) == e_success)
    {
	printf("INFO : Image has capacity to hold secret data.\n");
    }
    else
    {
	printf("ERROR : Image capacity error\n");
	return e_failure;
    } 

    if(copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
    {
	printf("INFO : DONE. Header copied\n");
    }
    else
    {
	printf("ERROR : Copy image header\n");
	return e_failure;
    }

    if(encode_magic_string(MAGIC_STRING, encInfo) == e_success)
    {
	printf("INFO : Done. Magic String encoded\n");
    }
    else
    {
	printf("ERROR : Encode magic string\n");
	return e_failure;
    }

    if(encode_secret_file_extn(encInfo->extn_secret_file,  encInfo) == e_success)
    {
	printf("INFO : Done. Secret file extension encoded\n");
    }
    else
    {
	printf("ERROR : Secret file extension\n");
	return e_failure;
    }
    
    if(encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
    {
	printf("INFO : Done. Secret file size encoded\n");
    }
    else
    {
	printf("ERROR : Secret file size.\n");
	return e_failure;
    }

    if(encode_secret_file_data(encInfo) == e_success)
    {
	printf("INFO : Done. Secret file encoded\n");
	fclose(encInfo->fptr_secret);
    }
    else
    {
	printf("ERROR : Encode Secret file data\n");
	return e_failure;
    }

    if(copy_remaining_imag_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
    {
	printf("INFO : Done. Remaining data copied\n");
	fclose(encInfo->fptr_src_image);
	fclose(encInfo->fptr_stego_image);
    }
    else
    {
	printf("ERROR : Copy remaining data\n");
	return e_failure;
    }
}
