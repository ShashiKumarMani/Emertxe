/*
    Title - Matrix multiplication
    Author - Shashikumar M
    Date - 6 February 2020
    Description - Program to perform matrix multiplication using threads
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

/* structure to store matrix info m1_col == m2_row*/
typedef struct threaddata{

    short m1_row;
    short m1_col;
    short m2_col;
    int **matrix1;
    int **matrix2;
    int **result;
    short curr_row;

}ThreadData_t;

/* Function to allocate memory */
int allocate_memory(short row, short col, int ***src_matrix)
{
  //  printf("1\n");

    //printf("Allocate - row %d col %d\n", row, col);

    int **matrix = malloc(sizeof(int *) * row);

    for(short i = 0;i < row;i++)
    {
//	printf("i - %d\n", i);
	*(matrix + i) = malloc(sizeof(int) * col);
//	printf("done\n");
    }
    
    *src_matrix = matrix;

  //  printf("2\n");
}

/* Print matrices */
void print_matrix(int row, int column, int **matrix)
{
    for(int i = 0;i < row;i++)
    {
	for(int j = 0;j < column;j++)
	{
	    printf("%d ", matrix[i][j]);
	}
	printf("\n");
    }
}

void scan_matrix(int row, int column, int **matrix)
{
    /* Scan values */ 
    for(int i = 0;i < row;i++)
    {   
	for(int j = 0;j < column;j++)
        {   
//	    printf("[%d][%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
	}
    }
}

/* Thread function */
void *matrix_mul(void *data)
{
  //  printf("Matrix multiplication\n");

    ThreadData_t matrix = *(ThreadData_t *)data;
    int sum = 0;

    /* Columns */
    for(int i = 0;i < matrix.m2_col;i++)
    {
	/* Rows */
	for(int j = 0;j < matrix.m1_col;j++)
	{
//	    printf("[%d][%d] * [%d][%d] :\n", matrix->curr_row, j, j, i);
	    sum += (matrix.matrix1[matrix.curr_row][j] * matrix.matrix2[j][i]);
	}
//	printf("Sum - %d\n", sum);
	matrix.result[matrix.curr_row][i] = sum;
    }
}

int main()
{
    ThreadData_t matrix_data;
    short m2_row;

    printf("Enter M1 rows and columns : ");
    scanf("%hd %hd", &matrix_data.m1_row, &matrix_data.m1_col);

    /* M1 col == M2 rows*/
    printf("Enter M2 rows and columns : ");
    scanf("%hd %hd", &m2_row, &matrix_data.m2_col); 

    if(matrix_data.m1_col != m2_row)
    {
	printf("\nERROR : Matrix1 columns != Matrix2 rows\n");
	return 0;
    }
    pthread_t threads[matrix_data.m1_row];

    /* Allocate memory */
    allocate_memory(matrix_data.m1_row, matrix_data.m1_col, &matrix_data.matrix1);
    allocate_memory(matrix_data.m1_col, matrix_data.m2_col, &matrix_data.matrix2);
    allocate_memory(matrix_data.m1_row, matrix_data.m2_col, &matrix_data.result);

    /* Scan */
    printf("\nEnter elements of matrix 1 : \n");
    scan_matrix(matrix_data.m1_row, matrix_data.m1_col, matrix_data.matrix1);
    
    printf("\nEnter elements of matrix 2 : \n");
    scan_matrix(matrix_data.m1_col, matrix_data.m2_col, matrix_data.matrix2);

    /* Print values */
    printf("\nMatrix 1 : \n");
    print_matrix(matrix_data.m1_row, matrix_data.m1_col, matrix_data.matrix1);

    printf("\nMatrix 2 : \n");
    print_matrix(matrix_data.m1_col, matrix_data.m2_col, matrix_data.matrix2);

    /* Create threads */ 
    for(int i = 0;i < matrix_data.m1_row;i++)
    {
	matrix_data.curr_row = i;
	pthread_create(&threads[i], NULL, matrix_mul, (void *)&matrix_data);	
    }

    for(int i = 0;i < matrix_data.m1_row;i++)
    {
	pthread_join(threads[i], NULL);
    }
    
    printf("\nResult : \n");
    print_matrix(matrix_data.m1_row, matrix_data.m2_col, matrix_data.result);
    
    return 0;
}
