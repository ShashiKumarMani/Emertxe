#!/bin/bash

echo -n "Enter the value of N : "
read N

for i in `seq 1 $N`
do
    for j in `seq 1 $i`
    do
    	echo -n " $j"
    done
    echo 
done
