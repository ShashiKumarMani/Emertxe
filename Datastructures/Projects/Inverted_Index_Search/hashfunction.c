/*
    Function to return hash index
*/

#include "header.h"

int hashfunction(char *key)
{
    //Return index[0-25] if alphabet, 26 - digits, 27-other characters
    return isalpha(key[0]) ? tolower(key[0]) - 'a' : isdigit(key[0]) ? 26 : 27;	
}
