/*
    Title : Sort a float array
    Author : Shashi Kumar M
    Date : 23 October 2019
    Description : Read n float elements in array 'arr', Print the values in sorted order without modifying or copying array arr.
		  Input - n float non-duplicate elements.
		  Output - Print the array in sorted order.		
*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

//Function to read array elements
void read_array(float *arr, int size)
{
    int i = 0;

    for(i = 0;i < size;i++)
    {
	scanf("%f", &arr[i]);
    }
}

//Function to print sorted array
void print_sorted(float *arr, int size)
{
    if(size == 0)
    {
	printf("ERROR : Provide inputs.\n");
    }

    float temp, temp2 = INT_MIN;

    printf("\nThe sorted array\n");
    
    //Loops to print the array in sorted order, 
    for(int i = 0;i < size;i++)
    {
	temp = INT_MAX;

	//Find the smallest value in the array, greater than previous smallest element
        for(int j = 0;j < size;j++)
	{
	    //IF element is less than other elements and greater than prev printed element.
	    if(arr[j] < temp && arr[j] > temp2)
	    {
		temp = arr[j];
	    }
	}
	temp2 = temp;

	printf("%.2f ", temp);
    }
    printf("\n\n");
}

int main()
{
    //Declare variables
    char option;
    int size, i;
    float *arr = NULL;

    do
    {
	//Read n
	printf("Enter the value of n : ");
	scanf("%d", &size);

	//printf("Size - %d\n", size);

	arr = malloc(size * sizeof(float));

	//Read elements
	read_array(arr, size);

	//Print sorted order
	print_sorted(arr, size);

	//Print the original array
	printf("The original array \n");

	for(i = 0;i < size;i++)
	{
	    printf("%.2f ",arr[i]);
	}
	printf("\n\n");

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
