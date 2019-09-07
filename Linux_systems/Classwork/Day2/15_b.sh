#!/bin/bash

echo -n "Enter the value of N : "
read N

for i in `seq 1 $N`
do
    for j in `seq 1 $((N-i+1))`
    do
    	echo -n "x"
    done
    echo
done
