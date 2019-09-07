#!/bin/bash

#Print the sum of digits of a given number

echo -n "Enter the number  : "
read num
sum=0
while [ $num -gt 0 ]
do
    unit=$(($num%10))
    sum=$(($sum+$unit))
    num=$(($num/10))
done

echo "The sum of digits is $sum"

