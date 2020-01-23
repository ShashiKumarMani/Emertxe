/*
    Title : Find median of two unsorted arrays. 
    Author : Shashi Kumar M
    Date : 09 October 2019
    Description : Find the median of two unsorted arrays.
		  Input - Read the size and the elements of the arrays.
		  Output - Print the median of the arrays.
 */

#include<stdio.h>

//Function to print array elements
void print_array(int *ptr, int size)
{
    //Declare the variables
    int i;

    //Print the elements
    for(i = 0;i < size;i++)
    {
	printf("%d ", ptr[i]);
    }
    printf("\n");

    return;
}

//Function to scan arrays
void scan_array(int *ptr, int size)
{
    //Declare the variables
    int i;

    printf("Enter %d array elements : ", size);

    //Scan the variables
    for(i = 0;i < size;i++)
    {
	scanf("%d", ptr + i);
    }

    return;
}

//Function to find median of one array
float find_median(int *arr, int size)
{
    //Declare the variables
    int i, j, temp;

    //Sort 
    for(i = 0;i < size;i++)
    {
	for(j = 0;j < size - i - 1;j++)
	{
	    //Swap
	    if(arr[j] > arr[j + 1])
	    {
		temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;		
	    }
	}
    }

    //Print array
    printf("The sorted array : ");
    print_array(arr, size);

    //return median
    return size % 2 == 0 ? (arr[size / 2 - 1] + arr[size / 2]) / 2.0 : arr[size / 2];
}

//Function to find median of both arrays
float array_median(int *ptr1, int size1, int *ptr2, int size2)
{
    //Call function and find median of each array
    return (find_median(ptr1, size1) + find_median(ptr2, size2)) / 2;
}

int main()
{
    //Declare the variables
    char option;
    int size1, size2;

    do
    {
	//Read array size
	printf("\nEnter the number of elements of array 1 : ");
	scanf("%d", &size1);

	printf("Enter the number of elements of array 2 : ");
	scanf("%d", &size2);

	//Check array size
	if(size1 >= 1 && size2 >= 1)
	{
	    //Static allocation
	    int arr1[size1], arr2[size2];

	    //Scan the array
	    scan_array(arr1, size1);
	    scan_array(arr2, size2);

	    //Print the median
	    printf("\nThe median of the two arrays is %.2f.\n", array_median(arr1, size1, arr2, size2));
	}
	else
	{
	    printf("Error : Array size must be greater than 0.\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
