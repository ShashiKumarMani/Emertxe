/*
    Title : File copy
    Author : Shashi Kumar M
    Date : 20 November 2019
    Description : Program to implement my_cp() function.
		  Input - Read source, destination file names.
		  Output - Copy file contents from source to destination.
 */

#include<stdio.h>

//Function to copy contents
void my_cp(FILE *src, FILE *dest)
{
    char ch;

    //If no errors
    if(src)
    {
	while((ch = fgetc(src)) != EOF)
	{
	    fputc(ch, dest);
	}

	printf("\nFile copied successfully\n");	
    }
    else
    {
	printf("\nERROR : Source file doesnt exist\n");
    }
}

int main(int argc, char *argv[])
{
    char option;
    FILE *src, *dest;

    do
    {
	if(argc > 2)
	{
	    //Open files and call function
	    src = fopen(argv[1], "r");
	    dest = fopen(argv[2], "w");

	    my_cp(src, dest);
	}
	else
	{
	    printf("\nERROR : Please pass files in format [ ./a.out <Source_file> <Destination_file> ]\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to copy the files again? [Yy | Nn] : ");
	scanf("\n%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}


