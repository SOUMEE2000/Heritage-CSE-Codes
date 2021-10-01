#!/bin/bash

a=$1 
b=$2 
number=$3 
# Subroutine to find A 
# to the power B 
power() 
{ 
	num=$1 
	pow=$2 
	counter=1 
	result=1 
	if((pow==0)); then 
		result=1 
	fi 
	if ((num==0)); then 
		result=0 
	fi 
	if((num>=1 && pow>=1)); then while((counter<=pow)) 
	do 
		result=$((result*num)) 
		counter=$((counter + 1)) 
	done 
	fi 
	#Printing the result 
	echo "$1 to the power $2 is $result" } 
	while((1)) 
	do 
		# Input type of operation 
		echo "Enter Choice :" 
		echo "1. Addition" 
		echo "2. Subtraction" 
		echo "3. Multiplication" 
		echo "4. Division" 
		echo "5. Power"
		echo "6. Square root" 
		echo "7. Exit" 
		read ch 
		# Switch Case to perform 
		# calculator operations 
		case $ch in 
			1)res=`echo $a + $b | bc` 
				;; 
			2)res=`echo $a - $b | bc` 
				;; 
			3)res=`echo $a \* $b | bc` 
				;; 
			4)res=`echo "scale=2; $a / $b" | bc` 
				;; 
			5)power $a $b 
				;; 
			6)res=square_root=`echo "scale=4; sqrt($number)" | bc` 
				;; 
			7)exit 1 
		esac 
		echo " Result is : $res" 
	done 
