/*
    Project 1 : LSB Steganography
    Input : Pass file through command line.
	    Encoding ./lsb_steg -e <.bmp file> <secret_file> [output file]
	    Decoding./lsb_steg -d <.bmp file> [output file]
    Output: Secret is Encoded/Decoded from the given bmp file.
    References : https://en.wikipedia.org/wiki/BMP_file_format
		 https://codereview.stackexchange.com/questions/196084/read-and-write-bmp-file-in-c
		 https://stackoverflow.com/questions/33483708/understanding-bmp-file 
		 https://engineering.purdue.edu/ece264/17au/hw/HW15
 */

#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char *argv[])
{
    EncodeInfo encInfo;

    //If arguments are less than 3
    if(argc < 3)
    {
	printf("ERROR : Enter input in correct format\n./lsb_steg: Encoding: ./lsb_steg -e <.bmp file> <secret file> [output file]\n./lsb_steg: Decoding: ./lsb_steg -d <.bmp file> [output file]\n");
	return 0;
    }

    //Check operation type
    if(check_operation_type(argv) == e_encode)
    {
	printf("##### Encode #####\n");

	//Validate args
	if(read_and_validate_encode_args(argv, &encInfo) == e_failure)
	{
	    printf("Enter arguments in correct format and file extensions.\n./lsb_steg: ./lsb_steg -e <.bmp_file> <secret file> [output file]\n");
	    return 0;
	}
	else
	{
	    printf("INFO : Done. Arguments validation done\n");
	}

	//Start encoding
	if(do_encoding(&encInfo) == e_failure)
	{
	    printf("ERROR : Encoding failure\n");
	    return 0;
	}
	else
	{
	    printf("INFO : Encoding Success\n");
	}
    }
    else if(check_operation_type(argv) == e_decode)
    {
	printf("##### Decode #####\n");

	if(read_and_validate_decode_args(argv, &encInfo) == e_failure)
	{
	    printf("Enter arguments in correct format\n./lsb_steg: ./lsb_steg -d <.bmp file> [output file]\n");
	    return 0;
	}
	else
	{
	    printf("INFO : Done. Decoding arguments validation done.\n");
	}

	if(do_decoding(argv, &encInfo) == e_failure)
	{
	    printf("ERROR : Decoding failure\n");
	    return 0;
	}
	else
	{
	    printf("INFO : Decoding success\n");
	}
    }
    else
    {
	printf("ERROR : Unsupported\n");
    }

    return 0;
}
