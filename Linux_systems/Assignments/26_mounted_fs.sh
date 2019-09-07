#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019
    Description : Script to determine whether a given file or mount point is mounted.
    Input : -N-
    Output : mounted/not , used space % and free space .
comments

#store all file-system information in arrays
num_files=`df | wc -l`
file_system=(`df | tr -s ' ' | cut -d ' ' -f 1`)
used_space=(`df | tr -s ' ' | cut -d " " -f 5`)
mounted=(`df | tr -s ' ' | cut -d " " -f 6`)
free_space=(`df | tr -s ' ' | cut -d " " -f 4`)

#if no cla is passed
if [ $# -eq 0 ]
then
    echo " Error : Please pass the name of the file-system through command line. "

elif [ $# -eq 1 ]
then

    # loop through the file-system 
    for i in `seq 1 $((num_files-1))`
    do
	if [ ${file_system[$i]} = $1 ]
	then
	    echo "File-system $1 is mounted on ${mounted[$i]} and it is having ${used_space[$i]} used space with ${free_space[$i]} KB free"
	    exit    #if file system is present exit
	fi

    done
    echo "$1 is not mounted. "
else

    echo $'Error : Please input only one argument. \nUsage : ./26_mounted_fs file_system_name '
fi
