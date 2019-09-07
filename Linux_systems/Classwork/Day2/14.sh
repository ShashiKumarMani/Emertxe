#!/bin/bash

# Check if the number is prime or not

read -p "Enter a number : " num

flag=0

if [ $num -eq 1 -o $num -eq 0 ]
then
    echo "0 and 1 are not prime "
fi

for i in `seq 2 $((num/2))`
do
    if [ $((num%i)) -eq 0 ]
    then
    	flag=1
    fi
done

if [ $flag -eq 0 ]
then
    echo "The number is prime "
else
    echo "The number is not prime "
fi



