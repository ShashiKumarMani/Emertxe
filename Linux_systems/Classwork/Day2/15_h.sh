#!/bin/bash

echo -n "Enter the value of N : "
read N

k=1

for i in `seq 1 $N`
do
    for j in `seq 1 $i`
    do
    	echo -n " $k"
	k=$((++k))
    done
    echo 
done
