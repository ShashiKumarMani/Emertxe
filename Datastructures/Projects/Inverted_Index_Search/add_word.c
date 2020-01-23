/*
    Function to add a word into the database
 */

#include "header.h"

int add_word(char *word, char *file_name, Wordnode *database[])
{
    int index = hashfunction(word);
    Wordnode *temp = NULL, *prev = NULL;
    Filenode *temp2 = NULL, *prev2 = NULL;

//    printf("Add_word : The word  : %s\n", word);

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
	    while(temp2 && strcmp(temp2->file_name, file_name))
	    {
		prev2 = temp2;
		temp2 = temp2->file_link;
	    }

	    //If file aready present inc word_count
	    if(temp2)
	    {
//		printf("File present\n");
		(temp2->word_count) = temp2->word_count + 1;
	    }
	    //Else create a file node
	    else
	    {
//		printf("File absent\n");
		temp->file_count = temp->file_count + 1;
		prev2->file_link = create_file_node(file_name);
	    }
	}
	//Word absent
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
//	printf("Update done\n");
    }
}
