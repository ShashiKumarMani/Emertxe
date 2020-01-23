/*
    Title : Sizeof  
    Author : Shashi Kumar M
    Date : 26 September 2019
    Description : Print the sizes of all basic datatypes using sizeof operator
		    Input - No input
		    Output - Print sizes of all basic datatypes
 */

#include<stdio.h>

int main()
{
    //print sizeof datatypes
    printf("The size of char - %lu bytes\n",sizeof(char));
    printf("The size of unsigned char - %lu bytes\n",sizeof(unsigned char));
    printf("The size of signed short - %lu bytes\n",sizeof(signed short));
    printf("The size of unsigned short - %lu bytes\n",sizeof(unsigned short));
    printf("The size of int - %lu bytes\n",sizeof(int));
    printf("The size of unsigned int - %lu bytes\n",sizeof(unsigned int));
    printf("The size of long - %lu bytes\n",sizeof(long));
    printf("The size of unsigned long - %lu bytes\n",sizeof(unsigned long));
    printf("The size of signed long long - %lu bytes\n",sizeof(signed long long));
    printf("The size of unsigned long long - %lu bytes\n",sizeof(unsigned long long));
    printf("The size of float - %lu bytes\n",sizeof(float));
    printf("The size of double - %lu bytes\n",sizeof(double));
    printf("The size of long double - %lu bytes\n",sizeof(long double));

    return 0;
}
