#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 20 August 2019
    Description : Script to add two real numbers
    Input : Two real numbers	
    Output : Sum of the real number
comments

#read two real numbers
read -p "Enter two numbers : " num1 num2

#bc to perform addition and print result
echo "The Answer is : `echo $num1 + $num2 | bc`"
