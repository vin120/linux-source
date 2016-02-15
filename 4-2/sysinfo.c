#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void printffile(const char *filename) //打印filename指定的文件内容
{
	FILE *p = fopen(filename,"r");
	if(p == NULL)
	{
		printf("error is %s\n",strerror(errno));
		return ;
	}
	char buf[1024]; //定义一个buffer，存放cpuinfo读取到的内容

	while(1)
	{
		memset(buf,0,sizeof(buf));
		if(fgets(buf,sizeof(buf),p) ==NULL)
		{
			break;
		}
		printf("%s",buf);
	}
	fclose(p);
}

int main(int arg, char *args[])
{
	printffile("/proc/cpuinfo"); //读取/proc/cpuinfo文件，cpuinfo文件中存放系统CPU信息
	printffile("/proc/meminfo");
	return 0;
}
