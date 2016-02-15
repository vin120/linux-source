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
	int fd = open("fifo1",O_RDONLY);
	while((len = read(fd,buf,sizeof(buf))) > 0)
	{
		printf("%s",buf);
		memset(buf,0,sizeof(buf));
	}
	close(fd);

	return 0;
}
