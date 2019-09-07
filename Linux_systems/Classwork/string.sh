#!/bin/bash

echo Enter a string

read string

if [ $string -n 0 ]
then
    echo CORRECT
else
    echo INCORRECT
fi

