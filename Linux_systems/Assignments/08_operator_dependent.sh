#!/bin/bash

<< comments
    Assignment 8 : Operator Dependence
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to perform arithmetic operation on digits of a given number depending upon the operator
    Input : A number
    Output : Result of the arithmetic operation
comments


#Function to perform the arithmetic operation
function arithmetic_operation()
{
     string=$1

     operator=${string:${#string}-1:1} #operator at the end of the string
     
     result=0
     
     #iteratively perform the arithmetic operation : i -> ( strlen , 2 ) 
     for i in `seq $((${#string})) -1 2`
     do  
         #initialise the result with first character
         if [ $i -eq $((${#string})) ]
         then
             result=${string:${#string}-i:1} #string[0]

	 else
	     # result = (result (operator) string[n] )
             result=$(echo "scale=02; $result$operator${string:${#string}-i:1}" | bc -l)
         fi
     done

     #print the result
     echo $result
}

# main script

# if number of arguments is 0
if [ $# -eq 0 ]
then
    echo "Error : Pass the arguments through command line. "
    echo "Usage: ./08_operator_dependence 1234+ "
# if $# is greater than 1
elif [ $# -gt 1 ]
then
    echo "Error : Pass max. 1 argument. "
else
    string=$1

    operator=${string:${#string}-1:1} #operator at the end of the string

    #case statement to print result
    case $operator in
	"+")
	    echo "The result is `arithmetic_operation $string` "
	    ;;
	"-")
	    echo "The result is `arithmetic_operation $string`"
	    ;;
	"/")
	    echo "The result is `arithmetic_operation $string`"
	    ;;
	"*")
	    echo "The result is `arithmetic_operation $string` "
	    ;;
	"%")
	    echo "The result is `arithmetic_operation $string`"
	    ;;
	*)
	    echo "Error : Operator missing "
    esac
fi
