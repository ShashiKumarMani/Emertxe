#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 27 August 2019
    Description : Script to print greetings based on time.
    Input : No input
    Output : string - Greetings
comments

#hour value from date
hour=`date | cut -d ":" -f 1 | cut -d " " -f 5` # OR date +%H

#hour=$1

#if statement to print greetings
if [ $hour -lt 5 ]
then
    echo "Good night!"

elif [ $hour -lt 12 ]
then
    echo "Good Morning!"

elif [ $hour -lt 13 ]
then
    echo "Good noon!"

elif [ $hour -lt 17 ]
then
    echo "Good Afternoon!"

elif [ $hour -lt 21 ]
then
    echo "Good Evening!"

else
    echo "Good night!"
fi
