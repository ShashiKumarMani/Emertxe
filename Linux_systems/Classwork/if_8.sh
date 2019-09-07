#!/bin/bash

echo "Enter the two integers"
read num1 num2

if [ $(($num1%$num2)) -eq 0 ]
then
    echo "num1 is a multiple of num2"
else
    echo "num1 is not a multple of num2"
fi
