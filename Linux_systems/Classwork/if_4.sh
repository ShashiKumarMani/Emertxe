#!/bin/bash

echo -n "Enter the nhumber : "
read num

if [ $num -gt 0 ]
then
    if [ $(($num % 2)) -eq 0 ]
    then
    	echo "POSITIVE EVEN"
    else
    	echo "POSITIVE ODD"
    fi
elif [ $num -eq 0 ]
then
    echo "NUMBER IS ZERO"
else
    echo "NEGATIVE"
fi
