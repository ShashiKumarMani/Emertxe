#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 30 August 2019
    Description : Script that takes any number of directories as command line arguments and then lists the contents of each of these directories.
    Input : Directories
    Output : Contents of directories and sub-directories.
comments

#all_files=(`echo *`)
#num_files=`echo * | wc -w` #contents are printed in a single line

function print_ls()
{
    cd $1

    all_files=(`echo *`)
    num_files=`echo * | wc -w`

    for i in `seq 0 $(($num_files-1))`
    do
	if [ -f ${all_files[$i]} ]
	then
	    echo " ${all_files[$i]}"
	elif [ -d ${all_files[$i]} ]
	then
	    echo "Moving into directory ${all_files[$i]} "
	    print_ls ${all_files[$i]}
	    cd ..
	fi
    done
}

print_ls $PWD
<<vvv
for i in `seq 0 $(($num_files-1))`
do
    if [ -f ${all_files[$i]} ]
    then
	echo " ${all_files[$i]}"

    elif [ -d ${all_files[$i]} ]
    then

	cd ${all_files[$i]}
	echo "------- "
	echo "Directory : ${all_files[$i]}"
	echo "--" *
	echo "------- "
	cd ..
    fi
done
vvv
