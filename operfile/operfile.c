/*
 * main.c
 *
 *  Created on: Jan 11, 2016
 *      Author: cc
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void myprintf(const char *s)
{
	write(STDOUT_FILENO,s,strlen(s));
}



/**
 * 		read file
 *
 */

/*
int main(int arg,char *args[])
{
	if(arg < 2)
	{
		return 0;
	}
	int fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error is %s\n", strerror(errno));
	}
	else
	{
		printf("success fd = %d\n", fd);
		char buf[100];
		memset(buf, 0, sizeof(buf));
		while(read(fd,buf,sizeof(buf) -1 ) > 0)
		{
			printf("%s\n", buf);
			memset(buf,0,sizeof(buf));
		}
		close(fd);
	}
	return 0;
}
*/

/**
 * write file
 *
 *
 */
int main(int arg,char *args[])
{
	int fd = open(args[1],O_RDWR | O_APPEND);

	if(fd == -1)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{
		printf("success fd = %d\n",fd);
		char buf[100];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"hello world\n");
		int i = write(fd,buf,strlen(buf));
		close(fd);
	}


	return 0;
}

