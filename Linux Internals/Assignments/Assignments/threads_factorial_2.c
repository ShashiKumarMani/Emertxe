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

void *factorial1(void *data1)
{
    unsigned long int *data = data1, res = 1, i;

    for(i = data[0];i >= data[1];i--)
    {
	res *= i;
	printf("1 : res - %lu\n", res);
    } 
    return (void *)(long)res;
}

void *factorial2(void *data2)
{
    unsigned long int res = 1, i, *data = data2;

    for(i = data[2];i >= data[3];i--)
    {
	res *= i;
	printf("2 : res - %lu\n", res);
    }

//    data->num2 = res;
    return (void *)(long)res;
}

void *factorial3(void *data3)
{
    unsigned long int res = 1, i, *data = data3;

    for(i = data[4];i >= data[5];i--)
    {
	res *= i;
	printf("3 : res - %lu\n", res);
    }
//    data->num3 = res;
    return (void *)(long)res;
}

int main()
{
    unsigned long *data, res1, res2, res3;
    pthread_t tid1, tid2, tid3;
    int size, excess;

    data = malloc(sizeof(long) * NUMTHREADS * 2);

    /* Read value */
    printf("Enter the value : ");
    scanf("%lu", data + 0);

    size = *(data + 0) / 3;
    excess = *(data + 0) % 3;

    printf("Size - %d Excess - %d\n", size, excess);

    /* Loop */
    data[1] = data[0] - size + 1;

    if(excess)
    {	
	data[1] -= 1;
	excess--;
    }

    data[2] = data[1] - 1;
    data[3] = data[2] - size + 1;

    if(excess)
    {
	data[3] -= 1;
    }
    data[4] = data[3] - 1;
    data[5] = 1;

    /* Loop */

//    printf("Struct - %lu %lu %lu %lu %lu %lu\n", data[0], data[1], data[2], data[3], data[4], data[5]);

    pthread_create(&tid1, NULL, factorial1, (void *)data);
    pthread_create(&tid2, NULL, factorial2, (void *)data);
    pthread_create(&tid3, NULL, factorial3, (void *)data);

    pthread_join(tid1, (void *)&res1);
    pthread_join(tid2, (void *)&res2);
    pthread_join(tid3, (void *)&res3);
   
    //printf("res1:%lu res2:%lu res3:%lu\n", res1, res2, res3);

    printf("%lu\n", res1 * res2 * res3);
    
    return 0;
}
