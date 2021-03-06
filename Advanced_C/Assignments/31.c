/*

    Title : Float, Double Binary
    Author : Shashi Kumar M
    Date : 19 November 2019
    Description : Program to print the binary form of a float and double variable.
		  Input  - Read a float or Double variable.
		  Output - Print the binary of the variable.

 */

#include <stdio.h>

//Function to print double bits
void print_bits(long int num, long unsigned int size)
{
    unsigned long int mask = 1;

    printf("\nThe binary form : ");

    for(mask = mask << size * 8 - 1;mask > 0;mask >>= 1)
    {
	(num & mask) == 0 ? printf("0") : printf("1");
    }
    printf("\n");
}

int main()
{
    int choice, *ptr = NULL;
    char option;
    float f_num;
    double d_num;

    do
    {
	//Read choice
	printf("\nMenu\n1. Float\n2. Double\n\nEnter your choice : ");
	scanf("%d", &choice);

	//Execute choice
	switch(choice)
	{
	    case 1:
		    printf("\nEnter the value : ");
		    scanf("%f", &f_num);

    		    print_bits(*(int *)&f_num, sizeof(float));

		break;
	    case 2:
		    printf("\nEnter the value : ");
		    scanf("%lf", &d_num);

		    print_bits(*(long int *)&d_num, sizeof(double));

		break;
	    default:
		    printf("ERROR\n");
	}	    

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
