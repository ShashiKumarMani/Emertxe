#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 29 August 2019
    Description : Script to rename a file/directory by lower/upper case letters.
    Input : -N-
    Output : files renamed to lowercase ,and directories renamed to upercase.

comments

# man test

# loop through the array and rename the files and directories
for i in `ls`
do
    if [ -f $i ]     # if the element is a file
    then
	new_name=`echo $i | tr [:upper:] [:lower:]` # uppercase -> lowercase

	if [ -e $new_name ]	#if the file with the name already exists
	then
	    echo "File already exists"
	else
	    mv $i $new_name
	fi
    elif [ -d $i ]  #if the element is directory
    then
	new_name=`echo $i | tr [:lower:] [:upper:]`

	if [ -e $new_name ]
	then
	    echo "Directory already exists!"
	else
	    mv $i $new_name
	fi
    fi
done
