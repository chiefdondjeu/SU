/*
	Florent Dondjeu Tschoufack
	Nov 25, 2020
	lab 10
	msgQrcv.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg {
	long int msg_type;
	char some_text[200];
};

int main()
{
	struct my_msg buf;
	int msqid;
	key_t key;

	int numb1, numb2, sum;
	char my_eof = (char)4;

	if ((key = ftok("msgQsnd.c",'B')) == -1) {
		perror("ftork error");
		exit(1);
	}

	//open message queue
	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
		perror("msgget error");
		exit(1);
	}
	
	while(1) {
		if (msgrcv(msqid, (struct my_msg *)&buf, sizeof(buf), 0, 0) == -1) {
			perror("msgrcv error");
			exit(1);
		}
		
		//when receive eof char, exit loop
		if (buf.some_text[0] == my_eof) break;

		if (sscanf(buf.some_text, "%d%d", &numb1, &numb2) != 2) {
			printf("error; incorrect number of input\n");
		} else {
			sum = numb1+numb2;
			printf("Sum: %d\n", sum);
		}
	}

	if (msgctl(msqid, IPC_RMID, NULL) == -1) {
		perror("msgctl error");
		exit(1);
	}

	exit(0);
}
