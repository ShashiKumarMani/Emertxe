#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to obtain the largest integer value from n number of arguments using command line
    Input : Integer values through command line
    Output : The largest integer value
comments
 
#if no arguments is passed
if [ $# -eq 0 ]
then
    echo "ERROR: No arguments passed "

elif [ $# -eq 1 ]
then
    echo "Largest : $1 "

else

    #initialise largest with first argument
    largest=$1

    # loop and compare $largest with all arguments
    for i in $@
    do	
	if [ $i -gt $largest ]
	then
    	    largest=$i
	fi
    done
    echo "Largest : $largest "
fi

