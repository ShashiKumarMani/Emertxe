/*
    Title : Sizeof
    Author : Shashi Kumar M
    Date : 13 November 2019
    Description : Program to define a macro SIZEOF where x is a variable without using sizeof operator.
		  Input - No Input.
		  Output - Print szieof of different datatypes.
 */

#include<stdio.h>

#define SIZEOF(x)		    \
{				    \
    void *ptr = &x, *str = &x + 1;  \
    printf("%ld\n", str - ptr);	    \
}

int main()
{
    char option;
    void *ptr = NULL, *str = NULL;

    do
    {
	int num = 0, size = -1;
	short s_num;
	float f_num;
	double d_num;
	long int l_num;


	printf("Sizeof int is       - "); SIZEOF(num)
	printf("Sizeof short is     - "); SIZEOF(s_num)
	printf("Sizeof float is     - "); SIZEOF(f_num)
	printf("Sizeof long int is  - "); SIZEOF(l_num)
	printf("Sizeof double is    - "); SIZEOF(d_num)

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("\n%c", &option);
	printf("OPTION - %d\n", option);
	
    }while(option == 'Y' || option == 'y');

    return 0;
}





