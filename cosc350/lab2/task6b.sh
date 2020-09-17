#!/bin/bash

# Florent Dondjeu TSchoufack
# Sept 15, 2020
# Lab 2
# task6b.sh

STAR="*"

for i in $(seq 1 5);
do
	for ((j = 1; j <= i; j++));
	do
		printf "$STAR"
	done
	echo
done

for i in $(seq 4 1);
do
	for ((j = 1; j <= i; j++));
	do
		printf "$STAR"
	done
	echo
done

exit 0