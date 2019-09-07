#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 28 August 2019
    Description : Given album name and correspoding directory this script renames them by inserting index numbers
    Input : A directory of images
    Output : The images will be renamed to the given name
comments

if [ $# -eq 0 ]			#if no cla is passed
then
    echo "Error: Please pass the prefix through command line. "
elif [ $# -eq 1 ]
then
    new_name=$1			    #store the new name

    j=1				    #variable to keep count

    all_files=(`ls *.jpg`)	    #store all jpg files in an array
				#assuming all_files are in order
    if [ ${#all_files[@]} -ne 0 ]   #if jpg files are present
    then
	#count=${#all_files[@]}	    #the number of jpg files

	for i in ${all_files[@]}    #loop through jpg files
	do
	    if [ $j -le 9 ]	    #if count is less than 9
	    then
		mv $i "${new_name}_00${j}.jpg"  # 1 - 9
	    elif [ $j -le 99 ]
	    then
		mv $i "${new_name}_0${j}.jpg"   # 10 - 99
	    else
		mv $i "${new_name}_${j}.jpg"   
	    fi
	    j=$((++j))                          #increment count
	done
    else
	echo "Error : No jpg files in the present directory. "
    fi
else
    echo "Error : Please input only one argument. "
fi
