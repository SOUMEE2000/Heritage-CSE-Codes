#!/bin/sh
# This is a comment!
echo "Hello      World"       # This is a comment, too!
: 'this 
is 
a
multiline
comment'

#variations of echo
echo "Hello World"
echo "Hello * World"
echo Hello * World
echo Hello      World
echo "Hello" World
echo Hello "     " World
echo "Hello "*" World"
echo 'hello' world

#variables
echo "\n"
x=32
y=5
crscode=csen2253
crstitle=OSlab

#Basic Arithmetic
echo "Sum is `expr $x + $y`" #expr is external program
echo "Difference  is $(($x-$y))"
echo "Product is `expr $x \* $y`"
echo "Quotient  is $(($x/$y))"
echo "Remainder is `expr $x % $y`"
fp=`echo "scale=2; $x/$y" | bc` #bc is external program
echo "Floating Point Division $fp"

#arguments
echo "\n"
echo "I was called with $# parameters" # $#number of args
echo "My name is $0" # $0 prg name
echo "My first parameter is $1" # $1 .... $9 arg names
echo "My second parameter is $2" # $1 .... $9 arg names
echo "All parameters are $@" # $@ all arg names
echo "Last Return is $?" # $? return code from last program
echo "PID of Current Shell is $$" # $$ process id of current shell

#user input
echo "\n"
echo "Enter your name : "
read usnm
day=`date +%A`
course="$crscode $crstitle"
msg="Welcome ${usnm} to ${course}. Today is ${day}."
echo $msg
