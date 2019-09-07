#!/bin/bash

echo -n "Enter the value of N : "
read N

for i in `seq 1 $N`
do
    for j in `seq 1 $i`
    do
    	#if [ $j -le $i ]
	#then
	#    echo -n "x"
	#else
	#    echo -n " "
	#fi

	echo -n "*"
    done
    echo 
done
