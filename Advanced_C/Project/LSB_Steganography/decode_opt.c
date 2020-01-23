#include <stdio.h>
#include <string.h>
#include "decode.h"
#include "types.h"
#include "common.h"

/* Description: Open files
 * Inputs: Stego image filename, Output filename 
 * Output: FILE pointers for above files
 * Return Value:
 *  e_success - If all files are opened,
 *  e_failure - On file errors
 */
Status open_decode_files(EncodeInfo *encInfo)
{
    printf("INFO : Opening files.\n");
    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "rb");
    //Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
    	return e_failure;
    }

    printf("INFO : Steg file opened\n");
    
    return e_success;
}

/*
    Validate decode arguments.
    Input: Command line arguments, Structure ponter
    Output: validate arguments, and return e_success/e_failure.
 */
Status read_and_validate_decode_args(char *argv[], EncodeInfo *encInfo)
{
    // Encoding - ./a.out -e beautiful.bmp secret.txt [steg.bmp]
    char *ptr = NULL, *str = NULL;

    printf("INFO : Validating decode arguments...\n");

    //Cla[2]
    if(argv[2])
    {
	encInfo->stego_image_fname = argv[2];

	//Check if source file is bmp
	ptr = strchr(argv[2], '.');

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
    return e_success;
    
}

/*
    Decode 8 bits from image buffer and store it in data
    Input: 8byte image data.
    Output: Decoded byte.
 */
char decode_byte_from_lsb(char *image_buffer)
{
    char data = 0;

    for(int i = 0;i < 8;i++)
    {
	data |= (image_buffer[i] & 1) << 7 - i;
    }
    return data;
}

/*
   Decode magic string
   Input: Magic string, Structure pointer.
   Output: Decode magic string, and return e_success/e_failure.

*/
Status decode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
    printf("INFO : Decoding magic string.\n");

    //Assuming maxlen of magic string is 50
    char magic_buff[50] = {0}, ch;

    //Point to the 55th byte, orig and steg
    fseek(encInfo->fptr_stego_image, 54, SEEK_SET);

    int i = 0;

    //Decode bytes till the null of magic string is read
    while(i < (int)strlen(magic_string))
    {
	fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
	ch = decode_byte_from_lsb(encInfo->image_data);
	magic_buff[i] = ch;
	i++;
    }
    magic_buff[i] = '\0';

    //Compare decoded magic string with the encoded magic string
    if(strcmp(magic_string, magic_buff) == 0)
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
}

/*
    Decode secret file extension.
    Input: Structure pointer.
    output: Secret file extension is decoded.
 */
Status decode_secret_file_extn(EncodeInfo *encInfo)
{
    printf("INFO : Decoding file extension.\n");

    int i;

    //Decode extn length - 1 byte
    fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    encInfo->extn_size = decode_byte_from_lsb(encInfo->image_data);

    //Decode secret file extension
    for(i = 0;i < encInfo->extn_size;i++)
    {
        fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
        encInfo->extn_secret_file[i] = decode_byte_from_lsb(encInfo->image_data);
    }
    encInfo->extn_secret_file[i] = '\0';

    return e_success;
}

/*
    Validate the output file (after the file extension is decoded.

 */
Status open_output_file(char *argv[], EncodeInfo *encInfo)
{
    printf("INFO : Validating output file.\n");

    char *ptr = NULL;

    if(argv[3])
    {
	encInfo->secret_fname = argv[3];
	ptr = strchr(encInfo->secret_fname, '.');

	//If extension is not provided add decoded extension
	if(ptr == NULL)
	{
	    strcat(encInfo->secret_fname, encInfo->extn_secret_file);
	}
	//If extension are not same change extension
	else if(strcmp(encInfo->extn_secret_file, ptr) != 0)
	{
	    strtok(encInfo->secret_fname, ".");
	    strcat(encInfo->secret_fname, encInfo->extn_secret_file);
	}
    }
    //Create default file of the decoded extension if file not provided
    else
    {
	printf("INFO : Output file not entered, creating file named default with decoded extension.\n");

	char arr[15] = "default";
	strcat(arr, encInfo->extn_secret_file);

	encInfo->secret_fname = arr;
    }

    //Open Output file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "wb");
    
    if(encInfo->fptr_secret == NULL)
    {
	printf("ERROR : Opening output file.\n");
	return e_failure;
    }

    return e_success;
}

/*
    Decode secret file size.
    Input: Structure pointer.
    Output: File extension is decoded.
 
 */
Status decode_secret_file_size(EncodeInfo *encInfo)
{
    printf("INFO : Decoding secret file size.\n");

    uint size = 0;
    uint temp = 0;

    //Decode long int from image    
    for(int i = 0;i < (int)sizeof(int);i++)
    {
	temp = 0;
	fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
	temp = decode_byte_from_lsb(encInfo->image_data);
	//Shift 8 and OR
	size |= (temp << 8 * i);
    }
    
    encInfo->size_secret_file = size;

    return e_success;
}

/*
    Decode secret file data
    Input: Structure pointer.
    Output: Secret file size is decoded and stored in structure.
 */
Status decode_secret_file_data(EncodeInfo *encInfo)
{
    printf("INFO : Decoding secret file data.\n");
    char ch;
    
    for(int i = 0;i < encInfo->size_secret_file;i++)
    {
	//Read byte 8 bytes from image, encode char, write to steg file
	fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
	ch = decode_byte_from_lsb(encInfo->image_data);
	fwrite(&ch, 1, 1, encInfo->fptr_secret);
    }

    return e_success;
}

/*
    Main decoding function.
    Input: Structure pointer.
    Output: All decoding function are called.
 */
Status do_decoding(char *argv[], EncodeInfo *encInfo)
{
    printf("INFO : Decoding started. \n");

    //Open files
    if(open_decode_files(encInfo) == e_success)
    {
	printf("INFO : Done. Open_files success\n");
    }
    else
    {
	printf("ERROR : Open_files failure\n");
	return e_failure;
    }	

    if(decode_magic_string(MAGIC_STRING, encInfo) == e_success)
    {
	printf("INFO : Done. Magic String match\n");
    }
    else
    {
	printf("ERROR : Magic String doesnt match\n");
	return e_failure;
    }

    if(decode_secret_file_extn(encInfo) == e_success)
    {
	printf("INFO : Done. Secret file extension decoded\n");
    }
    else
    {
	printf("ERROR : Secret file extensions doesnt match\n");
	return e_failure;
    }
    
    if(open_output_file(argv, encInfo) == e_success)
    {
	printf("INFO : Done. Output file opened.\n");
    }
    else
    {
	printf("ERROR : Opening output file.\n");
	return e_failure;
    }

    if(decode_secret_file_size(encInfo) == e_success)
    {
	printf("INFO : Done. Secret file size encoded\n");
    }
    else
    {
	printf("ERROR : Secret file size.\n");
	return e_failure;
    }

    if(decode_secret_file_data(encInfo) == e_success)
    {
	printf("INFO : Done. Secret file encoded\n");
	fclose(encInfo->fptr_stego_image);
	fclose(encInfo->fptr_secret);
    }
    else
    {
	printf("ERROR : Secret file data\n");
	return e_failure;
    }

    return e_success;
}
