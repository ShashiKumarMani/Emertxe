#!/bin/bash

echo "Enter a  number"
read num

case $(($num%2)) in
    0)
    	echo "Number is even"
	;;
    1)
    	echo "Number is odd"
	;;
    *)
    	echo "Not a number"
	;;
esac

