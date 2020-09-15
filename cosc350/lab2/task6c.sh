#!/bin/sh
#task6c.sh

echo "Enter an integer"
read numb

while [ $numb -lt 5 ] || [ $numb -gt 9 ]; do
	echo "Error! Input integer between 5-9!"
	read numb
done

x=$numb

for i in $(seq 1 $numb); do
	for ((k = x; k > 0; k--)); do
		printf " "
	done

	for ((j = 1; j <= i; j++)); do
		printf "$i ";
	done

	echo " "
	let x--
done

exit 0