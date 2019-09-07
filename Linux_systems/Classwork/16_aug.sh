#!/bin/bash

echo -n "Enter 3 numbers : "
read num1 num2 num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then
    echo "NUM1 is the largest number"
elif [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then
    echo "NUM2 is the largest number"
elif [ $num3 -gt $num1 -a $num3 -gt $num2 ]
then
    echo "NUM3 is the largest number"
else
    echo "Repeating values : Largest could not be found"
fi


