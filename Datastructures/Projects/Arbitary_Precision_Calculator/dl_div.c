/*
    Function to implement linked list division
*/

#include "Dlist.h"

int dl_div(Dlink **head1, Dlink **tail1, Dlink **head2, Dlink **tail2, Dlink **head3, Dlink **tail3)
{
    Dlink *temp1 = *tail1, *temp2 = *tail2, *temp_h = NULL, *temp_t = NULL;
    int  data1, data2;
    float diff_1 = 0, diff_2 = 0;

    //Traverse the list and compute the decimals
    while(temp1 != *head1 || temp2 != *head2)
    {	
	data1 = temp1 ? temp1->data : 1;
	data2 = temp2 ? temp2->data : 1;

	for(int i = 0;i < 0xFFFFFFF;i++)
	{
	}

	printf("data1 : %d, data2 : %d\n", data1, data2);

	diff_1 += 10 - data1;
	diff_2 += 10 - data2;
	
	temp1 = temp1 ? temp1->prev : NULL;
	temp2 = temp2 ? temp2->prev : NULL;

	//Add one function	
	temp1 ? temp1->next ? add_one(head1, tail2, temp1) : 1 : 1;
	temp2 ? temp2->next ? add_one(head2, tail2, temp2) : 1 : 1;

	printf("temp1:%p|head1:%p || temp2:%p|head2:%p\n", temp1, *head1, temp2, *head2);
	if(temp1 == *head1)
	{
	    printf("List1 - head\n");
	}
	if(temp2 == *head2)
	{
	    printf("List2 - head\n");
	}

	diff_1 /= 10;
	diff_2 /= 10;
    }

    printf("The final diff1 : %f\n", diff_1);
    printf("The final diff2 : %f\n", diff_2);

    temp1 ? printf("temp1 - %d\n", temp1->data) :1;
    temp2 ? printf("temp2 - %d\n", temp2->data) :1;
   
    data1 = temp1 ? temp1->data :1;
    data2 = temp2 ? temp2->data :1;

    printf("Res - %f\n", (data1 - diff_1) / (data2 - diff_2));
}
