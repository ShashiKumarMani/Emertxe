/*
    Program to compute sum of two integers.
   
 */

#include <stdio.h>

int sum(int num1, int num2)
{
    return num1 + num2;
}

int main()
{
    int num1, num2;
    printf("Enter two values : ");
    scanf("%d %d", &num1, &num2);
    
    printf("The sum is %d\n", sum(num1, num2));

    return 0;
}
