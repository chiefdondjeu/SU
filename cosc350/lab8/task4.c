/*
	Florent Dondjeu Tschoufack
	Nov 10, 2020
	lab 8
	task4.c
 */

#include <stdio.h>
#include <stdlib.h>

#define CMD_SIZE 180

int main(int argc, char* argv[])
{

	if(argc < 3)
	{
		printf("Need at least two arguments!\n");
		exit(1);
	}

	char cmd[CMD_SIZE];
	for(int i = 1; i < argc; i++)
		sprintf(cmd, "%s %s", cmd, argv[i]);

	FILE *fp;
	char buf[BUFSIZ];

	if( (fp = popen(cmd,"r")) != NULL)
	{
		while(fgets(buf, BUFSIZ, fp) != NULL)
			(void) printf("%s\n", buf);
	}

	pclose(fp);
	return 0;
}