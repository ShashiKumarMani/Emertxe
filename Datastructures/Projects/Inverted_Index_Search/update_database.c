/*
    Function to update database
*/

#include "header.h"

int update_database(Wordnode *database[], Filenames **filelist, char *backup)
{
    printf("\nINFO : Updating database\n");

    FILE *fptr = NULL; 
    Filenames *file_temp = *filelist, *newlist = NULL, *temp = NULL;
    char data[50], word[50], filename[50];
    int index, filecount;

    //Open the file
    if((fptr = fopen(backup, "rb")) == NULL)
    {
	return FAILURE;
    }

    //Read contents of the file space seperated by space
     while(fscanf(fptr, "%s", data) != EOF)
     {
         index = atoi(data);
//         printf("Index - %d : ", index);
 
         while(fscanf(fptr, "%s", word))
	 {
	     if(word[0] == '\0')
	     {
	//	 printf("NULL, BREAK\n");
		 break;
	     }

//	     printf("Word - %s ", word);

	     //Update the database index 
	     fscanf(fptr, "%s", data);
	     filecount = atoi(data);
	  //   printf("File count - %d\n", filecount);

	     for(int i = 0;i < filecount;i++)
	     {
		 fscanf(fptr, "%s", filename);
	//	 printf("filename-%d - %s : ", i, filename);

		 if(isduplicate(*filelist, filename) == SUCCESS)
		 {
		    update_word(index, word, filename, &newlist, database);
		 }
		 else
		 {
		     printf("Index : [%2d] Duplicate data found\n", index);
		 }

		 fscanf(fptr, "%s", data);
	//	 printf("WC - %s\n", data);
	     }

	 }
    }
	
    temp = newlist;

    //Copy the newfiles to the database's filelist
    while(temp)
    {
//	printf("%s\n", temp->filename);
	insert_last(filelist, temp->filename);
	temp = temp->link;
    }    
}

