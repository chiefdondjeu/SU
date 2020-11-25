/*
	Florent Dondjeu Tschoufack
	Nov 25, 2020
	lab 10
	msgQsnd.c
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

	char my_eof = (char)4;

	if ((key = ftok("msgQsnd.c",'B')) == -1) {
		perror("ftork error");
		exit(1);
	}

	//create message queue
	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
		perror("msgget error");
		exit(1);
	}

	printf("Enter two integers\n");
	buf.msg_type = 1;
	while (gets(buf.some_text), !feof(stdin)) {
		if (msgsnd(msqid, (struct my_msg *)&buf, sizeof(buf), 0) == -1)
			perror("msgsnd error");
	}

	//send eof as last message
	buf.some_text[0] = my_eof;
	msgsnd(msqid, (struct my_msg *)&buf, sizeof(buf), 0);

	exit(0);
}
