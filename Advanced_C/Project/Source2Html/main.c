/***********************************************************************************************************************************************  

    Project : Source to HTML
    Description : Program to convert a source .c file into html
    Input : A .c file
    Output : Convert the .c into .html

*************************************************************************************************************************************************/

#include "header.h"

int main(int argc, char *argv[])
{
    FileInfo InputData;

    //If #args less than 3
    if(argc < 3)
    {
	printf("USAGE : ./a.out <source file.c> <output file.html> <-n>\n");
	return 0;
    }

    //Validate command line arguments    
    if(validate_args(argv, &InputData) == FAILURE)
    {
	printf("USAGE : ./a.out <source file.c> <output file.html> <-n >\n");
	return 0;
    }

    printf("INFO : Arguments validation Done.\n");

    //Open files
    if(open_files(&InputData) == FAILURE)
    {
	printf("ERROR : Open Files\n");
	return 0;
    }

    printf("INFO : Files opened\n");

    if(add_tags(&InputData) == FAILURE)
    {
	printf("ERROR : Add flags\n");
	return 0;
    }

    printf("INFO : HTML tags added to the file.\n");

    return 0;
}
