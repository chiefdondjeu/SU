#!/bin/bash

# Florent Dondjeu TSchoufack
# Sept 15, 2020
# Lab 2
# task6c.sh

echo -n "Enter an integer: "
read NUMB

while [ $NUMB -lt 5 ] || [ $NUMB -gt 9 ]; do
	echo -n "Error! Input integer between 5-9: "
	read NUMB
done

x=$NUMB
echo

for i in $(seq 1 $NUMB); do
	for ((k = x; k > 0; k--)); do
		printf " "
	done

	for ((j = 1; j <= i; j++)); do
		printf "$i ";
	done

	echo
	let x--
done

exit 0