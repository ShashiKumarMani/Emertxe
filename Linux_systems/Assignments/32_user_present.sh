#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : August 2019
    Description : Script to search a user present in your system.
    Input : -N-
    Output : User present / No
comments

#store all usernames in an array
array=(`cat /etc/passwd | cut -d ":" -f 1`)

if [ $# -eq 0 ]
then
    echo "Error : Please pass the argument through command line. "
else

    echo "Searching for user $1"
    
    for i in `seq 0 $((${#array[@]}-1))`
    do
	if [ ${array[$i]} = $1 ]
	then
	    echo "User present"
	    exit   #if user is present exit
	fi
    done
    echo "User not present"
fi
