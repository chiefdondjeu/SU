#!/bin/bash

# Florent Dondjeu TSchoufack
# Sept 15, 2020
# Lab 2
# task8.sh

if [ $# -lt 1 ]; then
	echo "You need to pass one numerical argument"
elif [ $# -gt 1 ]; then
	echo "You only need one numerical argument"
else
	let SIZE=${#1}-1
	SUM=0
	for i in $(seq 0 $SIZE); do
		TEMP=${1:i:1}
		let SUM=SUM+TEMP
	done
	echo $SUM
fi

exit 0