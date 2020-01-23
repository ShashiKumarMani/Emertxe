/*
    Title : Swap macro
    Author : Shashi Kumar M
    Date : 14 November 2019
    Description : Program to define a single macro to swap varaibles of any datatype.
		  Input - Read datatype, 2 values.
		  Output - After swapping, print the values.
 */		    

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define SWAP(type, num1, num2)  \
{				\
    type temp = num1;		\
    num1 = num2;		\
    num2 = temp;		\
}

int main()
{
    //Declare variables
    char option, *ptr = NULL, *str = NULL, ch1, ch2;
    int num1, num2, choice;
    short s_num1, s_num2;
    float f_num1, f_num2;
    double d_num1, d_num2;

    do
    {
	//Read datatype and values
	printf("\nChoose the datatype :\n1. Int\n2. Short\n3. Float\n4. Double\n5. String\n\nEnter the choice : ");
	scanf("%d", &choice);

	printf("\nEnter the two values : ");

	//Execute choice
	switch(choice)
	{
	    case 1:
		//Print values before and after swap
		scanf("%d %d", &num1, &num2);

		printf("\n\nThe values before swapping num1 - %d num2 - %d\n", num1, num2);

		//Macro
		SWAP(int, num1, num2)	
	
		printf("The values afer swapping num1   - %d num2 - %d\n", num1, num2);    
		break;

            case 2:
                scanf("%hd %hd", &s_num1, &s_num2);
                
                printf("\n\nThe values before swapping num1 - %hd num2 - %hd\n", s_num1, s_num2);
            
                SWAP(short, s_num1, s_num2)
            
                printf("The values afer swapping num1   - %hd num2 - %hd\n", s_num1, s_num2);
                break;

            case 3:
                scanf("%f %f", &f_num1, &f_num2);
                
                printf("\n\nThe values before swapping num1 - %f num2 - %f\n", f_num1, f_num2);
            
                SWAP(float, f_num1, f_num2)
            
                printf("The values afer swapping num1   - %f num2 - %f\n", f_num1, f_num2);
                break;

            case 4:
                scanf("%lf %lf", &d_num1, &d_num2);
                
                printf("\n\nThe values before swapping num1 - %lf num2 - %lf\n", d_num1, d_num2);
            
                SWAP(double, d_num1, d_num2)
            
                printf("The values afer swapping num1   - %lf num2 - %lf\n", d_num1, d_num2);
                break;

	    case 5:
		printf("\nString max length 50, seperate with space\n-->");
		
		//DMA, limit
		ptr = malloc(50);
		str = malloc(50);
		ptr[49] = str[49] = 0;

		scanf("%s %s", ptr, str);
		
		printf("The string before swapping str1 - %s str2 - %s\n", ptr, str);

		SWAP(char *, ptr, str);

		printf("The string after swapping str1  - %s str2 - %s\n", ptr, str);
		
		free(ptr);
		free(str);

		break;

	    default:
		    printf("ERROR : Invalid choice\n");

	}
	
	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
    	scanf("\n%c", &option);
	printf("%d\n", option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
