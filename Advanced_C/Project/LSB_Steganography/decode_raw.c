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
#if 1
    //printf("%s\n", encInfo->secret_fname);
    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "wb");
    //Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
    	return e_failure;
    }

    printf("INFO : Output file opened\n");
#endif
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

    printf("Validating decode arguments...\n");

    //Cla[2]
    if(argv[2])
    {
//	printf("argv[2] - %s\n", argv[2]);

	encInfo->stego_image_fname = argv[2];

	//Check if source file is bmp
	ptr = strchr(argv[2], '.');

//	printf("extension is %s\n", ptr);

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
#if 1
    //Assuming the decoded extn and cla extn are same
    if(argv[3])
    {
//	printf("argv[3] - %s\n", argv[3]);
	encInfo->secret_fname = argv[3];

	ptr = strchr(argv[3], '.');

	//ptr == NULL if extension is not given

//	if(ptr != NULL)
  //  	    printf("The file extension is %s\nThe program will terminate if the decoded extension is different\n", ptr);


    }
    //Default - .txt extn
    else
    {
	encInfo->secret_fname = "output.txt";
	printf("INFO : Output file not entered,default file with decoded extension will be created.\n");
    }
#endif
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

    //printf("Decoded %d\n", data);
    
    return data;
}

/*
   Decode magic string
   Input: Magic string, Structure pointer.
   Output: Decode magic string, and return e_success/e_failure.

*/
Status decode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
  //  printf("============Decode magic string ================\n");

    //printf("magic! = %s\n", magic_string);
    //Assuming maxlen of magic string is 50
    char magic_buff[50] = {0}, ch;

    //printf("---fptr_stego - %ld\n", ftell(encInfo->fptr_stego_image));

    //Point to the 55th byte, orig and steg
    fseek(encInfo->fptr_stego_image, 54, SEEK_SET);

    //printf("----fptr_stego - %ld\n", ftell(encInfo->fptr_stego_image));
    //fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);

    int i = 0;

    //Decode bytes till the null of magic string is read
    //while((ch = decode_byte_from_lsb(encInfo->image_data)) != 0)
    while(i < (int)strlen(magic_string))
    {
	fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
	ch = decode_byte_from_lsb(encInfo->image_data);
	magic_buff[i] = ch;
	i++;
    }
    magic_buff[i] = '\0';

    printf("INFO : Magic string decoded.\n");

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
    //printf("============Decode secret file extn===============\n");

    //printf("----fptr_stego - %ld\n", ftell(encInfo->fptr_stego_image));

    int i;

    //Decode extn length - 1 byte
    fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    encInfo->extn_size = decode_byte_from_lsb(encInfo->image_data);

    //printf("Decoded extn size - %d\n", encInfo->extn_size);

    //Decode secret file extension
    for(i = 0;i < encInfo->extn_size;i++)
    {
	//printf("i = %d\n", i);
        fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
        encInfo->extn_secret_file[i] = decode_byte_from_lsb(encInfo->image_data);
    }
    encInfo->extn_secret_file[i] = '\0';

    //printf("The decoded file extension - %s \n", encInfo->extn_secret_file);

    //printf("The output file - %s\n", encInfo->secret_fname);

    char *ptr = strchr(encInfo->secret_fname, '.');
    
//    if(ptr == NULL)
//	printf("The output file - %s\n", encInfo->secret_fname);

    //If file extn is not given
    if(ptr == NULL)
    {
	printf("INFO : The entered file doesnt have an extension, adding the decoded extension.\n");
	encInfo->secret_fname = strcat(encInfo->secret_fname, encInfo->extn_secret_file);
	//Close old file
	fclose(encInfo->fptr_secret);
	encInfo->fptr_secret = fopen(encInfo->secret_fname, "wb");
	if(encInfo->fptr_secret == NULL)
	{
	    printf("ERROR : New file open error\n");
	    return e_failure;
	}

    }
    //If decoded file etn and the entered file extn are different
    else if(strcmp(encInfo->extn_secret_file, ptr) != 0)
    {
	char arr[15] = "default";
	printf("INFO : The decoded file extension and the cla file extension doesnt match. Opening a default file of the decoded extension.\n");
	strcat(arr, encInfo->extn_secret_file);

	encInfo->secret_fname = arr;
	//Close the old file
	fclose(encInfo->fptr_secret);

	//Open default file and error check
	encInfo->fptr_secret = fopen(arr, "wb");
	if(encInfo->fptr_secret == NULL)
	{
	    printf("Default secret file open error\n");
	    return e_failure;
	}
	return e_success;
    }

    //printf("----fptr_stego - %ld\n", ftell(encInfo->fptr_stego_image));
    
    return e_success;
}

