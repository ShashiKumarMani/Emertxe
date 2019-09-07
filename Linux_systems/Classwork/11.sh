#!/bin/bash

echo -n "Enter your choice : "
read choice

case ${choice} in
    "Y")
    	echo "YOU HAVE ENTERED - YES"
	;;
    "y")
    	echo "YOU HAVE ENTERED - YES"
	;;
    "N")
    	echo "YOU HAVE ENTERED - NO"
	;;
    "n")
    	echo "YOU HAVE ENTERED - NO"
	;;
    *)
    	echo "ERROR:Enter a valid choice"
	;;
esac



