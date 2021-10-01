#!/bin/bash
echo "Even numbers are: "
for (( i=$1 ; i<=$2 ; i++ ))
do
	if (( $i%2==0 ))
	then
	      echo "$i "
	fi
done

echo "Odd numbers are: "
for (( i=$1 ; i<=$2 ; i++ ))
do
        if (( $i%2!=0 ))
        then
              echo "$i "
        fi
done

flag=1

echo "Prime numbers in the range are: "
for (( i=$1 ; i<=$2; i++ ))
do
	for (( j=2 ; j<=$i/2; j++ ))
        do
		if (( $i%$j==0 ))
		then
			flag=0
			break
		else
			flag=1
		fi
	done
	
	if [ $flag -ne 0 ]
	then
		echo "$i"
	fi
done
