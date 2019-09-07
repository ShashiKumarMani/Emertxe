#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 23 August 2019
    Description : Display the longest and shortest username on the system
    Input : -N-
    Output : Two strings - longest and shortest usernames.
comments

#store all usernames in an array
array=(`cat /etc/passwd | cut -d ":" -f 1`)

#initialse longest and shortest with the first username
longest=${array[0]}
shortest=${array[0]}

#loop through the array and find the shortest and longest usernames
for i in `seq 1 ${#array[@]} `
do
    #if len(current) > len(longest) AND len(current) != 0
    if [ ${#array[$i]} -gt ${#longest} -a ${#array[$i]} -ne 0 ]
    then
	longest=${array[$i]}

    #if len(current) < len(shortest) AND len(current) != 0
    elif [ ${#array[$i]} -lt ${#shortest} -a ${#array[$i]} -ne 0 ]
    then
	shortest=${array[$i]}
    fi	
done

echo "The Longest name is :  $longest "
echo "The Shortest name is :  $shortest "
