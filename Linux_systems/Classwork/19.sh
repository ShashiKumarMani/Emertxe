#!/bin/bash

read -p "Enter the limit : " limit

echo "Enter the elements :  "

for i in `seq 0 $((limit-1))`
do
    read arr[$i]
done

echo "Printing the array : "

for i in `seq 0 $((limit-1))`
do
    echo ${arr[$i]}
done


echo "The entire array : ${arr[@]} "
echo "The first element : ${arr[0]} "
echo "The length of first element : ${#arr[0]} "
echo "The second element is : ${arr[1]} "
echo "The length of the second element is ${arr[1]} "

echo "The length of the whole array : ${#arr[@]} "

echo "The last element is : ${arr[$((limit-1))]} "

