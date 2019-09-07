#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : August 2019
    Description : Script to display any file system which has less than 10% free space
    Input : -N-
    Output : A file system that has less than 10% free space.
comments


#number of files in the system
num=`df | wc -l`
#file=`df | tr -s ' ' | cut -d " " -f 1`
#used=`df | tr -s ' ' | cut -d " " -f 3`
#avail=`df | tr -s ' ' | cut -d " " -f 4`

#loop through the file systems and find files with <10% free space
for i in `seq 2 $num`
do 

    file=`df --output=file | sed -n "$i"p`  #file system names
    used=`df --output=used | sed -n "$i"p`  #Used space   
    avail=`df --output=avail | sed -n "$i"p` #available space

    #calculate remaining space %
    rem=$(( $(($avail*100))/$(($used + $avail )) ))

    if [ $rem -lt 10 ]
    then
	echo "File system $file has less than 10% free space. "
    else
    	echo "File system $file has $rem remaining space. "
    fi

done
