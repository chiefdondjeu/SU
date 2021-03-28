/*
	Florent Dondjeu Tschoufack
	Dec 1, 2020
	lab 11
	blackJack.c
 */

#include <stdio.h>

const char spade[] = "\xe2\x99\xa0";
const char club[] = "\xe2\x99\xa3";
const char heart[] = "\xe2\x99\xa5";
const char diamond[] = "\xe2\x99\xa6";

void cardAce(const char[]);
void cardTwo(const char[]);
void cardThree(const char[]);
void cardFour(const char[]);
void cardFive(const char[]);
void cardSix(const char[]);
void cardSeven(const char[]);
void cardEight(const char[]);
void cardNine(const char[]);
void cardTen(const char[]);
void cardJoker(const char[]);
void cardQeen(const char[]);
void cardKing(const char[]);

int main()
{
	cardAce(spade);

	cardTwo(club);
	cardThree(heart);
	cardFour(diamond);
	cardFive(spade);
	cardSix(club);
	cardSeven(heart);
	cardEight(diamond);
	cardNine(spade);
	cardTen(club);

	cardJoker(heart);
	cardQeen(diamond);
	cardKing(spade);

	return 0;
}

void cardAce(const char pic[])
{
	printf("----------\n");
	printf("|A       |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|       A|\n");
	printf("----------\n");
}

void cardTwo(const char pic[])
{
	printf("----------\n");
	printf("|2       |\n");
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("|       2|\n");
	printf("----------\n");
}

void cardThree(const char pic[])
{
	printf("----------\n");
	printf("|3       |\n");
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("|       3|\n");
	printf("----------\n");
}

void cardFour(const char pic[])
{
	printf("----------\n");
	printf("|4       |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|       4|\n");
	printf("----------\n");
}

void cardFive(const char pic[])
{
	printf("----------\n");
	printf("|5       |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|       5|\n");
	printf("----------\n");
}

void cardSix(const char pic[])
{
	printf("----------\n");
	printf("|6       |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|       6|\n");
	printf("----------\n");
}

void cardSeven(const char pic[])
{
	printf("----------\n");
	printf("|7       |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|       7|\n");
	printf("----------\n");
}

void cardEight(const char pic[])
{
	printf("----------\n");
	printf("|8       |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|   %s    |\n", pic);
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("|   %s    |\n", pic);
	printf("| %s    %s |\n", pic, pic);
	printf("|       8|\n");
	printf("----------\n");
}

void cardNine(const char pic[])
{
	printf("----------\n");
	printf("|9       |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|   %s    |\n", pic);
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|       9|\n");
	printf("----------\n");
}

void cardTen(const char pic[])
{
	printf("----------\n");
	printf("|10      |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|   %s   |\n", pic);
	printf("| %s    %s |\n", pic, pic);
	printf("|        |\n");
	printf("| %s    %s |\n", pic, pic);
	printf("|   %s    |\n", pic);
	printf("| %s    %s |\n", pic, pic);
	printf("|      10|\n");
	printf("----------\n");
}

void cardJoker(const char pic[])
{
	printf("----------\n");
	printf("|%sJ      |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|      J%s|\n", pic);
	printf("----------\n");
}

void cardQeen(const char pic[])
{
	printf("----------\n");
	printf("|%sQ      |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|      Q%s|\n", pic);
	printf("----------\n");
}

void cardKing(const char pic[])
{
	printf("----------\n");
	printf("|%sK      |\n", pic);
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|        |\n");
	printf("|      K%s|\n", pic);
	printf("----------\n");
}

