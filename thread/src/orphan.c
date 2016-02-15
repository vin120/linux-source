/*
 * orphan.c
 *
 *  Created on: Jan 31, 2016
 *      Author: cc
 */

/**
 * 编写100个孤儿进程
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int arg,char *args[])
{
	pid_t pid = fork();
	if (pid < 0)
	{
		printf("fork failed %s\n",strerror(errno));
		return -1;
	}

	if(pid > 0)
	{
		exit(0);
	}

	if ( pid == 0)
	{
		 int i  = 0;
		 for(;i < 100; i++)
		 {
			 pid_t pid_tmp = fork();
			 if(pid_tmp == 0)
			 {
				 exit(0);
			 }

		 }
		 pause();
	}

	return 0;
}
