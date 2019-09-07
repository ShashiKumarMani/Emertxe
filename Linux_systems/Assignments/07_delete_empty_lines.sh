#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Delete empty lines from a file using sed command
    Input : A file containing empty lines
    Output : The file with empty lines removed.
comments


if [ $# -eq 0 ]
then
    echo "Error : Please pass the arguments through the command line. "
else
    sed -i '/^$/d' $1 #Delete empty lines,
			# regex ^ - start of string / line, $ - end of string / line

    sed -i 's/[[:blank:]]//g' $1 #deletes empty spaces
				    # substitute/blank_spaces with/NAN/g - g to perform it on the whole line

    echo "Empty lines deleted. "
fi



