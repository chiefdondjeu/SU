#!/bin/bash
#task6b.sh

star="*"

for i in $(seq 1 5);
do
	for ((j = 1; j <= i; j++));
	do
		printf "$star"
	done
	echo ""
done

for i in $(seq 4 1);
do
	for ((j = 1; j <= i; j++));
	do
		printf "$star"
	done
	echo ""
done

exit 0