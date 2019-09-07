#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019
    Description : Script that takes any number of directories as command line arguments and then lists the contents of each of these directories.
    Input : Directories
    Output : Contents of directories and sub-directories.
comments

all_files=(`echo *`)  # all_files in the current directory
num_files=`echo * | wc -w` #number of files


for i in `seq 0 $(($num_files-1))` #loop through all files
do
    if [ -f ${all_files[$i]} ]  #if file
    then
	echo " ${all_files[$i]}"

    elif [ -d ${all_files[$i]} ]  #if directory
    then

	cd ${all_files[$i]}    #get into the directory and print contents
	echo "|------------------------ "
	echo "|---Directory : ${all_files[$i]}"
	echo "|-" *
	echo "|----------------------- "
	cd ..

    fi
done
