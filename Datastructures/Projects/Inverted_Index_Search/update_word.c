/*
    Function to add a word into the database
 */

#include "header.h"

int update_word(int index, char *word, char *file_name, Filenames **newlist, Wordnode *database[])
{
    Wordnode *temp = NULL, *prev = NULL;
    Filenode *temp2 = NULL, *prev2 = NULL;
    //Filenames *newfiles = NULL;

//    printf("\nUpdate word\n");

    //If temp already occupied traverse the database
    if(database[index])
    {
//	printf("Index occupied\n");

	temp = database[index];

	//Find if word present
	while(temp && strcmp(temp->word, word))
	{
	    prev = temp;
	    temp = temp->word_link;
	}	    

	//Word already present
	if(temp)
	{   
//	    printf("Word Present\n");
	    temp2 = temp->file_link;
	    
	    //Traverse the file link and find if file present
	    while(temp2->file_link)
	    {
		temp2 = temp2->file_link;
	    }

//	    printf("Creating a file node, adding name to newlist\n");

	    //Incremnt filecount of word node
	    temp->file_count = temp->file_count + 1;

	    //Add the file node at the end and add filename to newfile
	    temp2->file_link = create_file_node(file_name);

	    //If file not added add it to the list
	    if(isduplicate(*newlist, file_name) == SUCCESS)
		insert_last(newlist, file_name);
	}
	else
	{
//	    printf("Word Absent\n");
	    prev->word_link = create_word_node(word, file_name);
	}
    }
    //Create a new word node
    else
    {
//	printf("Index Empty\n");
	database[index] = create_word_node(word, file_name);

	if(isduplicate(*newlist, file_name) == SUCCESS)
	    insert_last(newlist, file_name);

//	printf("Update done\n");
    }
}
