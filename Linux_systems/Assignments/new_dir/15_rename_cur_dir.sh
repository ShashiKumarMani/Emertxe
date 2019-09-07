#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 26 August 2019
    Description : Script to rename current working directory with the given name.
    Input : A string - new name
    Output : The directory name will replaced by new name.
comments

# man basename

if [ $# -eq 0 ]   #if cla is passed
then
    echo "Error : Please pass the new directory name "
else

    #new_dir=${PWD%/*}/$1; mv $PWD $new_dir

    present=`basename $PWD`        #get the present directory

    cd ..                         #Go to the previous directory

    if [ -e $1 ]                  # if the directory already exists
    then
	echo "Directory exists. "

    else
	echo "Current directory will be renamed to - $1 "
	mv "$present" "$1"       #rename directory
	#cd .
    fi

fi
