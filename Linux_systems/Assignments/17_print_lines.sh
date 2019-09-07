#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 23 August 
    Description : Script to print contents of the file from given line number to next given number of lines
    Input : A file, start of line and number of lines - integers
    Output : Contents of the file,from line number to next given number of lines.
comments


if [ $# -eq 0 ]
then
    echo "Error : Pass the arguments through command line. "

elif [ $# -lt 3 ] # if number of arguments is less than 3
then
    echo "Error : Arguments missing!"
    echo "Usage : ./17_print_lines.sh start_line end_line file_name "
    echo "For eg. ./17_print_lines.sh 5 5 <file> "

elif [ -f $3 ] #check whether file exists
then
    if [ $1 -ne 0 -a $2 -ne 0 ] # start_line and num_lines should not be 0
    then
	echo $(head -n $(($1+$2-1)) $3 | tail -n $2) # OR sed -n $1,$(($2+$1-1))p $3
    else
	echo "Error : start_line and num_lines should be greater than 0. "
    fi
else
    echo "File doesnt exist. "
fi
