#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 26 August 2019
    Description : Script to translate the string lower to upper and upper to lower
    Input : A file
    Output : The file with contents converted upper/lowercase.
comments

if [ $# -eq 0 ] # if no arguments is passed
then
    echo "Error : Pass the file name through command line. "

elif [ -f $1 ] # if the file exists execute
then

    if [ `cat $1 | wc -l` -eq 0 ]	    # if the file has no contents
    then
	echo "Error : No contents inside the file. "

    else
	echo $'1 -- Lower to Upper\n2 -- Upper to Lower\nPlease select option : '
	read option
	
	if [ $option -eq 1 ]		    #lower to upper
	then

		#echo "File contents before translating : "
		#cat $1			    # print the contents before translating
	    echo "`cat $1 | tr [:lower:] [:upper:]`" > $1
	
	elif [ $option -eq 2 ]		    #Upper to lower
	then
		#echo "File contents before translating : "
		#cat $1
	    echo "`cat $1 | tr [:upper:] [:lower:]`" > $1
	else
    	    echo "Error : Invalid Option. "
	fi
    fi

else
    echo "Error : file doesnt exist. "

fi
