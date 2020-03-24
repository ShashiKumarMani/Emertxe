/*
    
    Title - thread_factorial
    Author - Shashikumar M
    Date - 5 February 2020
    Description - Program to find factorial of the given number using threads.

 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUMTHREADS 3

/* Function to find factorial */
void *factorial(void *data1)
{
    unsigned long int *data = data1, res = 1, i;
//    printf("-- %lu - %lu -- \n", data[0], data[1]);

    /* Loop and compute factorial */
    for(i = data[0];i >= data[1];i--)
    {
	res *= i;
//	printf("1 : res - %lu\n", res);
    } 
    return (void *)(long)res;
}

/* Main */
int main()
{
    unsigned long *data = NULL;
    pthread_t threads[NUMTHREADS];
    int size, excess;

    /* Array */
    data = malloc(sizeof(long) * NUMTHREADS * 2);

    /* Read value */
    printf("Enter the value : ");
    scanf("%lu", data + 0);

    /* Find size and modulus */
    size = *(data + 0) / NUMTHREADS;
    excess = *(data + 0) % NUMTHREADS;

    /* Find indices to compute */
    for(int i = 1;i < NUMTHREADS * 2;i++)
    {
	if(i != 0 && i % 2 == 1)
	{
	    data[i] = data[i - 1] - size + 1;

	    if(excess)
	    {
		data[i] -= 1;
		excess--;
	    }
	}
	else
	{
	    data[i] = data[i - 1] - 1;
	}
    }

    /* Create threads */
    for(int i = 0;i < NUMTHREADS;i++)
    {
	pthread_create(&threads[i], NULL, factorial, (void *)(data + i * 2));
    }

    /* Wait for the threads to complete get return value */
    for(int i = 0;i < NUMTHREADS;i++)
    {
	pthread_join(threads[i], (void *)(data + i * 2));
    }

    printf("The factorial is %lu\n", *data * *(data +2) * *(data + 4)); 
    free(data);

    return 0;
}
