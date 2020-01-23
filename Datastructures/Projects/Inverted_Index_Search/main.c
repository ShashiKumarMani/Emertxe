
#include "header.h"

int main(int argc, char *argv[])
{
    int choice;
    char word[SIZE], filename[SIZE], option;
    Wordnode *database[28] = {NULL};
    Filenames *filenames = NULL;

//    printf("Arg count - %d\n", argc);

    if(argc < 2)
    {
	printf("ERROR : Enter file names\n");
	return 0;
    }

    while(1)
    {
	printf("\n\n##### Database Menu #####\n\n1. Create Database\n2. Display Database\n3. Updata Database\n4. Search Database\n5. Save Database\n6. Exit\n\nEnter your choice : ");
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		if(create_database(argv, &filenames, database) == SUCCESS)
		{
		    printf("\nINFO : Database created\n");
		}
		else
		{
		    printf("\nERROR : Database not created\n");
		}
		break;
	    case 2:
		display_database(database);
		break;
	    case 3:
		//Read file and update
		printf("\nEnter the name of the backup file : ");
		scanf("%s", filename);
		update_database(database, &filenames, filename);

		break;
	    case 4:
		printf("\nEnter the word : ");
		scanf("%s", word);

		if(search_database(word, database) == FAILURE)
		{
		    printf("\nERROR : Word Absent\n");
		}
		break;
	    case 5:
		//Save the database
		printf("\nEnter the backupfile name : ");
		scanf("%s", filename);
		choice = save_database(database, filename);

		if(choice == FAILURE)
		{
		    printf("\nERROR : Backup file doesnt exist\n");
		}

		break;
	    case 6:
		printf("\nExiting....\n");
		return 0;
		break;
	    default :
		printf("\nERROR : Invalid choice\n");
	}
    }
}
