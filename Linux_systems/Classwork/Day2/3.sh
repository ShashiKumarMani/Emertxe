#!/bin/bash

echo "Enter the value of m and n"
read m n

if [ $m -lt $n ]
then
    for i in `seq $m $n`
    do
    	echo $i
    done
else
    for i in `seq $m -1 $n`
    do
    	echo $i
    done
fi
