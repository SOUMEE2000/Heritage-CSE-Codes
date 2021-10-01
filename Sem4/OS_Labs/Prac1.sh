#!/bin/sh
a=$1
b=$2
read a
read b
echo "$2"
echo "$1"

divide=`echo $a / $b |bc`
sum=$(($a + $b))
res=`echo $a \* $b | bc`

echo "Sum is ${sum}, multiplication is $res, division is ${divide} "
