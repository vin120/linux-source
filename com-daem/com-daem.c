/*
 * com-daem.c
 *
 *  Created on: Jan 25, 2016
 *      Author: cc
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>



void readfifo() //读取fifo管道文件内容
{
	int len = 0;
	char buf[1024];
	memset(buf,0,sizeof(buf));
	int fd = open("~/workspace/c++/tutorial/com-daem/fifo1",O_RDONLY);
	if(fd == -1)
	{
		printf("open fifo error %s\n",strerror(errno));
		return;
	}
	while((len = read(fd,buf,sizeof(buf))) > 0)  //循环读取管道文件内容，直到管道文件被关闭，
	{
		printf("%s\n",buf);
		memset(buf,0,sizeof(buf));
	}
	close(fd);
	return;
}

void setdaemon() //把程序设置为daemon状态
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("fork error\n");
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

	if(pid > 0)
	{
		exit(0);
	}


}



int main(void)
{
	setdaemon();
	readfifo();
	return EXIT_SUCCESS;
}

