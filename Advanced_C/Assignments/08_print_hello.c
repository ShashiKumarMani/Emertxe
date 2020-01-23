/*
    Title : Print hello in 'X' format
    Author : Shashi Kumar M
    Date : 27 September 2019
    Description : Program to print 'HELLO' in 'X' format
		  Input : Number of lines
		  Output : Print 'HELLO' in X format
 */

#include<stdio.h>

int main()
{
    //Declare variables and read num
    int num, i, j;
    char option;

    do
    {
	printf("\nEnter the number of lines : ");
        scanf("%d", &num);
    
        //check if number greater than 1
	if (num >= 1)
	{
	    //print the pattern
	    printf("The pattern : \n");

	    //loop x axis
	    for(i = 0;i < num;i++)
	    {
		//loop y axis
	        for(j = 0;j < num;j++)
		{
		    // if diagonal axis print hello
		    if (i == j || i + j == num - 1)
		    {
			printf("HELLO");
		    }
		    else
		    {
			printf(" ");
		    }
		}
		//newline
		printf("\n");
	    }
	}
	else
	{
	    printf("ERROR : Enter a number greater than equal to 1. ");
	}

	//prompt to continue
	printf("Do you want to cotinue ? ");
	getchar();
	scanf("%c",&option);

    }while(option == 'Y' || option == 'y');
    
    return 0;
}
