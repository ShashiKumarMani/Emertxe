#!/bin/bash

echo "Enter a string : "
read string

if [[ -n ${string} ]]
then
    echo "String not empty"
else
    echo "String empty"
fi
