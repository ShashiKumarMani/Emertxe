/*
    Title : Binary Search
    Author : Shashi Kumar M
    Date : 13 November 2019
    Description : Program to implement binary search for all datatypes.
		  Input - Read datatype, read array size and array elements.
		  Output - Print whether key element found or not, if found print position.
	
 */

#include <stdio.h>
#include <stdlib.h>

#define BINARY_SEARCH(ptr, size, type, format)				\
{								\
    int begin = 1, end = size - 1, mid, i, j;			\
    type temp;							\
								\
    for(i = 1;i < size;i++)					\
    {								\
	for(j = 1;j< size - i - 1;j++)				\
	{							\
	    if(*((type *)ptr + j) > *((type *)ptr + j + 1))		\
	    {							\
		temp = *((type *)ptr + j);				\
		*((type *)ptr + j) = *((type *)ptr + j + 1);		\
		*((type *)ptr + j + 1) = temp;			\
	    }							\
	}							\
    }								\
    \
    printf("The sorted array : ");				\
    for(i = 1;i < size;i++)					\
    {								\
	printf(format, *((type *)ptr + i));			\
    }								\
    while(begin <= end)						\
    {								\
	mid = (begin + end) / 2;				\
								\
	if(*((type *)ptr + mid) == *((type *)ptr))		\
	{							\
	    return mid;						\
	}							\
	else if(*((type *)ptr + mid) > *(type *)ptr)		\
	{							\
	    end = mid - 1;					\
	}							\
	else							\
	{							\
	    begin = mid + 1;				    	\
	}							\
    }								\
    return -1;						\
}

//Function to read array
int read_array(void *ptr, int size, int choice)
{
    int i, pos;
    printf("Enter array elements: ");

    switch(choice)
    {
	case 1:
		for(i = 1;i < size;i++)
		{
		    scanf("%d", (int *)ptr + i);
		}

		printf("Enter key element : ");
		scanf("%d", (int *)ptr);

		BINARY_SEARCH(ptr, size, int, "%d ");
	    break;
	case 2:
		for(i = 1;i < size;i++)
		{
		    scanf("%hd", (short *)ptr + i);
		}

		printf("Enter key element : ");
		scanf("%hd", (short *)ptr);

		BINARY_SEARCH(ptr, size, short, "%hd ");
	    break;
	case 3:
		for(i = 1;i < size;i++)
		{
		    scanf("%f", (float *)ptr + i);
		}
		    
		printf("Enter key element : ");
		scanf("%f", (float *)ptr);

		BINARY_SEARCH(ptr, size, float, "%f ");
	    break;
	case 4:
		
		for(i = 1;i < size;i++)
		{
		    scanf("%lf", (double *)ptr + i);
		}
		
		printf("Enter key element : ");
		scanf("%lf", (double *)ptr);
		
		BINARY_SEARCH(ptr, size, double, "%lf ");
	    break;
    }
}

int main()
{
    char option;
    int choice, array_size, pos;
    void *ptr = NULL;

    do
    {
	printf("\nEnter datatype : \n1. Int\n2. Short\n3. Float\n4. Double\n\nEnter your choice : ");
	scanf("%d", &choice);

	printf("\nEnter the array size : ");
	scanf("%d", &array_size);

	//Execute choice
	switch(choice)
	{
	    case 1:
		    ptr = malloc((array_size + 1) * sizeof(int));
		    pos = read_array(ptr, array_size + 1, choice);

      	        break;
	    
	    case 2:
		    ptr = malloc((array_size + 1) * sizeof(short));
		    pos = read_array(ptr, array_size + 1, choice);
		
		break;
	    
	    case 3:
		    ptr = malloc((array_size + 1) * sizeof(float));
		    pos = read_array(ptr, array_size + 1, choice);
	    
		break;

	    case 4:
		    ptr = malloc((array_size + 1) * sizeof(double));
		    pos = read_array(ptr, array_size + 1, choice);

		break;
	    default:
		    printf("ERROR : Invalid choice\n");
		    pos = -1;
	}	    

	if(pos == -1)
	{
	    printf("\nERROR : Element not found\n");
	}
	else
	{
	    printf("\nElement found at position %d\n", pos - 1);
	}
    
	free(ptr);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	getchar();
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
