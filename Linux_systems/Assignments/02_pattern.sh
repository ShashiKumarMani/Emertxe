#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 20 August 2019
    Description : Read a number n and generate given pattern
		    1
		    2 3
		    4 5 6
		    7 8 9 10
    Input : An integer
    Output : The pattern
    
comments

read -p "Enter the value of N : " num

k=1

if [ $num -le 0 ]
then
    echo "Error: Enter a value greater than 0 "
else

    # print pattern
    for i in `seq 1 $num`
    do
	for j in `seq 1 $i`
	do
	    echo -n " $k"
	    k=$((++k)) #increment k
	done
	echo 
    done
fi
