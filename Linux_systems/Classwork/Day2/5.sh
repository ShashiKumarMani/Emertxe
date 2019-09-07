#!/bin/bash

#Print the largest and smallest of the given numbers

echo -n "Enter N : " 
read N

echo "Enter the numbers " 

for i in `seq 1 $N`
do
    read num

    if [ $i -eq 1 ]
    then
    	largest=$num
    	smallest=$num
    fi

    if [ $num -lt $smallest ]
    then
    	smallest=$num
    fi

    if [ $num -gt $largest ]
    then
    	largest=$num
    fi


done

echo "The largest number is : $largest "
echo "The smallest number is : $smallest "
