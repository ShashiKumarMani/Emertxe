/*
    Title : Demoted int
    Author : Shashi Kumar M
    Date : 22 November 2019
    Description : Program to Demote a float value.
		  Input - Read a float value.
		  Output - Print the demoted float value.
 */

#include<stdio.h>

//Union to store float value
union float_bits{

    float num;
    struct bits{

	unsigned m : 23;
	unsigned e : 8;
	unsigned s : 1;

    }elements;
};

//Function to demote float value
void demote_float(union float_bits *ptr)
{
    int num = ptr->elements.e - 127;

    printf("N-%d M-%u\n", num, ptr->elements.m);

    //If num is less than 1 0.xyz
    if(num < 0)
    {
	ptr->elements.e = 0;
    }
    else
    {
	//Retain num bits from msb of mantissa
	ptr->elements.m = ptr->elements.m & ~((1 << (23 - num)) - 1);
    }


}

int main()
{
    char option;
    union float_bits var;

    do
    {
	//Read value
	printf("\nEnter the value : ");
	scanf("%f", &var.num);	
	
	//Call function and print result
	demote_float(&var);
	
	printf("\nResult value : %f\n", var.num);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
