#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Filenames and word default size
#define SIZE 50
#define BACKUPFILE "backup.txt"

#define SUCCESS -456
#define FAILURE -234

typedef struct file{
    
    char file_name[50];
    int word_count;
    struct file *file_link;

}Filenode;

typedef struct word
{
    char word[50];
    int file_count;
    struct word *word_link;
    Filenode *file_link;

}Wordnode;

typedef struct filename
{
    char *filename;
    struct filename *link;
}Filenames;

int hashfunction(char *word);
int isduplicate(Filenames *filenames, char *filname);
int insert_last(Filenames **head, char *filename);
Wordnode *create_word_node(char *word, char *file_name);
Filenode *create_file_node(char *file_name);
int add_word(char *word, char *file_name, Wordnode *database[]);
int create_database(char *argv[], Filenames **filenames, Wordnode *database[]);
int display_database(Wordnode *database[]);
int search_database(char *word, Wordnode *database[]);
int save_database(Wordnode *database[], char *filename);
int update_database(Wordnode *database[], Filenames **filenames, char *filename);
int update_word(int index, char *word, char *filename, Filenames **newlist, Wordnode *database[]);
#endif
