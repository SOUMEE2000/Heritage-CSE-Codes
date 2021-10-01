#!/bin/bash
#while loop with CONDITIONAL exit using break==============================
con=true
ct=1
while [ $con ]
do
	echo $ct
	if [ $ct -eq 5 ];
	then
		break
	fi
	((ct++))
done

#while loop with FIXED Exit=============================
n=1
while [ $n -le 5 ]
do
       echo "$n execute"
       (( n++ ))
done

#for loop with STATIC values=============================
for vibgyor in Violet Indigo Blue Green Yellow Orange Red
do
	echo "Color = $vibgyor"
done

#for loop with  c like syntax
for (( n=1; n<=10; n++ ))
do
	if (( $n%2==0 ))
	then
		echo "$n is even"
	else
		echo "$n is odd"
	fi
done

