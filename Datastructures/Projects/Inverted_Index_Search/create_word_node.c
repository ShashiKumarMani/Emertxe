/*
    Create a word node
 */

#include "header.h"

//Create a new word node
Wordnode *create_word_node(char *word, char *file_name)
{
//    printf("Create word node : %s , %s\n", word, file_name);

    //Create node
    Wordnode *word_node = malloc(sizeof(Wordnode));
    word_node->word_link = NULL, word_node->file_link = NULL;

    strcpy(word_node->word, word);

    //While creation def count 1
    word_node->file_count = 1;

//    printf("Word node created\n");

    word_node->file_link = create_file_node(file_name);
    
//    printf("File node created\n");

    return word_node;
}

