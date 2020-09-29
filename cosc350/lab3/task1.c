//Florent Dondjeu Tschoufack
//Sept 22, 2020
//lab3
//task1.c

#include <stdio.h>
#include <unistd.h>

int main()
{	
    char c;
	int nread;

    //reads given input from terminal and outputs it
	while( (nread = read(0,&c,1)) > 0)
		write(1,&c,nread);

	return 0;
}
