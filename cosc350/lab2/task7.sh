#!/bin/sh
#task7.sh

echo "Enter a positive integer"
read numb

while [ $numb -lt 0 ]; do
	echo "Error! Enter a positive integer"
	read numb
done


if [ $numb -lt 3 ]; then
	echo "$numb! = $numb"
else
	let i=numb
	let k=numb-1
	
	while [ $k -gt 0 ]; do
		let i=i*k
		let k--
	done
	echo "$numb! = $i"
fi

exit 0