#!/bin/bash

# Simple function script

function sum()
{
    echo $1 + $2 | bc
}

read -p "enter two numbers : " num1 num2

sum=`sum $num1 $num2`

echo $sum

echo "The sum of 4 and 3 is `sum $1 $2` "




