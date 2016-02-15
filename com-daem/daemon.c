/*
 * daemon.c
 *
 *  Created on: Jan 26, 2016
 *      Author: cc
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int signal1(int signo,void(*func)(int))
{
	struct sigaction act,oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	return sigaction(signo,&act,&oact);
}


void setdaemon()
{
	pid_t pid ,sid;
	pid = fork();
	if(pid < 0)
	{
		printf("fork failed %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(pid > 0)
	{
		exit(EXIT_SUCCESS);
	}

	if(sid =setsid() < 0)
	{
		printf("setsid failure %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}

}


void listenfifo()
{
	const char *sfifoname = "fifo1";
	int len = 0;
	char buf[1024];
	memset(buf,0,sizeof(buf));
	int fd = open(sfifoname,O_RDONLY);
	if(fd == -1)
	{
		printf("open %s failed,%s\n",sfifoname,strerror(errno));

	}
	len = read(fd,buf,sizeof(buf));
	if(len > 0)
	{
		if(buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) - 1] = 0;
		}
		close(STDOUT_FILENO);
		open(buf,O_WRONLY);
	}
	close(fd);
}


void catch_Signal(int Sign)
{
	switch(Sign)
	{
	case SIGINT:
		listenfifo();
		break;
	case SIGPIPE:
		break;
	}
}



int main(void)
{
	setdaemon(); //把进程设置成daemon状态
	signal1(SIGINT,catch_Signal);//捕捉Signal 信号
	signal1(SIGPIPE,catch_Signal);//捕捉Signal 信号
	while(1)
	{
		puts("hello world");
		sleep(1);

	}
	return EXIT_SUCCESS;
}
