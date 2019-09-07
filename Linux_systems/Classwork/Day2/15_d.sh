#!/bin/bash

echo -n "Enter the value of N : "
read N

for i in `seq 1 $N`
do
    for j in `seq 1 $N`
    do
	if [ $((i+j)) -gt $N ]
	then
	    echo -n "x"
	else
	    echo -n " "
	fi
    done
    echo 
done
