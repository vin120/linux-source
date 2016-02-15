#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg,char *args[])
{
	printf("a begin\n");
	int fd = open("a.txt",O_RDONLY);
	if (fd == -1)
	{
		printf("error is %s\n",strerror(errno));
		return EXIT_FAILURE;
	}
	pid_t pid = fork();
	if(pid < 0)
	{
		printf("fork failed %s\n",strerror(errno));
		return EXIT_FAILURE;
	}

	if(pid > 0)
	{
		close(fd);
	}

	if(pid == 0)
	{
		char s[128];
		memset(s,0,sizeof(s));
		sprintf(s,"%d",fd);
		char *args[] = {"b",s,NULL};
		if(execve("b",args,NULL) == -1)
		{
			printf("execve failed %s\n",strerror(errno));
		}
	}

	printf("a end\n");
	return EXIT_SUCCESS;
}
