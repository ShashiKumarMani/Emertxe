#!/bin/bash

<< comments
    Assignment 1 : Print pattern
    Author : Shashi Kumar M
    Date : 20 August 2019
    Description : Read integer and generate pattern 
		    1
		    1 2
		    1 2 3
		    1 2 3 4
    Input : An integer
    Output : Pattern
comments

#read an integer
read -p "Enter the value of N : " num

#if num less or equal to 0
if [ $num -le 0 ]
then
    echo "Error: Enter a value greater than 0 "
else

    #print pattern
    for i in `seq 1 $num`
    do
	for j in `seq 1 $i`     #j -> (1 - i)
	do
	    echo -n "$j "
	done
	echo #newline 
    done
fi

