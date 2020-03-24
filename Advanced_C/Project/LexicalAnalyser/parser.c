/*
    Helper functions to perform parsing
 */

/* Function to find if a string is a keyoword*/
int is_keyword(char *string)
{
    if(!strcmp(string, "char") || !strcmp(string, "int") ||!strcmp(string, "float") ||!strcmp(string, "double") ||!strcmp(string, "signed") ||!strcmp(string, "unsigned") ||!strcmp(string, "short") ||!strcmp(string, "long") ||!strcmp(string, "const") ||!strcmp(string, "volatile") ||!strcmp(string, "for") ||!strcmp(string, "while") ||!strcmp(string, "do") ||!strcmp(string, "goto") ||!strcmp(string, "break") ||!strcmp(string, "continue") ||!strcmp(string, "if") ||!strcmp(string, "else") ||!strcmp(string, "switch") ||!strcmp(string, "case") ||!strcmp(string, "default") ||!strcmp(string, "auto") ||!strcmp(string, "register") ||!strcmp(string, "static") ||!strcmp(string, "extern") ||!strcmp(string, "struct") ||!strcmp(string, "union") ||!strcmp(string, "enum") ||!strcmp(string, "typedef") ||!strcmp(string, "void") ||!strcmp(string, "return") ||!strcmp(string, "sizeof"))
	return 1;
    else
	return 0;
}

/* Function to parse through the file*/
int parser(FILE *fptr)
{
    int char_flag = 0, num_flag = 0, i = 0, preproc = 0;
    char buff[50], data;

    printf("\nINFO : Parsing Started\n\n");

    while((data = fgetc(fptr)) != EOF)
    {
	/* If Alpha read till alpha and print */
	if(isalpha(data))
	{
	    i = 0;
	    buff[i++] = data;

	    while(isalpha((data = fgetc(fptr))) || isdigit(data) || data == '[' || data == ']' || data == '.' || data == '+' || data == '-' || data == '=' || data == '_')
	    {
		buff[i++] = data;
	    }

	    fseek(fptr, -1, SEEK_CUR);

	    buff[i] = 0;


	    if(is_keyword(buff))
		printf("Keyword : %s\n", buff);
            else
                printf("Literal : %s\n", buff);
            num_flag = char_flag = i = 0;

	}
	/* If Digit read till digit OR . print*/
	else if(isdigit(data))
	{
	    i = 0;
	    
	    buff[i++] = data;

	    while(isdigit((data = fgetc(fptr))) || data == '.')
	    {
		buff[i++] = data;
	    }
	    fseek(fptr, -1, SEEK_CUR);

	    buff[i] = 0;

	    printf("Literal : %s\n", buff);

	}
	/* Punct */
	else if(ispunct(data))
	{
	    /* If preprocessor print the whole line*/
	    if(data == '#')
	    {
		printf("Preprocessor : #");
	
		while((data = fgetc(fptr)) != '\n')
		{
		    printf("%c", data);
		}
		printf("\n");
		continue;
	    }
	    else if(data == '"')
	    {
		i = 0;

		if((data = fgetc(fptr)) != '\'')
		{
		    buff[i++] = data;

		    while((data = fgetc(fptr)) != '"')
		    {
			buff[i++] = data;
		    }
		    buff[i] = 0;
		    printf("Literal : \"%s\"\n", buff);
		    continue;
		}
	    }
	    	    
	    printf("Operator : %c\n", data);
	}
    }
	
    printf("\nINFO : Parsing Done.\n");
}
