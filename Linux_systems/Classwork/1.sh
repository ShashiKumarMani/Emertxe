#!/bin/bash

echo "Enter the length and breadth"
read length breadth

var=$((2*$(($length+$breadth))))

echo "The perimeter of the rectangle is $var"
