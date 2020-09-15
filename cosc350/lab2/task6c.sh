#!/bin/sh
#task6c.sh

echo "Enter an integer"
read numb

while [ $numb -lt 5 ] || [ $numb -gt 9 ]; do
	echo "Error! Input integer between 5-9!"
	read numb
done

echo "done"
exit 0