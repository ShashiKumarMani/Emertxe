#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 26 August 2019
    Description : Script to generate random 8-character passwords including alpha-numeric characters
    Input : -N-
    Output : 8-character random passwords
comments

# tr : delete all character except alpha numbers,punctuations , 
# fold :   limit 8 characters per line and  head : print top 10 lines
cat /dev/urandom | tr -dc [:alpha:][:punct:] | fold -w 8 | head -n 15

