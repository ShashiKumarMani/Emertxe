/*
    Title : Magic Square
    Author : Shashi Kumar M
    Date : 5 November 2019
    Description : Program to print the magic square.
		  Input - Read a size n.
		  Output - Print the magic square.
 */

#include<stdio.h>
#include<stdlib.h>

//Function to create magic square
void magic_square(int size, int **arr)
{
    int val, i = 0, j = size / 2, i_new, j_new;

    //Loop and enter array elements
    for(val = 1;val <= size * size;val++)
    {
	arr[i][j] = val;
	
	i_new = i - 1;
	j_new = j + 1;

	//If row is out of range
	if(i_new < 0)
	{
	    i_new = size - 1;
	}
	//If col is out of range
	if(j_new > size - 1)
	{
	    j_new = 0;
	}
	//If the index is occupied, calloc 
	if(arr[i_new][j_new] != 0)
	{
	    i_new = i + 1;
	    j_new = j;
	}

	i = i_new;
	j = j_new;
    }
}

//Function to print the array elements
void print_square(int size, int **arr)
{
    int i = 0,j = 0;

    for(i = 0;i < size;i++)
    {
	for(j = 0;j < size;j++)
	{
	    printf("%*d ", size / 2, arr[i][j]);
	}
	printf("\n");
    }
}

int main()
{
    //Declare variables
    char option;
    int i, size, **arr = NULL;

    do
    {
	//Read size
	printf("Enter the size : ");
	scanf("%d", &size);

	//Error checking
	if(size >= 3 && size % 2 == 1)
	{
	    //Allocate memory
	    arr = malloc(size * sizeof(int *));

	    //Calloc to initialise elements to zero
	    for(i = 0;i < size;i++)
	    {
		arr[i] = calloc(size, sizeof(int));
	    }

	    //Call functions
    	    magic_square(size, arr);
	    
	    print_square(size, arr);
	}
	else
	{
	    printf("Please enter an odd value greater than 3\n");
	}

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
