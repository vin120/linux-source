#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main(void)
{
//	char buf[100];
//	memset(buf,0,sizeof(buf));
//	strcpy(buf,"hello world\n");
//	write(STDOUT_FILENO,buf, strlen(buf));

//	char buf[100];
//	memset(buf,0,sizeof(buf));
//
//	read(STDIN_FILENO,buf,sizeof(buf));
//	printf("%s\n",buf);

//	char s[] = "abc.txt";
//	int fd = open(s, O_RDONLY);
//
//	if (fd == -1)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("%d\n", fd);
//		close(fd);
//	}



	char s[] = "abc.txt";
	int i = 0;
	close(STDOUT_FILENO);//关闭标准文件输出描述符
	int fd1 = open("/dev/pts/1",O_WRONLY);//打开设备文件/dev/pts/1，该设备将作为标准输出文件描述符

	int fd = open(s, O_RDONLY);
	if(fd == -1)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{
		while(1)
		{
			printf("fd1 = %d,fd = %d : %d",fd1,fd,i++);//printf将会打印到/dev/pts/1上
			sleep(1);
		}
		close(fd);
	}

	return EXIT_SUCCESS;
}
