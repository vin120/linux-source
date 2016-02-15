#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void sort(int *src,int len)
{
	int i, j, tmp;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len -i; j++)
		{
			if (src[j] > src[j + 1])
			{
				tmp = src[j];
				src[j] = src[j + 1];
				src[j + 1] = tmp;
			}
		}
	}
}

int main(int arg, char *args[])
	{
		FILE *p1 = fopen("a.txt","r"); //以只读的方式打开名为a.txt的文件
		if(p1 ==NULL)
		{
			printf("error is %s\n",strerror(errno));
			return -1;
		}

		int buf[1024];
		memset(buf,0,sizeof(buf));
		char val[32]; //定义一个字符串，存放从a.txt读取的一行

		int len = 0;
		while(1)
		{
			memset(val,0,sizeof(val));
			if(fgets(val,sizeof(val),p1) == NULL)//读取一行，如果是文件最后一行，循环退出
			{
				break;
			}
			buf[len] = atoi(val);//读取的字符串转化为整数
			len++;
		}
		fclose(p1);

		FILE *p2 = fopen("b.txt","w");
		if(p2 == NULL)
		{
			printf("error is %s\n",strerror(errno));
			return -1;
		}
		sort(buf,len - 1);
		int i;
		for(i = 0; i < len;i++)//将内容写到文件b.txt
		{
			memset(val,0,sizeof(val));
			sprintf(val,"%d\n",buf[i]);
			fputs(val,p2);
		}
		fclose(p2);
		return 0;
	}
