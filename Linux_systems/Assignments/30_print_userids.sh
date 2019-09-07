#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019
    Description : Script to count the number of users with userids between the given values (default - 500 and 10000 ) on the system
    Input : -N-
    Output : Integer - count of userids between 500 and 10000
comments

user_ids=(`cat /etc/passwd | cut -d ":" -f 3`) # store usernames in an array

start=500 #default values of range
end=1000

function print_count()
{
    user_ids=($@) #store usernames in an array

    count=0

    for i in ${user_ids[@]} #loop through the array
    do
	if [ $i -gt $start -a $i -lt $end ]
	then
	    count=$((++count))
	fi
    done

    echo "The total number of user ID between $start and $end is $count "
    
}
if [ $# -eq 0 ]
then
    echo `print_count ${user_ids[@]}`

elif [ $# -eq 2 ]
then
    start=$1
    end=$2

    echo `print_count ${user_ids[@]}`

else
    echo $'Error : Enter the start and end values for userids. \nUsage : ./32_user_present.sh start end. '
fi
