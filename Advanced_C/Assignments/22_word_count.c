/*
    Title : Word Count
    Author : Shashi Kumar M
    Date : 14 October 2019
    Description : Program to implement word count.
		  Input - Read a number.
		  Output - Print number of words, number of characters and number of lines.
		  https://stackoverflow.com/questions/32322792/why-multiple-eof-enters-to-end-program
*/

#include<stdio.h>
#include<unistd.h>
#include<stdio_ext.h>

//Word count function
void wc_func(int *line_c, int *word_c, int *char_c)
{
    int word_flag = 0;
    char ch, opt;

    //Loop and read characters till EOF
    while(1)
    {
	if((ch = getchar()) == EOF)
	{
	    break;
	}

	(*char_c)++;

        //If character is newline
        if(ch == '\n')
        {
	    (*line_c)++;
            word_flag = 0;
        }
        else if(ch == ' ' || ch == '\t')
        {
            word_flag = 0;
        }
        else
        {
            //If previous character is blank
            if(word_flag == 0)
            {
		(*word_c)++;
            }
            word_flag = 1;
        }
    }
}

int main()
{
    //Declare variables
    char option;
    int word_count, char_count, line_count;

    do
    {
	//Reset flags and counts
	word_count = char_count = line_count = 0;

	wc_func(&line_count, &word_count, &char_count);

	//Print the result
	printf("\t%d\t%d\t%d\n", line_count, word_count, char_count);

	__fpurge(stdin);
	
	clearerr(stdin);
	
	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);
	getchar();
    
    }while(option == 'Y' || option == 'y');

    return 0;
}
