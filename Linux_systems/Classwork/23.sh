#!/bin/bash

# Simple function script to add two numbers

function sum()
{
    echo $1 + $2 | bc
}

read -p "enter two numbers : " num1 num2

#function call
sum=`sum $num1 $num2`

echo "The sum of $num1 and $num2 is $sum "

#use function in echo
echo "The sum of 1 and 5 is `sum 1 5` "

if [ $# -lt 2 ]
then
    echo "Enter min. 2 cla "
else
#cla
echo "The sum of 4 and 3 is `sum $1 $2` "
fi



