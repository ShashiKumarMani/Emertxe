#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 23 August 2019
    Description : Script to calculate BMI then display the following
		    Underweight  - less than 18.5
		    Normal       - between 18.5 and 24.9
		    Overweight   - between 25 and 29.9
		    Obese        - 30 or greater
    Input : Height and weight - real numbers
    Output : String-(Underweight/Normal/Overweight/Obese)

comments

#read weight and height
read -p "Enter weight in kg : " weight
read -p "Enter height in meters : " height

# BMI=(weight / (height*height))
bmi=`echo "scale=2;$weight / ($height*$height)" | bc`

echo "BMI : $bmi"

#if else statements to print the string
if [ `echo "$bmi < 18.5" | bc` -ne 0 ]
then
    echo "Your Underweight"

elif [ `echo "$bmi < 24.9" | bc` -ne 0 ]
then
    echo "Your Normal"

elif [ `echo "$bmi > 25" | bc` -ne 0 -a `echo "$bmi < 29.9" | bc` -ne 0 ]
then
    echo "Your Overweight"

else
    echo "Your Obese"
fi
