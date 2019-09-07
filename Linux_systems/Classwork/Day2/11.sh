#!/bin/bash

#Print N number of fibonacci numbers

echo -n "Enter the value of N : "
read N

a=0
b=1

echo $a
echo $b

for i in `seq 3 $N`
do
    sum=$((a+b))
    echo $sum
    a=$b
    b=$sum
done
