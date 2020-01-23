/*
    Function to display the contents of the database
*/

#include "header.h"

int save_database(Wordnode *database[], char *backupfile)
{
    printf("Creating a backup\n");
    Wordnode *temp_word = NULL;
    Filenode *temp_file = NULL;

    FILE *backup = fopen(backupfile, "wb");
    if(backup == NULL)
    {
	printf("ERROR : File open\n");
	return FAILURE;
    }

    char empty = '\0', comma = ' ';

    //Loop through the database
    for(int i = 0;i < 28;i++)
    {
	fprintf(backup, "%d ", i);

	//If data present
	if(database[i])
	{
	    temp_word = database[i];

	    while(temp_word)
	    {
		//Write the word and file count
		fwrite(temp_word->word, strlen(temp_word->word), 1, backup);
		fwrite(&comma, 1, 1, backup);
		fprintf(backup, "%d ", temp_word->file_count);

		temp_file = temp_word->file_link;

		//Loop through all files
		while(temp_file)
		{
		    //Write the file name and word count
		    fwrite(temp_file->file_name, strlen(temp_file->file_name), 1, backup);
		    fwrite(&comma, 1, 1, backup);
		    fprintf(backup, "%d ", temp_file->word_count);
		    temp_file = temp_file->file_link;
		}

		temp_word = temp_word->word_link;
	    }
	    
	    fwrite(&empty, 1, 1, backup);
	    fwrite("\n", 1, 1, backup);
	}
	else
	{
	    fwrite(&empty, 1, 1, backup);    
	    fwrite("\n", 1, 1, backup);
	}
    }
}
