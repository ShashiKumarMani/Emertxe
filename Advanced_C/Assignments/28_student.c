/*
    Title : Structures
    Author : Shashi Kumar M
    Date : 19 November 2019
    Description : Program to read student details 
		  Input - Read number of students, marks.
		  Output - Print student details and grade.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int max_len;

struct student{
    
    char name[50];
    int *arr;
    char grade;
};

//Function to print header
void print_header(int num_sub)
{
    printf("---------------------------------------------------------------------------------\n");

    printf("%20s","Name");

    for(int i = 0;i < num_sub;i++)
    {
        printf("\tSub%i", i + 1);
    }
    printf("\tGrade\n");

    printf("----------------------------------------------------------------------------------\n");

}

//Function to implement strcmp function
int my_strcmp(char *str1, char *str2)
{
    int sum = 0;

    //Loop through the strings
    while(str1 || str2)
    {
	//If equal
	if(*str1 == *str2)
	{
	    sum = 0;

	    str1++;
	    str2++;
	
	    if(str1 == NULL && str2 == NULL)
	    {
		return sum;
	    }
	}
	else if(*str1 > *str2)
	{
	    return *str1;
	}
	else
	{
	    return -*str2;
	}
    }

}

//Function to find average and grade
void read_details(struct student *p, int num)
{
    float average = 0;
    int j;

    //Read name and marks
    printf("\nEnter the name : ");
    scanf("%s", p->name);

    __fpurge(stdin);

    p->arr = malloc(num * sizeof(int));

    printf("Enter %d subject marks : ", num);
 
    for(j = 0;j < num;j++)
    {
	scanf("%d", &p->arr[j]);
        average += p->arr[j];
    }
 
    average = average / num;
 
    //Find grade
    if(average > 90)
    {
	p->grade = 'A';
    }
    else if(average > 80)
    {
        p->grade = 'B';
    }
    else if(average > 70)
    {
        p->grade = 'C';
    }
    else if(average > 60)
    {
        p->grade = 'D';
    }
    else
    {
        p->grade = 'E';
    }
}

//Function to print details of students
void print_details(struct student *p, int num_sub)
{
    printf("\n%20s", p->name);

    for(int i = 0;i < num_sub;i++)
    {
	printf("\t%5d", p->arr[i]);
    }

    printf("\t%5c", p->grade);
}

//Free DMA
void free_memory(struct student *p, int num)
{
    for(int i = 0;i < num;i++)
    {
	free(p[i].arr);
    }
}

int main()
{
    char option, stuname[50];
    int num, num_sub, i, choice;

    do
    {
	//Read values
	printf("\nEnter the number of students : ");
	scanf("%d", &num);

	printf("Enter the number of subjects : ");
	scanf("%d", &num_sub);

	struct student s_array[num];

	for(i = 0;i < num;i++)
	{
	    printf("\nEnter student %d details \n", i + 1);

	    //Read details and find average, grade
	    read_details(&s_array[i], num_sub);

	    __fpurge(stdin);
	}

	printf("\nMenu\n1. All student details\n2. Particular student detail\n\nEnter your choice : ");
	
	__fpurge(stdin);

	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		    //Print header and details
		    print_header(num_sub);

		    for(i = 0;i < num;i++)
		    {
			print_details(&s_array[i], num_sub);
		    }
	
		break;
	    
	    case 2:
		    //Search a particular student and print details
		    printf("Enter the name : ");
		    scanf("%s", stuname);

		    for(i = 0;i < num;i++)
		    {
			if(my_strcmp(stuname, s_array[i].name) == 0)
			{
			    print_header(num_sub);
			    print_details(&s_array[i], num_sub);
			    break;
			}
		    }
		    if(i == num)
		    {
			printf("Student not found\n");
		    }		

		break;
	    
	    default:
		    printf("ERROR : Invalid choice\n");
	}

	//Free DMA
	free_memory(s_array, num);

	__fpurge(stdin);

	//Prompt to continue or not
	printf("\n\nDo you want to continue? [Yy | Nn] : ");
	scanf("%c", &option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
