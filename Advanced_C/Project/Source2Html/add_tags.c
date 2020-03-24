/*
    Function to add html tags to the source file
 */

#include "header.h"

data_t add_tags(FileInfo *InputData)
{
     int data, flag = 0, line_count = 1;
 
     char *break_tag = "<br>\n", *head_tag_start = "<h3>", *head_tag_end = "</h3>\n", *space = "&emsp;", *ang_left = "&lt;", *ang_right = "&gt;";

     //Add the html, head tags
     fprintf(InputData->dest_ptr, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n</head>\n<body>\n", InputData->src_fname);
 
     while((data = fgetc(InputData->src_ptr)) != EOF)
     {
         //If character is newline
         if(data == '\n')
         {
             if(flag == 0)
             {
                 if(InputData->line_flag)
                 {
                     fprintf(InputData->dest_ptr, "%s%d%s", head_tag_start, line_count, head_tag_end);
                 }
                 else
                    fprintf(InputData->dest_ptr, "%s", break_tag);
 
             }
             else
                 fprintf(InputData->dest_ptr, "%s", head_tag_end);
 
             flag = 0;
             line_count++;
         }
         //Else
         else
         {
	     //Beginning of line
             if(flag == 0)
             {
                 fprintf(InputData->dest_ptr, "%s", head_tag_start);
 
		 //If -n add line number
                 if(InputData->line_flag)
                     fprintf(InputData->dest_ptr, "%d&emsp;", line_count);
             }
             if(data == ' ')
             {
                 fprintf(InputData->dest_ptr, "%s", space);
             }
             else if(data == '<')
             {
                 fprintf(InputData->dest_ptr, "%s", ang_left);
             }
             else if(data == '>')
             {
                 fprintf(InputData->dest_ptr, "%s",  ang_right);
             }
             else
                 fputc(data, InputData->dest_ptr);
 
             flag = 1;
         }
     }
 
     //Add the ending tags
     fprintf(InputData->dest_ptr, "</body>\n</html>\n");
    
     fclose(InputData->src_ptr);
     fclose(InputData->dest_ptr);
}
