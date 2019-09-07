#!/bin/bash

<< comments
     Author : Shashi Kumar M
     Date : 21 August 2019
     Description : Script to print the reverse of a number
     Input : An integer
     Output : Reverse of the integer

comments

#Script to print the given number in reverse order

if [ $# -eq 0 ]
then
    echo "ERROR : No arguments passed "
elif [ ${#1} -eq 1 ]
then
    echo "ERROR : Pass a multi-digit number "
else

    reverse=0
    temp=$1 

    echo ${temp:0:1}


    #check if the number is octal
    if [ ${temp:0:1} -eq 0 ]
    then
	echo ${#1}

	reverse=$(($reverse+$(($((temp%10))*$((10**$((${#temp}-1))))))))
	temp=$((temp/10))
    else
	for i in `seq 1 ${#1}`
	do
	    reverse=$(($reverse+$(($((temp%10))*$((10**$((${#temp}-1))))))))
	    temp=$((temp/10))
	done
    fi
    echo "Reversed number - $reverse"
fi
