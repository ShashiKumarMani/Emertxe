#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019 
    Description : Script to replace 20% lines in a file randomnly and replace it with the pattern <--DEL-->
    Input : A file
    Output : The file with 20% of lines deleted.
comments


if [ $# -eq 0 ] #if no cla is passed
then
    echo "Error : No arguments passed "
else

    num_lines=`cat $1 | wc -l`     # no of lines in the file
    num_delete=$(($(($num_lines*20))/100))   # find 20% lines value

    for i in `seq 1 $num_delete`
    do
	
	line_num=`shuf -i 1-${num_lines} | head -1`   # find the random line number
	
	if [ "`sed -n ${line_num}p $1`" = "<-------DEL------->" ] # if the line already deleted
	then

	    line_num=`shuf -i 1-${num_lines} | head -1` #find the random number again and delete line

	    sed -i "${line_num}d" $1
	    sed -i "${line_num}i\<-------DEL------->" $1
	else                                               #else delete the random line
	    
	    sed -i "${line_num}d" $1
	    sed -i "${line_num}i\<-------DEL------->" $1
	fi
    done
fi
