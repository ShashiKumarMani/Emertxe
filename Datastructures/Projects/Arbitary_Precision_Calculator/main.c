/*
    Project 1 : Arbitary Precision Calculator

 */
#include "Dlist.h"

int main(int argc, char *argv[])
{
    Dlink *head1 = NULL, *head2 = NULL, *head3 = NULL, *tail1 = NULL, *tail2 = NULL, *tail3 = NULL;
    int sum;
    char operator;

    if(argc == 1)
    {
	printf("Enter the expression\n");
	return 0;
    }

    if(dl_cla(argv[1], &head1, &tail1, &head2, &tail2, &operator) == FAILURE)
    {
	printf("ERROR : Enter the expression in correct format\n\n<Number 1> <Operator> <Number 2>\n\nOperators : \n'+' - Addition\n'-' - Subtraction\n'*' - Multiplication\n'/' - Division\n");
	return 0;
    }

    printf("\nNumber 1 : ");
    print_list(head1);

    printf("\nNumber 2 : ");
    print_list(head2);

    switch(operator)
    {
	case '+':
	    printf("Addition\n");
	    
	    dl_add(&head1, &tail1, &head2, &tail2, &head3, &tail3);

	    printf("Result Addition : ");
	    print_list(head3);
	    break;
	
	case '-':
	    printf("Subtraction\n");
	    
	    dl_sub(&head1, &tail1, &head2, &tail2, &head3, &tail3);

	    printf("Result Subtraction : ");
	    print_list(head3);
	    break;
	
	case '*':
	    printf("Multiplication\n");
	    
	    dl_mul(&head1, &tail1, &head2, &tail2, &head3, &tail3);

	    printf("Result Multiplication : ");
	    print_list(head3);
	    break;

	case '/':
	    printf("Division\n");

	    //dl_div(&head1, &tail1, &head2, &tail2, &head3, &tail3);
	    if(loop_div(&head1, &tail1, &head2, &tail2, &head3, &tail3) == FAILURE)
	    {
		printf("ERROR : Division by zero\n");
	    }
	    else
	    {
		printf("Result Division : ");
		print_list(head3);
	    }		
    }
	    
	delete_list(&head3, &tail3);
    return 0;
}
