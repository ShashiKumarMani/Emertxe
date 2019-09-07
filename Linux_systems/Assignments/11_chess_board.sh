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

# function to print chess board
function chess()
{
    #if row AND column are odd/even print white, else print black
    if [ $1 -eq 0 -a $2 -eq 0 -o $1 -eq 1 -a $2 -eq 1 ]
    then
	echo -e -n "\e[47m""  " #white
	echo -e -n "\e[0m"
    else
	echo -e -n "\e[40m""  " #black
	echo -e -n "\e[0m"
    fi
}

#loop to print chess board
for i in `seq 1 8`
do
    for j in `seq 1 8`
    do
	#function call - 64
	`echo chess $((i%2)) $((j%2))`
    done
    echo #newline
done
