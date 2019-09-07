#!/bin/bash

# Print the factorial of the given number 

echo -n "Enter N : "
read N

sum=1

for i in `seq $N -1 1`
do
    sum=$(($sum*i))
done

echo "The factorial of $N is $sum"

