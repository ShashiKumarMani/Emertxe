#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : August 2019
    Description : Script to display any file system which has less than 10% free space
    Input : -N-
    Output : A file system that has less than 10% free space.
comments


num=`df | wc -l` #number of files in the system
file=(`df | tr -s ' ' | cut -d " " -f 1`)
used_percent=(`df | tr -s ' ' | cut -d " " -f 5 | tr -d %`)

#loop through the file systems and find files with <10% free space
for i in `seq 1 $(($num-1))`
do 
    #calculate remaining space %
    rem=$((100-${used_percent[$i]}))

    if [ $rem -lt 10 ]
    then
	echo "File system ${file[$i]}% has less than 10% free space. "
    else
    	echo "File system ${file[$i]} has $rem% remaining space. "
    fi

done
