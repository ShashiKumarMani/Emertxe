/*
    Function to display the contents of the database
*/

#include "header.h"

int display_database(Wordnode *database[])
{
    Wordnode *temp_word = NULL;
    Filenode *temp_file = NULL;
    int size;

    printf("\n\t\t##### Database #####\n\n");
    //Loop through the database
    for(int i = 0;i < 28;i++)
    {
	printf("[%2d] : ", i);

	//If data present
	if(database[i])
	{
	    temp_word = database[i];

	    while(temp_word)
	    {
		size = printf("\n\t'%s' in %d file(s) : \n", temp_word->word, temp_word->file_count);	    

		temp_file = temp_word->file_link;

		//Loop through all files
		while(temp_file)
		{
		    printf("\t\t\t%s : %d times\n", temp_file->file_name, temp_file->word_count);
		    temp_file = temp_file->file_link;
		}
		temp_word = temp_word->word_link;
	    }
	    printf("\n");
	}
	else
	{
	    printf("--No Data--\n");
	}
    }
}
