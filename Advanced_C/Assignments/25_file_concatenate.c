/*

    Title : File Concatenate
    Author : Shashi Kumar M
    Date : 20 November 2019
    Description : Program to concatenate 2 files into a 3rd file.
		  Input - Read 3 file names.
		  Output - Copy file contents into a 3rd file.

*/

#include <stdio.h>
#include <stdio_ext.h>

//Function to implement cp command
void my_cp(FILE *src, FILE *dest)
{
    char ch;

    if(src && dest)
    {
	while((ch = fgetc(src)) != EOF)
	{
	    fputc(ch, dest);
	}
    }
    else
    {
	printf("ERROR : Source file doesnt exist\n");
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char option;
    FILE *file1, *file2, *file3;

    do
    {
	switch(argc)
	{
	    case 1:
		    my_cp(stdin, stdout);

		break;
	    case 2:
		    if(file1 = fopen(argv[1], "r"))
			my_cp(file1, stdout);
		    else
			printf("ERROR : File doesn't exist\n");

		break;
	    case 3:
		    file1 = fopen(argv[1], "r");
		    file2 = fopen(argv[2], "r");

		    if(file1 && file2)
		    {
			my_cp(file1, stdout);
			my_cp(file2, stdout);
		    }
		    else
		    {
			printf("ERROR : File doesn't exist\n");
		    }

		break;

	    default:
		    //Open files
		    file1 = fopen(argv[1], "r");
		    file2 = fopen(argv[2], "r");
		    file3 = fopen(argv[3], "w");

		    if(file1 && file2)
		    {
			my_cp(file1, file3);
			my_cp(file2, file3);

			printf("File contents copied to File3\n");
		    }
		    else
		    {
			printf("ERROR : File doesn't exist\n");
		    }

		break;
	}	    

	//Clear EOF from buffer
	clearerr(stdin);

	//Prompt to continue or not
	printf("\nDo you want rerun the command line arguments? [Yy | Nn] : ");
	scanf("%c", &option);
	printf("%d\n", option);
	
	__fpurge(stdin);

    }while(option == 'Y' || option == 'y');

    return 0;
}
