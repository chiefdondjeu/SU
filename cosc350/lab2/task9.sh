#!/bin/bash

# Florent Dondjeu TSchoufack
# Sept 17, 2020
# Lab 2
# task9.sh

# search for directory
read -p "Input name of directory: " DIR_NAME

if [ -d $DIR_NAME ]; then
	echo $"$DIR_NAME exist."

	# search a file in directory
	COUNT=3
	while [ $COUNT != 0 ]; do
		echo
		read -p "Input a file name from $DIR_NAME: " FILE_NAME
		FILE_LOCATION=$DIR_NAME/$FILE_NAME
		if [ -e $FILE_LOCATION ]; then
			if [ -d $FILE_LOCATION ]; then
				echo -n "$FILE_NAME is not a file!"
			else
				echo "$FILE_NAME was found."
				break
			fi
		else
			echo -n "$FILE_NAME does not exist!"
		fi
		let COUNT--
		echo -n " Attempts left: $COUNT"
		echo
	done

	if [ $COUNT == 0 ]; then
		echo $'\nYou have ran out of attempts!'
		exit 2
	fi

	# check file readability
	if [ -r $FILE_LOCATION ]; then
		echo "$FILE_NAME is readable."

		# search a word in the file
		echo
		read -p $"Input a word to be searched in $FILE_NAME: " WORD

		SEARCH=$(grep -i "$WORD" $FILE_LOCATION) # not case sensitive

		if [ "$SEARCH" = "$WORD" ]; then
			echo "$WORD is FOUND!"
			exit 0
		else
			echo "$WORD is not FOUND!"
			exit 4
		fi 
		#last nested if/else

	else
		echo "$FILE_NAME is not readable!"
		exit 3
	fi

else
	echo "$DIR_NAME does not exist!"
	exit 1
fi
# end of program