Status open_output_file(char *argv[], EncodeInfo *encInfo)
{

}
/*
    Decode secret file size.
    Input: Structure pointer.
    Output: File extension is decoded.
 
 */
Status decode_secret_file_size(EncodeInfo *encInfo)
{
//    printf("========Decode secret file size==============\n");

    //fseek(encInfo->fptr_stego_image, 118L, SEEK_SET);
  //  printf("----fptr_steg- %ld\n", ftell(encInfo->fptr_stego_image));

    long int size = 0;
    unsigned long int temp = 0;
    
    for(int i = 0;i < (int)sizeof(long);i++)
    {
	temp = 0;
	fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
	temp = decode_byte_from_lsb(encInfo->image_data);
	//printf("%d - %ld\n", i, temp);
	size |= (temp << 8 * i);
    }
    
    encInfo->size_secret_file = size;

    //printf("The decoded file size - %ld\n", size);
   // printf("----fptr_steg- %ld\n", ftell(encInfo->fptr_stego_image));

    printf("INFO : The file size decoding done.\n");

    return e_success;
}

/*
    Decode secret file data
    Input: Structure pointer.
    Output: Secret file size is decoded and stored in structure.
 */
Status decode_secret_file_data(EncodeInfo *encInfo)
{
//    printf("==========Decode secret file data============\n");
    
    char ch;
    
  //  printf("----fptr_steg- %ld\n", ftell(encInfo->fptr_stego_image));

    for(int i = 0;i < encInfo->size_secret_file;i++)
    {
	//Read byte 8 bytes from image, encode char, write to steg file
	fread(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
	ch = decode_byte_from_lsb(encInfo->image_data);
//	printf("i - %d : %c\n", i, ch);
	fwrite(&ch, 1, 1, encInfo->fptr_secret);
    }

  //  printf("----fptr_steg- %ld\n", ftell(encInfo->fptr_stego_image));
    
    printf("INFO : Decoding file data done.\n");

    return e_success;

}

/*
    Main decoding function.
    Input: Structure pointer.
    Output: All decoding function are called.
 */
Status do_decoding(EncodeInfo *encInfo)
{
    printf("INFO : Decoding started. \n");

    //Open files
    if(open_decode_files(encInfo) == e_success)
    {
	printf("INFO : open_files success\n");
    }
    else
    {
	printf("ERROR : Open_files failure\n");
	return e_failure;
    }	

    if(decode_magic_string(MAGIC_STRING, encInfo) == e_success)
    {
	printf("INFO : Magic String match\n");
    }
    else
    {
	printf("ERROR : Magic String doesnt match\n");
	return e_failure;
    }

    if(decode_secret_file_extn(encInfo) == e_success)
    {
	printf("INFO : Secret file extension decoded\n");
    }
    else
    {
	printf("ERROR : Secret file extensions doesnt match\n");
	return e_failure;
    }
    
    if(decode_secret_file_size(encInfo) == e_success)
    {
	printf("INFO : Secret file size encoded\n");
    }
    else
    {
	printf("ERROR : Secret file size.\n");
	return e_failure;
    }

    if(decode_secret_file_data(encInfo) == e_success)
    {
	printf("INFO : Secret file encoded\n");
    }
    else
    {
	printf("ERROR : Secret file data\n");
	return e_failure;
    }

    return e_success;
}
