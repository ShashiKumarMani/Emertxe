#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019 
    Description : For each directory in the $PATH display the number of executable files in that directory
    Input : -N-
    Output : Number of executable files in that directory , total number of executable files in the $PATH
comments

paths=(`echo $PATH | tr ':' '\n'`)  #store paths in an array

total_count=0

for i in ${paths[@]}  #loop through all directories
do
    count=0
    
    if [ -e $i ]             #if directory exists
    then
	cd $i
	all_files=(`echo *`)        #stores all files in an array

	for j in ${all_files[@]}    #loop through all files
	do
	    if [ -x $j ]            #if the file is an executable
	    then
		count=$((++count))   #increment
	    fi
	done

    fi
    total_count=$((total_count+count))
    echo "Current directory : $i"
    echo "Current count : $count"
done

echo
echo "Total count : $total_count "
