#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 31 August 2019
    Description : Use pipes and redirection to create an infinite feedback loop
    Input : A file
    Output : infinite loop of the file contents

comments

if [ $# -eq 0 ]                 #if no cla is passed
then

    echo "Error : Pass the file name through command line. "
else

    echo "File contents before the loop : "  
    cat $1                          #print file contents before loop
 
    echo "File contents after the loop : "
    tail -f $1 >> $1 | cat $1       #print infinite loop
fi
