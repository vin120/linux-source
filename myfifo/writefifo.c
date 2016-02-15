/*
 * writefifo.c
 *
 *  Created on: Jan 19, 2016
 *      Author: cc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int len = 0;
	char buf[100];
	memset(buf,0,sizeof(buf));
	int fd = open("fifo1",O_WRONLY);
	while(1)
	{
//		scanf("%s",buf);
		read(STDIN_FILENO,buf,sizeof(buf));
		if(buf[0] == '0')
			break;
		write(fd,buf,strlen(buf));
		memset(buf,0,sizeof(buf));

	}
	close(fd);
	return 0;
}
