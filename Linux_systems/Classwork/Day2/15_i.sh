#!/bin/bash

echo -n "Enter the value of N : "
read N


for i in `seq 0 $((N-1))`
do
    if [ $((i%2)) -eq 0 ]
    then
    	k=1
    else
    	k=0
    fi

    for j in `seq 0 $i`
    do
    	echo -n " $k"
    	if [ $k -eq 0 ]
    	then
    	    k=1
	else
	    k=0
	fi
    done
    echo 
done
