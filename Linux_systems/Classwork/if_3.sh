#!/bin/bash

echo -n "Enter the number : "
read num

if [ $num -gt 0 ]
then
    echo "POSITIVE"
elif [ $num -eq 0 ]
then
    echo "NUMBER IS ZERO"
else
    echo "NEGATIVE"
fi

