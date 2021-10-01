#!/bin/sh
#simple if-else=================================================
if [ $1 -lt 10 ];
then
	echo "$1 is a one digit number"
else
	echo "$1 has more than one digit"
fi

#if-else with OR condition, then on next line=====================
if [ $1 -eq 10 -o $1  -eq 20 ]
then
	echo "Correct Input"
else
	echo "Expected 10 OR 20"
fi

#if-else with AND condition, then on same line=====================
if [ $2 = "csen2253" -a $3 = "oslab" ]; then
	echo "correct input"
else
	echo "2nd argument is csen2253 and 3rd argument is oslab"
fi

#if-elseif==========================================================
echo "Enter a number"
read n

if [ $n -eq 100 ];
then
	pat=1
	echo "You got Full Marks"
elif [ $n -lt 100 -a $n -gt 40 ];
then
	pat=2
	echo "You passed the exam"
else
	echo "Sorry, try next time"
fi
#same program with case================================================

case $pat in
1)
	echo "You got Full Marks";;
2)
	echo "You passed the exam";;
*)
	echo "Sorry, try next time" ;;
esac
