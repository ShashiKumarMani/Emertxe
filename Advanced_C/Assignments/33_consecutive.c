/*

    Title : Consecutive
    Author : Shashi Kumar M
    Date : 18 November 2019
    Description : Take 8 consecutive bytes of memory, Provide a menu to manipulate or display the values.
		  Input - Read datatype, index.
		  Output - Print result accn. to the menu

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define SIZE 8

//Function to read the datatype
int data_type()
{
    int type;

    printf("\nEnter datatype :\n 1. Char \n 2. Short int\n 3. Int \n 4. Float \n 5. Double\n\nEnter your choice : ");
    scanf("%d", &type);   

    __fpurge(stdin);

    return type;
}

//Function to read the memory
int find_pos(char *indicator, int size)
{
    int prev = 0, pres = 0, i, sum = 0;

    for(i = 0;i < SIZE;i++)
    {
	//If byte is empty
	if(*(indicator + i) == -1)
	{
	    sum++;

	    if(sum == 1)
		prev = i;
	}
	else
	{
	    sum = 0;
	}

	if(sum == size)
	{
	    return prev;
	}
    }
    return -1;
}

//Function to set indicator
void set_indicator(char *indicator, int pos, int size, int type)
{
    for(int i = pos;i < (pos + size);i++)
    {
	*(indicator + i) = type;
    }
}

//Function to add data and set indicator
void add_data(void *ptr, char *indicator)
{
    int pos;

    //Add element
    switch(data_type())
    {
	case 1:	
		//Find empty space and read value else error
		pos = find_pos(indicator, 1);

		if(pos == -1)
		{
		    printf("Memory not available\n");
		    return;
		}
		else
		{
		    printf("Enter the char value : ");
		    scanf("\n%c", (char *)ptr + pos);
		}
		__fpurge(stdin);

		*(indicator + pos) = 1;
    		break;
	case 2:
                 pos = find_pos(indicator, 2);
 
                 if(pos == -1)
                 {
                     printf("Memory not available\n");
                     return;
                 }
                 else
                 {
                     printf("Enter the short value : ");
                     scanf("%hd", (short *)((char *)ptr + pos));
		 }

		 //set from pos - > pos + sizeof(data) = case;
		 set_indicator(indicator, pos, 2, 2);
	    break;
	case 3:
                 pos = find_pos(indicator, 4);

                 if(pos == -1)
                 {
                     printf("Memory not available\n");
                     return;
                 }
                 else
                 {
                     printf("Enter the integer value : ");
                     scanf("%d", (int *)((char *)ptr + pos));
		 }

		 set_indicator(indicator, pos, 4, 3);
		 break;
	case 4:
                 pos = find_pos(indicator, 4);

                 if(pos == -1)
                 {
                     printf("Memory not available\n");
                     return;
                 }
                 else
                {
                     printf("Enter the float value : ");
                     scanf("%f", (float *)((char *)ptr + pos));
		}
		
		 set_indicator(indicator, pos, 4, 4);
	    break;
	case 5:
                 pos = find_pos(indicator, 8);
 
                 if(pos == -1)
                 {
                     printf("Memory not available\n");
                     return;
                 }
                 else
                 {
                     printf("Enter the double value : ");
                     scanf("%lf", (double *)((char *)ptr + pos));
		 }

		 set_indicator(indicator, pos, 8, 5);

     	    break;
	default:
	    printf("ERROR : Invalid choice\n");
	    break;

    }
}

//Function to remove data from array
void remove_data(char *indicator)
{
    int i, j, flag = 0, type = data_type(), size;

    switch(type)
    {
	case 1:
		size = 1;
		break;
	case 2:
		size = 2;
		break;
	case 3:
		size = 4;
		break;
	case 4:
		size = 4;
		break;
	case 5:
		size = 8;
		break;
	default :
		printf("ERROR : Invalid choice of datatype\n");
		return;
    }

    //Loop through indicator array and remove value
    for(i = 0;i < SIZE;i++)
    {
	if(*(indicator + i) == type)
	{
	    flag = 1;

	    for(j = i;j < i + size;j++)
	    {
		*(indicator + j) = -1;
	    }
	}
    }

    //If value doesnt exist
    if(!flag)
    {
	printf("Value doesn't exist\n");
    }
    else
    {
	printf("All variables of the datatype removed\n");
    }
}

//Function to print array elements
void display_elements(void *ptr, char *indicator)
{
    int i = 0;

    printf("\nElements in array : \n\n");

    //Loop and print the values in array and inc. i + datatype
    while(i < SIZE)
    {
	//Typecast ptr to char, shift, cast to datatype dereference
	switch(*(indicator + i))
	{
	    case 1:
		    printf("---> %c\n", *((char *)ptr + i));
		    i++;
		break;
	    case 2:
		    //ptr = (char *)ptr + i;
		    printf("--|\n--|> %hd\n", *((short *)((char *)ptr + i)));
		    i += 2;
		break;
	    case 3:
		    printf("--|\n--|\n--|\n--|> %d\n", *((int *)((char *)ptr + i)));
		    i += 4;
		break;
	    case 4:
		    printf("--|\n--|\n--|\n--|> %f\n", *((float *)((char *)ptr + i)));
		    i += 4;
		break;
	    case 5:
		    printf("--|\n--|\n--|\n--|\n--|\n--|\n--|\n--|> %lf\n", *((double *)((char *)ptr + i)));
		    i += 8;
		break;
	    default :
		    printf("---> --EMPTY--\n");
		    i++;
	}
    }
}

int main()
{
    char option, *indicator = NULL;
    int choice, type, flag, i;
    void *ptr = NULL;

    do
    {
	//Allocate 8 bytes
	ptr = malloc(8);
	indicator = malloc(8);
	
	//Initialise indicators
	for(i = 0;i < 8;i++)
	{
	    indicator[i] = -1;
	}

	printf("\nStart : 8 Bytes allocated. \n");
	
	flag = 1;

	//Loop till flag is zero
	while(flag)
	{
	    printf("\n##### Menu #####\n\n 1. Add element\n 2. Remove element\n 3. Display element\n 4. Exit\n\nEnter your choice : ");
	    scanf("%d", &choice);

	    switch(choice)
	    {
		case 1:
			//Add data
		        add_data(ptr, indicator);
			break;
		case 2:
			//Remove data
		        remove_data(indicator);	
			break;
		case 3:
			//Display element
			display_elements(ptr, indicator);
			break;
		case 4:
			//Exit loop
			flag = 0;
			break;
		default :
		        printf("ERROR : Invalid choice\n");
			flag = 0;
	    }
	}

	free(ptr);

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
