/*
    Title : Program to check if number is even or odd
    Author : Shashi Kumar M
    Date : 1 October 2019
    Description : WAP to check whether a number is even or odd using bitwise operators
		  Input : A number
		  Output : Print whether a number is even or odd. 
*/

#include<stdio.h>

int main()
{
    //Declare and read input
    int num;
    unsigned mask;
    char option;

    do
    {
	//Read the number
	printf("\nEnter a number : ");
	scanf("%d", &num);

	//Mask to get 1 at last index
	mask = 1 << sizeof(int) * 8 - 1;

	//Print the result
	printf("The number is ");

	//If else to find positive or negative
	if ((num & mask) == mask)
	{
	    //Ternary operator to find zero, odd or even.
	    (num & -1) == 0 ? printf("Zero\n") : (num & 1) == 0 ? printf("-ve Even\n") : printf("-ve Odd\n");
	}
	else 
	{
	    //Ternary operator to find zero, odd or even.
	    (num & -1) == 0 ? printf("Zero\n") : (num & 1) == 0 ? printf("+ve Even\n") : printf("+ve Odd\n");
	}
	
	//Prompt to continue
	printf("\nDo you want to continue ? [Yy || Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');
    
    return 0;
}
