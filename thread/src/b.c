/*
 * b.c
 *
 *  Created on: Feb 2, 2016
 *      Author: cc
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int arg,char *args[])
{
	printf("b start\n");
	if(args[1] == NULL)
	{
		return EXIT_FAILURE;
	}

	int fd = atoi(args[1]);
	if(fd == 0)
	{
		return EXIT_FAILURE;
	}
	char buf[1024];
	memset(buf,0,sizeof(buf));
	read(fd,buf,sizeof(buf));
	printf("%s\n",buf);
	close(fd);
	printf("b end\n");
	return EXIT_SUCCESS;

}

