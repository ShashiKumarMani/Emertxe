#!/bin/bash

array=(shashi 052 emertxe bangalore 560032)

echo "The elements of the array are "
for i in ${array[*]}
do
    echo "   $i"
done

echo "The second element of the array is ${array[1]} "
echo "The first element of the array is ${array[0]} "
echo "The length of the array is ${#array[@]} "
echo "The length of first element of the array is ${#array[0]} "
