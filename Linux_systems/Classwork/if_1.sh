#!/bin/bash

echo -n "Enter the number : "
read num

if [ $num -gt 0 ]
then
    echo "POSITIVE"
else
    echo "NEGATIVE"
fi

