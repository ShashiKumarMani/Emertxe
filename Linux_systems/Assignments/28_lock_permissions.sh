#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 31 August 2019
    Description : Script to lock permission of the given directory
    Input : A directory
    Output : The directory is locked
comments

if [ $# -eq 0 ]
then
    echo "Error : Please pass the directory in command line. "
elif [ -d $1 ]
then
    cd $1  # get into the directory

    all_files=(`ls`) #store all files in an array

    if [ ${#all_files[@]} -ne 1 ] # if files exist
    then
	for i in ${all_files[@]}
	do
	    chmod 700 $i # rwx-for owner 0-group 0-others
	done
	cd ..
    else
	echo "No files in the directory"
    fi
else
    echo "Directory doesnt exist "
fi

