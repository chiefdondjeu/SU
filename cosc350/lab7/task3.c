/*
	Florent Dondjeu Tschoufack
	Nov 1, 2020
	lab 7
	task3.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();
	int fd, status;

	if( (fd = open("foo", O_CREAT | O_RDWR, 0600)) < 0)
	{
		printf("foo write/create file error!");
		exit(1);
	}

	if(pid == 0) /* child process */
	{
		char* message = "Hi, Mom";

		write(fd,message,strlen(message));
	}
	else /* parent process */
	{
		pid = wait(&status);
		if( (access("foo",F_OK)) == -1)
		{
			printf("Parent: foo file does not exit!\n");
			exit(1);
		}

		char* output = "My son said ";

		int c_size = lseek(fd,0,SEEK_END);
		int p_size = strlen(output) + c_size;

		char child_msg[c_size], parent_msg[p_size+1];
		//+1 to take into account "\n"

		pread(fd,child_msg,c_size,SEEK_SET); //read foo file
		sprintf(parent_msg,"My son said %s\n",child_msg);

		write(1,parent_msg,p_size+1);	//write to console
	}

	close(fd);
	exit(0);
}