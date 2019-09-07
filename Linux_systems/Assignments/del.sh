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
    num_delete=$(($(($num_lines*20))/100))   # find 20%(num_lines) value

    line_num=(`shuf -i 1-${num_lines} | head -$num_delete`) #create random values

    for i in `seq 0 $(($num_delete-1))`
    do
	sed -i "${line_num[$i]}d" $1                      #delete line 
	sed -i "${line_num[$i]}i\<-------DEL------->" $1  # write pattern at that line
    done
fi
