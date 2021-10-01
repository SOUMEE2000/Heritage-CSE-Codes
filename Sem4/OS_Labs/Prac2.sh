#!/bin/bash

high=$2
low=$1

for((i=$low; i<=$high; i++))
do
     if (($i%2==0))
     then
        echo "$i is an even number"
     else
	echo "$i is an odd number"
     fi
done

