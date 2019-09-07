#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019
    Description : Script to delete all swp files in the system or directory
    Input : A directory 
    Output : All swp files will be deleted.
comments

directory="/home/sayan"    #default directory - 

if [ $# -eq 1 ]
then
    directory=$1            #if directory is given
fi

echo "Searching swp files...."
all_swp=(`find $1 -name ".*.swp"`)  #search&store all swp file paths
echo "Search completed"

if [ ${#all_swp[@]} -ne 0 ]
then

    echo "swp file found :"
    echo ${all_swp[@]}

    for i in ${all_swp[@]}  #loop through the array & delete files
    do
	rm $i
    done
    echo "swp file deleted."

else
    echo "No swp files found in $directory. "
fi
