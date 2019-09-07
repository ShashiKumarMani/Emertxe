#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to print the reverse of the given number
    Input : An integer
    Output : Reverse of the integer
comments

#check if cla is passed
if [ $# -eq 0 ]
then
    echo "ERROR : No arguments passed "

elif [ ${#1} -eq 1 ] #if the length of argument is 1
then
    echo "ERROR : Pass a multi-digit number "

else

    reverse=0
    temp=$1 

    #loop from 1 --> length of integer
    for i in `seq 1 ${#1}`
    do
	#reverse = (reverse + (digit * (10 ** n_digit )))
	reverse=$((reverse+$((${temp:${#temp}-i:1}*$((10**$((${#temp}-i))))))))
    
    done

    echo "Reversed number - $reverse"
fi

