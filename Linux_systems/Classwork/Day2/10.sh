#!/bin/bash

#Print fibonacci numbers upto a limit

echo -n "Enter the value of limit : "
read limit

a=0
b=1

echo $a
echo $b

while [[ $((a+b)) -lt $limit ]]
do
    sum=$((a+b))
    echo $sum
    a=$b
    b=$sum
done
