//Florent Dondjeu Tschoufack
//Oct 26, 2020
//lab6
//child.c

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int convertToInt(char *str, int n)
{
	int numb = 0;
	for (int i = 0; i < n; i++)
		numb = numb * 10 + str[i] - '0';

	return numb;
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("prg needs 3 arguments to run!\n");
        exit(1);
    }

    int exit_code = 37;

    char* message = argv[0];
    int Nc = convertToInt(argv[1],strlen(argv[1]));
    int Tc = convertToInt(argv[2],strlen(argv[2]));

    int n = Nc;
    for(; n > 0; n--)
    {
        printf("%s: PID = %d\n", message, getpid());
        sleep(Tc);
    }

    exit(exit_code);
}
