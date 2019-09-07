#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to print the length of each and every 
		    string using arrays
    Input : A sentence through command line
    Output : Length of strings stored in the array
comments

if [ $# -eq 0 ]
then

    echo "Error : No arguments passed "
else

    #store the cla in an array
    array=($@)

    #loop over the array elements and print the lengths
    for i in ${array[@]}
    do
	echo "Length of string($i) - ${#i} "
    done

fi
