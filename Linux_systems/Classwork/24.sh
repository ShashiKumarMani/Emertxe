#!/bin/bash
# Simple function script to add two numbers

function sum()
{
    sum=0
    arr=($@)
    for i in `seq 0 $((${#arr[@]}-1))`
    do
	sum=$(($sum+${arr[$i]}))
    done
    echo $sum
}

function sum1()
{
    for i in $@
    do
    	total=`echo $total + $i | bc`
    done
    echo $total

}
read -p "enter two numbers : " num1 num2 num3 num4

#function call
sum=`sum1 $num1 $num2 $num3 $num4`

echo "The sum is $sum "

#use function in echo
echo "The sum of 1 and 5 is `sum 1 5` "

if [ $# -lt 4 ]
then
    echo "Enter min. 4 cla "
else
    echo "The sum of $3 and $4 is `sum $3 $4` "
fi
