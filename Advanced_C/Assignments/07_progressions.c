/*
    Title : Print AP GP HP progressions
    Author : Shashi Kumar M
    Date : 26 September 2019
    Description : Print AP, GP and Hp progression.
		  Input : First term, common ratio, number of terms.
		  Output : Print the progressions.
 */

#include<stdio.h>

int main()
{
    //Declaration and read values
    int first_term, ratio, num_terms, sum1, sum2, i;

    //read first term
    printf("Enter the first term : ");
    scanf("%d", &first_term);

    //read common ratio
    printf("Enter the common ratio/difference : ");
    scanf("%d", &ratio);

    //read number of terms
    printf("Enter the number of terms : ");
    scanf("%d", &num_terms);

    //header
    printf("\nAP\tGP\tHP\n");

    //if first term is greater than 0
    if (first_term > 0)
    {
	//Print progressions
	for(i = 0, sum1 = sum2 = first_term;i < num_terms;i++)
	{
	    printf("%d\t%d\t%0.2f\n", sum1,sum2,1.0 / sum1);
	    sum1 = sum1 + ratio;
	    sum2 = sum2 * ratio;
	}
	printf("\n");
    }
    else
    {
	printf("ERROR : First term should be positive\n");
    }

    return 0;
}
