/*
    Title - Threads_sum_max
    Author - Shashikumar M
    Date - 
    Description - Program to find sum and max of the given array using threads.

 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>

#define NUMTHREADS 5

pthread_mutex_t lock;

typedef struct{

    int index;
    int *indices;
    int *arr;
    
}ThreadArr;

int sum, max = INT_MIN;

/* Function to read the array */
void read_array(int *arr, int size, int *sum, int *max)
{
    for(int i = 0;i < size;i++)
    {
	arr[i] = rand() % size;
	*sum += arr[i];
	if(arr[i] > *max)
	    *max = arr[i];
    }
}

/* Function to find sum and max, & update the global variables using mutex-lock */
void *sum_max(void *data_g)
{      
    int sum_t = 0, max_t = INT_MIN;
    ThreadArr *data = (ThreadArr *)data_g;

    /* Find the sum and max*/ 
    for(int i = data->indices[data->index];i <= data->indices[data->index + 1];i++)
    {
	if(data->arr[i] > max_t)
	    max_t = data->arr[i];

	sum_t += data->arr[i];
    }

    /* Lock and update*/
    pthread_mutex_lock(&lock);

    sum += sum_t;
    if(max_t > max)
	max = max_t;

    pthread_mutex_unlock(&lock);
}


int main()
{
    int size, *indices = NULL, excess = 0, len, m_sum = 0, m_max = 0;
    pthread_t threads[NUMTHREADS];
    ThreadArr Arr_data;

    /* Read size and allocate memory */
    printf("\nEnter the size of array : ");
    scanf("%d", &size);

    Arr_data.arr = malloc(sizeof(int) * size);
    indices = malloc(sizeof(int) * NUMTHREADS * 2);

    /* Find the range and modulus*/
    len = size / NUMTHREADS;
    excess = size % NUMTHREADS;

    /* Find indices to compute */
    indices[0] = 0;

    for(int i = 1;i < NUMTHREADS * 2 ; i++)
    {
	if(i % 2 == 1)
        {
	    indices[i] = indices[i - 1] + len - 1;
 
            if(excess)
            {
		indices[i] += 1;
                excess--;
            }
        }
        else
        {
	    indices[i] =  indices[i - 1] + 1;
        }
    }

    Arr_data.indices = indices;

    /* Read the array */
    read_array(Arr_data.arr, size, &m_sum, &m_max);

    for(int i = 0;i < size    
    printf("\nResult found while reading : Sum : %d, Max : %d\n", m_sum, m_max);

    /* Create an array of structures, each element with different indices, static values  */
    ThreadArr Array[NUMTHREADS];

    for(int i = 0;i < NUMTHREADS;i++)
    {
	Arr_data.index = i * 2;
	Array[i] = Arr_data;
	pthread_create(&threads[i], NULL, sum_max, (void *)&Array[i]);
    }

    /* Wait for the threads */
    for(int i = 0;i < NUMTHREADS;i++)
    {
	pthread_join(threads[i], NULL);
    }
    
    printf("\nResult after threading : Sum : %d, Max : %d\n", sum, max);

    return 0;
}
