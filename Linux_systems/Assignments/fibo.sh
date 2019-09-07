#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 20 August 2019  
    Description : Print fibonacci numbers upto a limit
    Input : The limit - an integer
    Output : The fibonacci number upto the limit
comments

read -p "Enter the value of limit : " limit

if [ $limit -gt 0 ]
then
    #initial fibonacci numbers
    a=0
    b=1

    echo -n "$a, $b"

    #add a and b till sum is less than the limit
    while [ $((a+b)) -lt $limit ]
    do
        sum=$((a+b))
	echo -n ", $sum"
	a=$b
	b=$sum
    done
    echo

else
    a=0
    b=-1

    echo -n "$a, $b"

    #print fibonacci numbers till abs(sum) < abs(limit)

    while [ $((a-b)) -gt $limit ]
    do
	#if positive sum greater than abs(limit) break
	if [ $((a-b)) -ge $((limit*-1)) ]
	then
	    break
	fi
	sum=$((a-b))
	echo -n ", $sum"
	a=$b
	b=$sum
    done
    echo
fi
