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

void writefifo()
{
	char buf[1024];
	memset(buf,0,sizeof(buf));
	int fd = open("~/workspace/c++/tutorial/com-daem/fifo1",O_WRONLY);
	if(fd == -1)
	{
		printf("write fifo1 error %s\n",strerror(errno));
		return ;
	}
	while(1)
	{
		memset(buf,0,sizeof(buf));
		scanf("%s",buf);
		write(fd,buf,sizeof(buf));

	}
	close(fd);
	return;
}



int main(void)
{
	writefifo();
	return EXIT_SUCCESS;
}

