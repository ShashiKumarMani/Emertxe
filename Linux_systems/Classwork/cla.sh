#!/bin/bash

#Command line arguments

echo "Filename : $0 "

if [ $# -eq 0 ]
then
    echo "ERROR : No arguments passed "
else
    arr=($@)
    echo "Total number of cla : $# "
    echo "Total number of cla : ${#arr[@]} "
    echo "All arguments are : $@ "
    echo "All arguments are : ${arr[@]} "
    echo "The first cla is : $1 "
    echo "The first cla is : ${arr[0]} "
    echo "The cla is : ${arr[$#-1]} "
    echo "The length of the last argument : ${#arr[$#-1]} "
    sum=$(($1+$2))
    echo "The sum of elements 0 and 1 is : $sum "

fi

