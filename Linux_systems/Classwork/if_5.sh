#!/bin/bash

echo Enter a number 
read num

if [ $num -gt 50 ]
then
    if [ $num -gt 100 ]
    then
    	echo "Number greater than 100"
    elif [ $num -eq 100 ]
    then
    	echo "Number is 100"
    else
    	echo "Number is between 50 and 100"
    fi
else
    if [ $num -eq 50 ]
    then
    	echo "Number is 50"
    else
    	echo "Number is less than 50"
    fi
fi
