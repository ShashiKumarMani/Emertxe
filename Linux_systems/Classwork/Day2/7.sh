#!/bin/bash

#Print all even numbers between m and n

echo "Enter the values of m and n"

read m n

sum=0
for i in `seq $((m+1)) $((n-1))`
do
    if [ $((i%2)) -eq 0 ]
    then
    	echo $i
    fi
done
