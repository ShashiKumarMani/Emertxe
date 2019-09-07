#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 29 August 2019
    Description : Script to print argument passed to the function recursively.
    Input : Integers through command line.
    Output : Print Command line arguments using recursion.
comments

function recursion()
{
    if [ $# -le 1 ]
    then
	echo $1
	return
    fi
    echo $1

    temp=($@)  # temporary array

    recurArray=()  # Empty array to store the shifted array
   
    #shift the array by one unit 
    for i in `seq 0 $((${#temp[@]}-1))`
    do
	recurArray+=(${temp[$(($i+1))]})
    done

    recursion ${recurArray[@]}  #recursive call - using shifted array
}

if [ $# -eq 0 ]
then
    echo "Error : No arguments passed "
else
    array=$@

    `echo recursion ${array[@]}`
fi
