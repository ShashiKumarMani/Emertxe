#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to print the given numbers in ascending or descending order
    Input : An option -a/-d and a list of integers through command line
    Output : The integers in ascending or descending order
comments

if [ $# -eq 0 ]
then
    echo "Please pass the arguments through command line. "
    echo "Usage : ./12_sorting -a/-d 3 4 1 23 "
elif [ $# -eq 1 ]
then
    echo "Please pass more than 1 argument "
    echo "Usage : ./12_sorting -a/-d 3 4 1 23 "
else
    array=($@)

    #ascending order
    if [ ${array[0]} = "-a" ]
    then

	#bubble sort
	for i in `seq 1 $((${#array[@]}-1))`
	do
	    for j in `seq 1 $((${#array[@]}-$i-1))`
	    do
		if [ ${array[$j]} -gt ${array[$((j+1))]} ]
		then
		    temp=${array[$j]}
		    array[$j]=${array[$((j+1))]}
		    array[$((j+1))]=$temp
		fi
	    done
	done
	for i in `seq 1 $((${#array[@]}-1))`
	do
	    echo -n " ${array[$i]}"
	done
	echo

    #descending order
    elif [ ${array[0]} = "-d" ]
    then
         for i in `seq 1 $((${#array[@]}-1))`
         do  
             for j in `seq 1 $((${#array[@]}-$i-1))`
             do
                 if [ ${array[$j]} -lt ${array[$((j+1))]} ]
                 then 
                     temp=${array[$j]}
                     array[$j]=${array[$((j+1))]}
                     array[$((j+1))]=$temp
                 fi  
             done
         done
	 for i in `seq 1 $((${#array[@]}-1))`
	 do
	     echo -n " ${array[$i]}"
	 done
	 echo
    else
	echo "ERROR: Please pass the choice. "
	echo "Usage : ./12_sorting.sh -a/-d 1 2 3 4. "
    fi
fi
