#!/bin/bash

echo "Enter your name : "
read usnm

hour=`date +%H`
min=`date +%M`
sec=`date +%S`
day=`date +%D`
greet=""

if [ $hour -ge 4 -a $hour -le 12 ]
then
        greet="Good Morning"
elif [ $hour -ge 12 -a $hour -le 16 ]
then
        greet="Good Afternoon"
elif [ $hour -ge 16 -a $hour -le 19 ]
then
        greet="Good Evening"
elif [ $hour -ge 19 -o $hour -le 4 ]
then
        greet="Good Night"
fi

msg="${greet} ${usnm}!. Today is ${day}. Time is ${hour} : ${min} : ${sec}. Process id of the terminal is: $$"
echo $msg
