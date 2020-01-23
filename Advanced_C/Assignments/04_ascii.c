/*
    Title : Print ascii characters 
    Author : Shashi Kumar M
    Date : 26 September 2019
    Description : Print all ascii characters
		  Input - No Input
		  Output - Print all ascii characters
 
 */

#include<stdio.h>

int main()
{
    int i;

    //header
    printf("Oct\tDec\tHex\tChar\n------------------------------------------\n\n");

    //loop from 0-127 
    for (i = 0;i < 128;i++)
    {
	printf("%3o\t%3d\t%3x\t",i,i,i);   // print octal,decimal,hexadecimal
	
	if (i <= 32 || i == 127)           // if the value less than 32 or 127 
	{
	    printf("NON-printable\n");
	}
	else
	{
	    printf("%c\n",i);		// else print the character
	}
    }

    return 0;
}
