/*
    Title : Sizeof
    Author : Shashi Kumar M
    Date : 13 November 2019
    Description : Program to define a macro SIZEOF where x is a variable without using sizeof operator.
		  Input - No Input.
		  Output - Print szieof of different datatypes.
 */

#include<stdio.h>

#define SIZEOF(x)   ((char *)(&x + 1) - (char *)&x)

int main()
{
    char option;
    void *ptr = NULL, *str = NULL;

    do
    {
	int num = 0, size = -1;
	short s_num;
	float f_fl;
	double doub;
	long int l_num;
	long long int ll_num;
	long double l_doubb;

	printf("Sizeof int is         - %ld \n", SIZEOF(num));
	printf("Sizeof short is       - %ld \n", SIZEOF(s_num));
	printf("Sizeof float is       - %ld \n", SIZEOF(f_fl));
	printf("Sizeof long int is    - %ld \n", SIZEOF(l_num));
	printf("Sizeof double is      - %ld \n", SIZEOF(doub));
	printf("Sizeof long int is    - %ld \n", SIZEOF(ll_num));
	printf("Sizeof long double is - %ld \n", SIZEOF(l_doubb));

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("\n%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}





