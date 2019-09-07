#!/bin/bash

echo "Enter the weight and height"
read weight height

bmi=`echo "scale=02 $((((weight/((height*height))))))" | bc`

echo "BMI : $bmi"

if [ $bmi -lt 18.5 ]
then
    echo "Underweight"
elif [ $bmi -lt 24.9 ]
then
    echo "Normal"
elif [ $bmi -ge 25 ]
then
    if [ $bmi -lt 29.9 ]
    then
    	echo "Overweight"
    fi
else
    echo "Obese"
fi

