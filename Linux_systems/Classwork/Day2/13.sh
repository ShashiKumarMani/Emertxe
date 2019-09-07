#!/bin/bash

#Check if a number is palindrome or not

read -p "Enter a number : " num

#echo "The length of the number is ${#num} "

len=${#num}

for i in `seq 0 $((len-1))`
do
    arr[$((len-1-i))]=$((num%10))
    num=$((num/10))
done

#for i in `seq 0 $((len-1))`
#do
#    echo ${arr[$i]}
#done

#echo "${arr[$((len-1-0))]} "

for i in `seq 0 $(($((len-1))/2))`
do

    if [ ${arr[$i]} -eq ${arr[$((len-1-i))]} ]
    then
    	flag=1
     	flag2=1
    else
    	flag=0
    	flag2=1
    fi

    #echo " ${arr[$i]}  ${arr[$((len-1-i))]} "
done

if [ $flag -eq 1 -a $flag2 -eq 1 ]
then
    echo "The number is a palindrome "
else
    echo "The number is not a palindrome "
fi
