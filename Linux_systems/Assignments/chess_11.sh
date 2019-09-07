#!/bin/bash

<< comments
     Author : Shashi Kumar M
     Date : 22 August 2019
     Description : Print a chess board using echo
		    Knowledge required - Printing colors using echo
					 Nested loops
     Input : No input
     Output : Chess board
comments

# Script to print chess board

for i in `seq 1 8`
do
    for j in `seq 1 8`
    do
	#if line is even
	if [ $((i%2)) -eq 0 ]
	then
	    #if statement to print alternative 1 and 0
	    if [ $((j%2)) -eq 0 ]
	    then
		#echo -n " 0"
		echo -e -n "\e[47m""  "
		echo -e -n "\e[0m"
	    else
		#echo -n " 1"
		echo -e -n "\e[40m""  "
		echo -e -n "\e[0m"
	    fi
	else
	    #if line is odd
	    if [ $((j%2)) -eq 0 ]
	    then
		#echo -n " 1"
		echo -e -n "\e[40m""  "
		echo -e -n "\e[0m"
	    else
		#echo -n " 0"
		echo -e -n "\e[47m""  "
		echo -e -n "\e[0m"
	    fi
	fi
    done
    echo
done
echo -e -n "\e[0m""  "

