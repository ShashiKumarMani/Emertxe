#!bin/bash

echo -n Enter the number : 
read num


if [ $num -gt 0 ]
then
if [ $($num %2) -eq 0]
then 
echo POSITIVE EVEN
else
echo POSITIVE ODD
fi

if [ $($num % 2) -eq 0 ]
then
echo NEGATIVE EVEN
else
echo NEGATIVE ODD
fi


