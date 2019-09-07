#!/bin/bash

echo -n "Enter the year : "
read year

if [ $(($year%400)) -eq 0 ]
then
    echo "LEAP YEAR"
elif [ $(($year%4)) -eq 0 ]
then
    if [ $(($year%100)) -ne 0 ]
    then
    	echo "LEAP YEAR"
    else
    	echo "NOT A LEAP YEAR"
    fi
else
    echo "NOT A LEAP YEAR"
fi
