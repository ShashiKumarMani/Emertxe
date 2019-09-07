#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to print the given numbers in ascending or descending order
    Input : An option -a/-d and a list of integers through command line
    Output : The integers in ascending or descending order
comments

#function to perform bubble sort
function bubble_sort()
{
    #initilise array
    array=$2

    #bubble sort of array
    for i in `seq 1 $((${#array[@]}-1))`
    do  
	for j in `seq 1 $((${#array[@]}-$i-1))`
        do
	    #if arr[j] -greater/lessthan arr[j+1] 
	    if [ ${array[$j]} $1 ${array[$((j+1))]} ]
            then

		#swap arr[j] and arr[j+1]
		temp=${array[$j]}
                array[$j]=${array[$((j+1))]}
                array[$((j+1))]=$temp
            fi
        done
    done
 
    #print the sorted array
    for i in `seq 1 $((${#array[@]}-1))`
    do
	echo -n " ${array[$i]}"
    done
    echo
}

#if no argument is passed
if [ $# -eq 0 ]
then
    echo "Please pass the arguments through command line. "
    echo "Usage : ./12_sorting -a/-d 3 4 1 23 "

elif [ $# -eq 1 ]
then
    echo "Please pass more than 1 argument "
    echo "Usage : ./12_sorting -a/-d 3 4 1 23 "

else

    #store all cla in an array
    array=($@)

    #ascending order
    if [ ${array[0]} = "-a" ]
    then
	echo -n "Ascending order of the array is :"
	`echo bubble_sort -gt ${array[@]}` #pass the array and option to the function
    
    #descending order
    elif [ ${array[0]} = "-d" ]
    then
	echo -n "Descending order of the array is :"
	`echo bubble_sort -lt ${array[@]}`
    else
	echo "ERROR: Please pass the choice. "
	echo "Usage : ./12_sorting.sh -a/-d 1 2 3 4. "
    fi
fi

