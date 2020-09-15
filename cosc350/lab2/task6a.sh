#!/bin/sh
#task6a.sh

for i in $(seq 1 5);
do
	for ((j = 1; j <=i; j++));
	do
		printf "$i";
	done
	echo ""
done
exit 0