/*
    Title : Fragments
    Author : Shashi Kumar M
    Date : 18 November 2019
    Description : Program to find average of rows of a 2d array of varying column size.
		  Input - Number of rows, Columns.
		  Output - Print rows and average of each row.
*/

#include <stdio.h>
#include <stdlib.h>

//Function to read array elements
void read_elements_average(float **arr, int *col_size, int rows)
{
    float sum = 0;
    int i, j;

    //Loop and read #columns and elements
    for(i = 0;i < rows;i++)
    {   
	printf("\nEnter the number of columns of row %d : ", i);
        scanf("%d", col_size + i);
             
        arr[i] = malloc((*(col_size + i) + 1) * sizeof(float));
             
        printf("Enter the array elements : ");

	sum = 0;
	
	//Read elements and add it to sum
        for(j = 0;j < col_size[i];j++)
        {   
            scanf("%f", (*(arr + i) + j));
	    sum += *(*(arr + i) + j);
        }

	//Store average in last index
	*(*(arr + i) + j) = sum / col_size[i];    
    }
}

//Function to sort the arrays
void sort_arrays(float **arr,int *col_size, int rows)
{
    float temp, *temp_ptr;
    int i, j;

    //Bubble sort
    for(j = 0;j < rows - 1;j++)
    {
        for(i = 0;i < rows - j - 1;i++)
        {
            if(*(*(arr + i) + *(col_size + i)) > *(*(arr + i + 1)  + *(col_size + i + 1)))
            {
                //Swap pointer
                temp_ptr = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp_ptr;
 
		//Swap col_sizes
                temp = *(col_size + i);
                *(col_size + i) = *(col_size + i + 1);
                *(col_size + i + 1) = temp;
            }
        }
    }
}

int main()
{
    char option;
    int rows, *col_size = NULL, i, j;
    float **arr = NULL;

    do
    {
	//Read values
	printf("\nEnter the number of rows : ");
	scanf("%d", &rows);

	col_size = malloc(rows * sizeof(int));

	arr = malloc(rows * sizeof(float *));

	//Read elements and find average
	read_elements_average(arr, col_size, rows);
	
	//Sort arrays
	sort_arrays(arr, col_size, rows);

	//Print all elements
	for(i = 0;i < rows;i++)
	{
	    printf("%d - ", i);

	    for(j = 0;j < col_size[i];j++)
	    {
		printf("%f ", arr[i][j]);
	    }
	    printf("   Avg - %f\n", arr[i][j]);
	}

	//Free DMA
	for(i = 0;i < rows;i++)
	{
	    free(arr[i]);
	}
	free(arr);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
