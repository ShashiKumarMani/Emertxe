#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 20 August 2019
    Description : Script for arithmetic calculator using command line arguments
    Input : Two real numbers and an arithmetic operator through command line
    Output : Result of the arithmetic operation or an error
comments

#if number of cla is less than 3
if [ $# -lt 3 ]
then
    #if $# is 0
    if [ $# -eq 0 ]
    then
    	echo "Please pass the arguments through command line. "
    else
    	echo "ERROR : Please pass 3 arguments "
    	echo "Usage : ./04_calculator.sh 1 + 2 "_
    fi

elif [ $# -eq 3 ]
then
    #case to perform arithmetic operations
    case $2 in 
    +)
	echo "scale=02; $1 + $3" | bc
	;;
    -)
	echo "scale=02; $1 - $3" | bc
	;;
    /)
	echo "scale=02; $1 / $3" | bc
	;;
    x)
	echo "scale=02; $1 * $3" | bc
	;; 
    %) 
	echo "$1 % $3" | bc
	;;
    *)
	echo "ERROR : Enter valid operator "
	;;
    esac
# if $ greater than 3
else
    echo "Error : Please pass 3 arguments. "
    echo "Usage : ./04_calculator.sh 1 + 2"

fi
