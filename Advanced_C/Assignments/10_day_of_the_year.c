/*
    Title : Print the day of the year 
    Author : Shashi Kumar M
    Date : 27 September 2019
    Description : Program to print the day of the year.
		  Input - Start_day, Number_of_days
		  Output - Print the day
 */

#include<stdio.h>

int main()
{
    //declare variables
    int start_day,num_days;
    char option;
    
    do
    {
	//Print the menu and read start day
	printf("\nEnter the start day\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\nEnter your choice : ");
	scanf("%d",&start_day);

	//Check for errors
	if (start_day > 0 && start_day < 8)
	{
	    //Read number of days
	    printf("Enter number of days : ");
	    scanf("%d",&num_days);

	    //Print the day
	    printf("The day is : ");

	    //Switch to print result 
	    //Loop - sum should be less than equal to 7 i.e., within the week
	    //Int day = (start_day + num_days) % 7;
	    switch((start_day + num_days - 1) % 7)
	    {
		case 1: 
		        printf("Sunday\n");
			break;
		case 2:
		        printf("Monday\n");
			break;
		case 3:
			printf("Tuesday\n");
			break;
		case 4:
		        printf("Wednesday\n");
			break;
		case 5:
		        printf("Thursday\n");
			break;
		case 6:
		        printf("Friday\n");
			break;
		case 0:
		        printf("Saturday\n");
			break;
	    }
	}
	else
	{
	    printf("ERROR : start day should be between 1 and 7\n");
	}

	//Prompt to continue
	printf("Do you want to continue ? ");
	getchar();
	scanf("%c",&option);

    }while(option == 'Y' || option == 'y');

    return 0;
}
