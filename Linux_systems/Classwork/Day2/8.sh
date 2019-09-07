#!/bin/bash

#Print the sum of odd number between m and n

echo "Enter the values of m and n"

read m n

sum=0
for i in `seq $((m+1)) $n`
do
    if [ $((i%2)) -ne 0 ]
    then
	sum=$((sum+i))
    fi
done

echo "The sum of odd numbers between m and n is $sum "


