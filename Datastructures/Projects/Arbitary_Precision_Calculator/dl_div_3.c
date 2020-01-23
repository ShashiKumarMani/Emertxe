/*
    Function to perform division using linked list
*/

#include "Dlist.h"

int loop_div(Dlink **head1, Dlink **tail1, Dlink **head2, Dlink **tail2, Dlink **head3, Dlink **tail3)
{
    Dlink *temp1_h = NULL, *temp1_t = NULL, *temp2_h = NULL, *temp2_t = NULL, *inc_h = NULL, *inc_t = NULL;
    int count = PRECISION;

    if((*head2)->data == 0)
    {
	return FAILURE;
    }

    insert_first(&inc_h, &inc_t, 1);

    //Find range - exponential
    while(inc_h->data != 0 && inc_h->data != NEGATIVE)
    {	
	dl_mul(head2, tail2, &inc_h, &inc_t, &temp1_h, &temp1_t);
	dl_sub(head1, tail1, &temp1_h, &temp1_t, &temp2_h, &temp2_t);
    
	//If the subtraction is not negative
	if(temp2_h->data != NEGATIVE)
	{
	    //Multiply the value by 10
	    insert_last(&inc_h, &inc_t, 0);
	}
	else
	{
	    //Else divide by 10
	    if(inc_h->prev)
	    {
		delete_last(&inc_h, &inc_t);
	    }
	    break;
	}

	delete_list(&temp1_h, &temp1_t);
	delete_list(&temp2_h, &temp2_t);
    }

    //Copy inc->rem
    make_copy(head3, tail3, inc_h, inc_t);

    //Find magnitude part - stored in head3
    while(inc_h->data != 0)
    {
	// temp2 = Number - (divisor * head3-result)
	dl_mul(head2, tail2, head3, tail3, &temp1_h, &temp1_t);    
	dl_sub(head1, tail1, &temp1_h, &temp1_t, &temp2_h, &temp2_t);
	    
	delete_list(&temp1_h, &temp1_t);

	//If result not negative then add inc to result
	if(temp2_h->data != NEGATIVE)
	{
	    //		Rem += inc;
	    dl_add(head3, tail3, &inc_h, &inc_t, &temp1_h, &temp1_t);
	    delete_list(head3, tail3);

	    *head3 = temp1_h, *tail3 = temp1_t;
	    temp1_h = temp1_t = NULL;
	}	
	//Else divide inc by 10
	else
	{
	    //	    remainder -= inc;
	    dl_sub(head3, tail3, &inc_h, &inc_t, &temp1_h, &temp1_t);
	    delete_list(head3, tail3);
	    *head3 = temp1_h, *tail3 = temp1_t;
	    temp1_h = temp1_t = NULL;

	    //	    inc /= 10
	    if(inc_h == inc_t)
		inc_h->data = 0;
	    else
		delete_last(&inc_h, &inc_t);
	}
    
	delete_list(&temp2_h, &temp2_t);
    }

    //Remainder = Number - Divisor * <MAG> - temp2 will hold the remainder
    dl_mul(head2, tail2, head3, tail3, &temp1_h, &temp1_t);
    dl_sub(head1, tail1, &temp1_h, &temp1_t, &temp2_h, &temp2_t);

    delete_list(&temp1_h, &temp1_t);

    //Add decimal
    insert_last(head3, tail3, DOT);

    //No remainder add zero
    if(temp2_h->data == 0)
    {
	insert_last(head3, tail3, 0);
    }
    //Compute decimals
    else
    {
	//int ter;

	//Till remainder zero or till #precision
	while(temp2_h->data != 0 && count > 0)
	{
	    dl_sub(&temp2_h, &temp2_t, head2, tail2, &temp1_h, &temp1_t);
	    
	  //  printf("temp1 : ");
	    //print_list(temp1_h);

	    //If the multiplication is negative add zero to remainder
	    if(temp1_h->data == NEGATIVE)
	    {
	//	printf("NEG\n");
		insert_last(&temp2_h, &temp2_t, 0);
	//	printf("Afer NEG : ");
	//	print_list(temp2_h);
	    }
	    
	    //ter = loop_sub(&temp2_h, &temp2_t, head2, tail2);

	    //printf("Loop-sub res : %d\n", ter);

	    //Find multiple and insert it into result
	    insert_last(head3, tail3, loop_sub(&temp2_h, &temp2_t, head2, tail2));

	    delete_list(&temp1_h, &temp1_t);
	
	    count--;
	}
    }
}
