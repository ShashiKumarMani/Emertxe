/*

    Title : Calc_mean
    Author : Shashi Kumar M
    Date : 8 November 2019
    Description : Program to implement calc_mean for all basic datatypes.
		  Input - choice(short, int, float, double), n and n number of elements.
		  Output - Mean of given elements.
 
*/

#include<stdio.h>
#include<stdlib.h>

//Function to calculate mean
double calc_mean(void *ptr, int num, int choice)
{
    double sum = 0;
    int i;

    //Int, short, float, Double
    switch(choice)
    {
	case 1:
		for(i = 0;i < num;i++)
		{
		    sum += *((int *)ptr + i);
		}	

	    break;
	case 2:
		for(i = 0;i < num;i++)
		{
		    sum += *((short *)ptr + i);
		}

	    break;
	case 3:
		for(i = 0;i < num;i++)
		{
		    sum += *((float *)ptr + i);
		}

	    break;
	case 4:
		for(i = 0;i < num;i++)
		{
		    sum += *((double *)ptr + i);
		}
	    
	    break;
    }

    return sum / num;
}

int main()
{
    char option;
    double mean;
    int choice, num, i;
    void *ptr = NULL;

    do
    {
	//Read values
	printf("\nEnter the number of elements : ");
	scanf("%d", &num);
	
	printf("\nEnter datatype\n1. Int\n2. Short\n3. Float\n4. Double\n\nEnter your choice : ");
	scanf("%d", &choice);

	printf("Enter the elements : ");

	//Execute choice
	switch(choice)
	{
	    case 1:
		    //Allocate memory and read array
		    ptr = malloc(num * sizeof(int));

		    for(i = 0;i < num;i++)
		    {
			scanf("%d", (int *)ptr + i);
		    }

		    mean = calc_mean(ptr, num, choice);

		    printf("\nThe mean is %f\n", mean);

		break;
	    case 2:
		    ptr = malloc(num * sizeof(short));
		    
		    for(i = 0;i < num;i++)
		    {
			scanf("%hd", (short *)ptr + i);
		    }

		    mean = calc_mean(ptr, num, choice);

		    printf("\nThe mean is %f\n", mean);
		break;
	    case 3:
		    ptr = malloc(num * sizeof(float));
		
		    for(i = 0;i < num;i++)
		    {
			scanf("%f", (float *)ptr + i);
		    }

		    mean = calc_mean(ptr, num, choice);

		    printf("\nThe mean is %f\n", mean);
		break;
	    case 4:
		    ptr = malloc(num * sizeof(double));

		    for(i = 0;i < num;i++)
		    {
			scanf("%lf", (double *)ptr + i);
		    }

		    mean = calc_mean(ptr, num, choice);
		    
		    printf("\nThe mean is %f\n", mean);
		break;
	    default:
		    printf("ERROR : Invalid choice\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
