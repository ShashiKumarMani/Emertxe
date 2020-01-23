/*
    Function to create a database
*/

#include "header.h"

int create_database(char *argv[], Filenames **filenames, Wordnode *database[])
{
    //Assuming the word length is <= 50
    char word[SIZE];
    int i = 1;
    FILE *fptr = NULL;
    
    //Loop through the filenmes
    while(argv[i])
    {
//	printf("I : %d\n", i);
    
	if(isduplicate(*filenames, argv[i]) == FAILURE)
	{
	    printf("ERROR : Duplicate file found. Skipping the file.\n");
	    i++;
//	    printf("--i - %d\n", i);
	    continue;
	}
	else
	{
//	    printf("File not duplicate\n");
	}

	insert_last(filenames, argv[i]);

//	printf("File inserted into LL\n");

	//Check if file valid files without extension?
	if((strchr(argv[i], '.') == NULL) || (fptr = fopen(argv[i], "rb")) == NULL)	
	{
	    printf("ERROR : File Open\n");
	    return FAILURE;
	}	    

//	printf("==>	File valid\n");

	//Loop through words
	while(fscanf(fptr, "%s", word) != -1)
	{
//	    printf("\nThe word : %s : %c\n", word, word[0]);

	    //All words with atleast two characters
//	    if(strlen(word) > 1)
//	    {
//		printf("Word valid\n");
		add_word(word, argv[i], database);
//	    }
	}
	i++;
    }
    return SUCCESS;
}
