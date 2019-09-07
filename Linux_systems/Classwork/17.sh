#!/bin/bash

read -p "Enter a name : " name

count=0

while [ $count -lt 10 ]
do
    echo $name
    count=$((++count))

done

