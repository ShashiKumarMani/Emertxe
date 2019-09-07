#!/bin/bash

echo "Enter a number"
read num

if [ $num -lt 100 -o $num -gt 200 ]
then
    echo "Number is not between 100 and 200"
else
    echo "Number between 100 and 200"
fi

