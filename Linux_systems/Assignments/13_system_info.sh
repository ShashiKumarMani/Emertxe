
#!/bin/bash

<< comments
    Author : Shashi Kumar M
    Date : 21 August 2019
    Description : Script to print system information
    Input : Choice by the user - An integer
    Output : The system information
comments

read -p $'1. Currently logged in users\n2. Your shell directory\n3. Home directory\n4. OS name and version\n5. Current working diurectory\n6. Number of users logged in\n7. Show all available shells in the system\n8. Hard disk information\n9. CPU information\n10. Memory information\n11. File system information\n12. Currenly running processes\nEnter the choice : ' choice

case $choice in
    "1")
	echo "Currenly logged in user : `whoami`"
	;;
    "2")
	echo "Your shell directory : $SHELL "
	;;
    "3")
	echo "Home directory : $HOME"
	;;
    "4")
	echo "OS name : `uname -s`"
	echo "OS version : `uname -v`"
	;;
    "5")
	echo "Currently working directory $PWD"
	;;
    "6")
	echo "Number of users logged in  : `who | wc -l`"
	;;
    "7")
	echo "Show all available shell in the system "
	echo "`cat /etc/shells`"
	;;
    "8")
	echo "Hard disk information :"
	du -H
	;;
    "9")
	echo "CPU information  : "
	lscpu
	;;
    "10")
	echo "Memory information "
	lsmem
	;;
    "11")
	echo "File system information "
	df -H 
	;;
    "12")
	echo "Currently running process "
	ps
	;;
       *)
	echo "Enter valid choice "
	;;
esac
