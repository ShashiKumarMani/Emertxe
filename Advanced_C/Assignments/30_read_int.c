/*
    Title : Read integers.
    Author : Shashi Kumar M
    Date : 14 October 2019
    Description : Program to read integer using getchar() function.
		  Input - Read characters.
		  Output - Convert the character to integer and print the integer.
 */

#include<stdio.h>
#include<stdio_ext.h>

//Function to read the intger
int read_integer(int *ptr)
{
    //Declare variables
    char ch;
    int num = 0, flag = 0;

    printf("\nEnter the integer : ");

    //Loop and read characters
    while((ch = getchar()) != '\n')
    {
	//Set flag if number is negative
	if(ch == '-')
	{
	    flag = 1;
	}
	else if(ch == '+')
	{
	    flag = 0;
	}
	else if(ch >= '0' && ch <= '9')
	{
	    num = num * 10 + (ch - 48);
	}
	//If a character is read
	else
	{
	    break;
	}
    }
    
    //If negative return negative
    *ptr = flag ? -num : num;
}

int main()
{
    //Declare variables
    char option, ch, opt, red;
    int num = 0, ret;

    do
    {
	//Call function
	ret = read_integer(&num);

	__fpurge(stdin);

	//Check for errors
	if(ret == -1)
	{
	    printf("ERROR : Enter integers only.\n");
	}
	else
	{
	    printf("\nThe output - %d\n", num);
	}
	
	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);
	getchar();

    }while(option == 'Y' || option == 'y');

    return 0;
}
