#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 20 August 2019  
    Description : Print fibonacci numbers upto a limit
    Input : The limit - an integer
    Output : The fibonacci number upto the limit
comments

#read limit
echo -n "Enter the value of limit : "
read limit

#if limit is positive
if [ $limit -gt 0 ]
then
    #initial fibonacci numbers
    a=0
    b=1

    echo -n "$a $b "

    #add a and b till sum is less than the limit
    while [ $((a+b)) -le $limit ]
    do
        sum=$((a+b))
	echo -n "$sum "
	a=$b
	b=$sum
    done
    echo #newline

elif [ $limit -lt 0 ]
then
    #if limit is negative
    a=0
    b=-1

    echo -n "$a $b "

    #if the sum is greater than limit
    while [ $((a-b)) -gt $limit ]
    do
	#if (positive)sum ge than abs(limit), break
	if [ $((a-b)) -ge $((limit*-1)) ]
	then
	    break
	fi

	sum=$((a-b))
	echo -n "$sum "
	a=$b
	b=$sum
    done
    echo

else
    echo "0"
    #echo "Error : Enter limit value -gt/lt 0 "
fi
