#!/bin/bash

# Florent Dondjeu TSchoufack
# Sept 15, 2020
# Lab 2
# task7.sh

echo -n "Enter a positive integer: "
read NUMB

while [ $NUMB -lt 0 ]; do
	echo -n "Error! Enter a positive integer: "
	read NUMB
done


if [ $NUMB -lt 3 ]; then
	echo "$NUMB! = $NUMB"
else
	let RESULT=NUMB
	let k=NUMB-1
	
	while [ $k -gt 0 ]; do
		let RESULT=RESULT*k
		let k--
	done
	echo "$NUMB! = $RESULT"
fi

exit 0