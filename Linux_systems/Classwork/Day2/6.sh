#!/bin/bash

# Print all even numbers between 1 and 100

for i in `seq 0 100`
do
    if [ $((i%2)) -eq 0 ]
    then
    	echo $i
    fi
done

