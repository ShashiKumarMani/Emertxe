#!/bin/bash

echo "Enter  a string : "
read string

echo "The entered string is - $string"

if [ $string = "shashi" ]
then
    echo "string match"
else
    echo "string does not match"
fi
