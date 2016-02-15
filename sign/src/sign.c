/*
 ============================================================================
 Name        : sign.c
 Author      : cc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <syslog.h>


//int func1(int a, int b)
//{
//	return a + b;
//}
//

int status = 0;
void catch_Signal(int Sign)
{
	switch(Sign)
	{
	case SIGINT:
		printf("SIGINT Signal\n");
		exit(0);
	case SIGALRM:
		printf("SIGALRM Signal\n");
		break;
	case SIGUSR1:
		status = 1;
		break;
	}
}



int signal1(int signo,void(*func)(int))
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	return sigaction(signo,&act,&oact);
}


void setdaemon()
{
	pid_t pid = fork();
	if(pid == -1)
		return ;
	if(pid > 0)
		exit(0);

	if(pid == 0)
	{
		setsid();
	}
}


int main(int argc, char *argv[])
{
//	pause();
//	printf("end\n");
//	int (*p)(int,int);
//	p = func1;
//	printf("p = %d\n",p(5,3));

	setdaemon();
	signal1(SIGINT,catch_Signal);
	signal1(SIGALRM,catch_Signal);
	signal1(SIGKILL,catch_Signal);
	signal1(SIGTERM,catch_Signal);
	signal1(SIGUSR1,catch_Signal);

	int i  = 0;
	while(1)
	{
//		alarm(5);
//		printf("hello\n");
		if (status == 1)
			printf("helloworld%d\n",i++);
		sleep(1);
	}

	return EXIT_SUCCESS;
}
