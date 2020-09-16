#!/bin/sh
#task8.sh

if [ $# -lt 1 ]; then
	echo "You need to pass one numerical argument"
elif [ $# -gt 1 ]; then
	echo "You only need one numerical argument"
else
	let size=${#1}-1
	x=0
	for i in $(seq 0 $size); do
		y=${1:i:1}
		let x=x+y
	done
	echo $x
fi

exit 0