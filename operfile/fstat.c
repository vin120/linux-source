/*
 * fstat.c
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
/*
int main(int arg, char *args[])
{
	int fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error is %s\n", strerror(errno));
	}
	else
	{
		printf("success fd = %d\n", fd);
		struct stat buf;
		fstat(fd, &buf);
		if (S_ISREG(buf.st_mode))
		{
			printf("%s is charfile\n", args[1]);
		}

		if (S_ISDIR(buf.st_mode))
		{
			printf("%s is dir\n", args[1]);
		}

		printf("%s size= %d\n", args[1], buf.st_size);

		close(fd);
	}
	return 0;
}
*/
int main()
{
	char *s = getpass("please input:");
	printf("%s\n", s);
	return 0;
}
