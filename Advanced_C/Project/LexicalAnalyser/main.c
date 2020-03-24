/*
    Project - Lexical Analyser
    Author - Shashikumar M
    Date - -31 - January 2020
    Description - Perform lexical ananlysis on a given .c file

 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "1_parser.c"

int main(int argc, char *argv[])
{
    FILE *fptr = NULL;

    if(argc < 2)
    {
	printf("ERROR : Enter a .c file\n");
	return 0;
    }

    printf("The file name : %s\n", argv[1]);

    printf("Open : %s : ", argv[1]);

    if((fptr = fopen(argv[1], "rb")) == NULL)
    {
	printf("FAILURE;\n"); 
	return 0;
    }
    else
    {
	printf("SUCCESS\n");
    }

    parser(fptr);
}
