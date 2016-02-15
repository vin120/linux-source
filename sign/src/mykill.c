/*
 * mykill.c
 *
 *  Created on: Jan 22, 2016
 *      Author: cc
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

int main(int argc,char* argv[])
{
//	chdir("/");
//	if(argc > 1)
//	{
//		int pid  = atoi(argc[1]);
//		kill(pid,SIGUSR1);
//	}

	pid_t pid  = fork();
	if(pid == -1)
	{
		return -1;
	}

	if(pid > 0)
	{
		exit(0);
	}

	if(pid == 0)
	{
		setsid();
		chdir("/");
		umask(0);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
	syslog(LOG_INFO,"my deamin is OK ");

	return EXIT_SUCCESS;
}
