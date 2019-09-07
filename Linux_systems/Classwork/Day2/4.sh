#!/bin/bash

echo -n "Enter N : "
read N
sum=0

for i in `seq 1 $N`
do
    echo -n "Enter value $i  : "
    read m
    sum=$(($sum+$m))
done

echo "The sum of $N values is $sum"
echo -n "The average is : "
echo "scale=02; $sum/$N" | bc
