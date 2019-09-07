#!/bin/bash

echo "Enter 3 marks : "
read m1 m2 m3

total=$(($m1+$m2+$m3))

if [ $total -lt 50 ]
then
    echo "FAIL"
elif [ $total -gt 50 ]
then
    if [ $total -lt 100 ]
    then
    	echo "Average"
    else
    	echo "Excellent"
    fi
fi
