/*
    
    Title - thread_factorial
    Author - Shashikumar M
    Date - 5 February 2020
    Description - Program to find factorial of the given number using threads.

 */
#include <stdio.h>
#include <pthread.h>
#define THREADNUM 3

typedef struct{
    unsigned long int num, num2, num3;
    int size;
}Factorial;

void *factorial1(void *data1)
{
    Factorial *data = data1;

    unsigned long int res = 1, i;

    for(i = data->num;i > data->num - data->size;i--)
    {
	res *= i;
	printf("1 : res - %lu\n", res);
    } 
//    data->num = res;
    return (void *)(long)res;
}

void *factorial2(void *data2)
{
    Factorial *data = data2;

    unsigned long int res = 1, i;

    for(i = data->num2;i > data->num2 - data->size;i--)
    {
	res *= i;
	printf("2 : res - %lu\n", res);
    }

//    data->num2 = res;
    return (void *)(long)res;
}

void *factorial3(void *data3)
{
    Factorial *data = data3;
    unsigned long int res = 1, i;

    for(i = data->num3;i > data->num3 - data->size;i--)
    {
	res *= i;
	printf("3 : res - %lu\n", res);
    }
//    data->num3 = res;
    return (void *)(long)res;
}

int main()
{
    Factorial var;
    int excess;
    unsigned long res1, res2, res3;
    pthread_t tid1, tid2, tid3;

    printf("Enter the value : ");
    scanf("%lu", &var.num);

    printf("The number entered is : %lu\n", var.num);

    var.size = var.num / THREADNUM;
    excess = var.num % THREADNUM;

    printf("Size - %d Excess - %d\n", var.size, excess);

    if(excess)
    {	
	var.num2 = var.num - var.size + 1;
	excess--;
    }
    else
	var.num2 = var.num - var.size;

    if(excess)
	var.num3 = var.num2 - var.size + 1;
    else
	var.num3 = var.num2 - var.size;

    printf("Struct - %lu %lu %lu\n", var.num, var.num2, var.num3);

    pthread_create(&tid1, NULL, factorial1, (void *)&var);
    pthread_create(&tid2, NULL, factorial2, (void *)&var);
    pthread_create(&tid3, NULL, factorial3, (void *)&var);

    pthread_join(tid1, (void *)&res1);
    pthread_join(tid2, (void *)&res2);
    pthread_join(tid3, (void *)&res3);
   
    printf("var1:%lu var2:%lu var3:%lu\n", var.num, var.num2, var.num3);
    printf("res1:%lu res2:%lu res3:%lu\n", res1, res2, res3);

    printf("%lu\n", res1 * res2 * res3);

    return 0;
}
