#!/bin/bash

read -p "Enter a number : " num

while [ $num -ge 0 ]
do
    echo $num
    num=$((--num))
done

