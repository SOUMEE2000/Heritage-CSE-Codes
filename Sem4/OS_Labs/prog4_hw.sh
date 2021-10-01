#!/bin/bash
for f in * 
do 
	if [ -f $f ]; then echo "$f"; fi 
done 
total=0 
for size in $(ls -l | tr -s ' ' | cut -d ' ' -f 5) ; do 
	total=$(( ${total} + ${size} )) 
done 
echo "Sum Of size of all the file is ${total}" 

