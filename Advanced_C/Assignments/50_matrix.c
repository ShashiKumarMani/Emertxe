/*
    Title : Matrix multiplication.
    Author : Shashi Kumar M
    Date : 7 November 2019
    Description : Program to perform matrix multiplication.
		  Input - Row and column values.
		  Output - Print resultant matrix.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

//Function to create a transpose matrix
void transpose(int row, int column, int **matrix1, int **matrix2)
{
    int i, j;

    //matrix2[j][i] = matrix1[i][j]
    for(i = 0;i < row;i++)
    {
	for(j = 0;j < column;j++)
	{
	    *(*(matrix2 + j) + i) = *(*(matrix1 + i) + j);
	}
    }
}

//Function to multiply matrices
void matrix_multiplication(int row, int column, int **matrix1, int **matrix2,int **result)
{
    int sum = 0, i, j, k;

    //Loop through result matrix and enter values
    for(i = 0;i < row;i++)
    {
	for(j = 0;j < row;j++)
	{
	    sum = 0;

	    //Multiply and add row[i] of matrix1 and col[j] of matrix2
	    for(k = 0;k < column;k++)
	    {
		sum += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
	    }

	    *(*(result + i) + j) = sum;
	}
    }
}

//Function to free memory
void free_memory(int **ptr, int rows, int columns)
{
    for(int i = 0;i < rows;i++)
    {
	free(ptr[i]);
    }
    free(ptr);
}

int main()
{
    char option;
    int **matrix1 = NULL, **matrix2 = NULL, **result = NULL, rows, columns, i , j;    

    do
    {
	//Read values
	printf("\nEnter row value : ");
	scanf("%d", &rows);	

	printf("Enter column value : ");
	scanf("%d", &columns);
    
	//User matrix memory
	matrix1 = malloc(rows * sizeof(int *));

	for(i = 0;i < rows;i++)
	{
	    *(matrix1 + i)  = malloc(columns * sizeof(int));
	}

	//Transpose of matrix
	matrix2 = malloc(columns * sizeof(int *));

	for(i = 0;i < columns;i++)
	{
	    *(matrix2 + i) = malloc(rows * sizeof(int));
	}
	
	//Result matrix memory allocation
	result = malloc(rows * sizeof(int *));

	for(i = 0;i < rows;i++)
	{
	    *(result + i) = malloc(rows * sizeof(int));
	}

	//Read matrix
	printf("\nEnter matrix values : \n");

	for(i = 0;i < rows;i++)
	{
	    for(j = 0;j < columns;j++)
	    {
		scanf("%d", (*(matrix1 + i) + j));
	    }
	}

	//Call tranpose
	transpose(rows, columns, matrix1, matrix2);

	//Call multiplication
	matrix_multiplication(rows, columns, matrix1, matrix2, result);

	//Print resultant matrix and free memory
	printf("\nResultant matrix\n");

	for(i = 0;i < rows;i++)
	{
	    for(j = 0;j < rows;j++)
	    {
		printf("%4d", result[i][j]);
	    }
	    printf("\n");
	}

	free_memory(matrix1, rows, columns);
	free_memory(matrix2, columns, rows);
	free_memory(result, rows, rows);

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
