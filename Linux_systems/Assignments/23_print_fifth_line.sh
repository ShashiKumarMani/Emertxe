#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 26 August 2019 
    Description : Script to print the 5th line of the given file
    Input : A file through command line
    Output : 5th line of the file.

comments


if [ $# -eq 0 ]
then
    echo "Error : Please pass the filename in command line. "
elif [ -f $1 ]
then

    #get the number of lines from wc command
    num_lines=`cat $1 | wc -l `

    #if number of lines is less than 5
    if [ $num_lines -lt 5 ]
    then
	echo "Error : $1 has only $num_lines lines."

    else
	echo "Fifth line of $1 is "
	echo `head -7 $1 | tail -1`         #OR sed -n (line_no)p file_name

    fi
else
    echo "File doesnt exist"
fi
