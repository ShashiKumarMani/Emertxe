/*
    Title : Finf variance 
    Author : Shashi Kumar M
    Date : 4 November 2019
    Description : Variance calculation using static and dynamic arrays.
		  Input - Array size and elements of the array.
		  Output - Variance of the given array elements.
 */

#include<stdio.h>
#include<stdlib.h>

//Function to find variance and print table
float find_variance(int arr[], int size)
{
    int i = 0, diff; 
    float sum = 0, mean = 0, diff_sq = 0;

    //Calculate sum of elements
    for(i = 0;i < size;i++)
    {
	sum += arr[i];
    }

    mean = sum / size;

    printf("\nX\tD = X - mean\tD2\n-----------------------------------\n");

    //Calculate diff and sum of diff_square
    for(i = 0;i < size;i++)
    {
	diff = arr[i] - mean;
	printf("%3d\t%3d\t\t%3d\n", arr[i], diff, diff * diff);
	diff_sq += (diff * diff);
    }

    printf("-----------------------------------\nSUM=%.1f\t\t\tSUM=%.1f\n", sum, diff_sq);

    return diff_sq / size;
}

int main()
{
    char option;
    int arr[10], i = 0, *ptr = NULL, num, choice;
    float variance;

    do
    {
	printf("\n1. Static arrays[10]\n2. Dynamic arrays\n\nEnter your choice : ");
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		    //Static arrays
		    printf("Enter 10 elements : ");

		    for(i = 0;i < 10;i++)
		    {
			scanf("%d", arr + i);
		    }
		    
		    variance = find_variance(arr,10);

		    printf("\nThe variance is - %.3f\n", variance);
		break;

	    case 2:
		    //Dynamic array
		    printf("Enter the number of elements : ");
		    scanf("%d", &num);

		    ptr = (int *)malloc(num * sizeof(int));

		    printf("Enter the elements : ");

		    for(i = 0;i < num;i++)
		    {
			scanf("%d", ptr + i);
		    }

		    variance = find_variance(ptr, num);

		    printf("\nThe variance is- %.3f\n", variance);
		break;

	    default :
			printf("ERROR : Invalid choice\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
