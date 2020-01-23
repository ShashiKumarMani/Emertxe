/*
    Function to search a word in the database
 */

#include "header.h"

int search_database(char *word, Wordnode *database[])
{
    int index = hashfunction(word);
    Wordnode *temp = database[index];
    Filenode *temp2 = NULL;

    printf("\nINFO : Searching database\n");

    //If index occupied
    if(temp)
    {
	//Traverse the word nodes and find the word
	while(temp && strcmp(temp->word, word))
	{
	    temp = temp->word_link;
	}

	//If the word is found
	if(temp)
	{
	    printf("\n[%2d] : \n\t'%s' in %d file(s) \n", index, word, temp->file_count);
	    temp2 = temp->file_link;

	    //Traverse through the files 
	    while(temp2)
	    {
		printf("\t\t%s : %d time(s)\n", temp2->file_name, temp2->word_count);
		temp2 = temp2->file_link;
	    }
	    printf("\n");

	    return SUCCESS;
	}
    }
    
    return FAILURE;
}

