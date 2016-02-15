#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

void *recvsocket(void *argc) //接收client端socket数据的线程
{
	int st = *(int *) argc;
	char s[1024];

	while (1)
	{
		memset(s, 0, sizeof(s));
		int rc = recv(st, s, sizeof(s), 0);
		if (rc <= 0)
			break;
		printf("%s\n", s);
	}
	return NULL;
}

void *sendsocket(void *argc) //向client端socket发送数据的线程
{
	int st = *(int *) argc;
	char s[1024];
//	char *p = malloc(1048576);

	while (1)
	{
		memset(s, 0, sizeof(s));
		read(STDIN_FILENO, s, sizeof(s));
		int rc = send(st, s, strlen(s), 0);
		printf("rc = %d\n", rc);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		return -1;
	}

	int port = atoi(argv[2]);
	int st = socket(AF_INET, SOCK_STREAM, 0);	//初始化socket
	if (st == -1)
	{
		printf("create socket error: %s\n",strerror(errno));
	}
	struct sockaddr_in addr;	//定义一个IP地址的结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;	//设置结构地址类型为TCP/IP地址
	addr.sin_port = htons(port);//指定一个端口号：8080 ，htons:将short类型从host字节类型到net字节类型转换
	addr.sin_addr.s_addr = inet_addr(argv[1]);	//将字符串类型的IP地址转换成int，赋给addr结构成员

	//调用connect连接到结构addr指定的IP地址和端口
	if (connect(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)
	{
		printf("connect failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	pthread_t thrd1, thrd2;
	pthread_create(&thrd1, NULL, recvsocket, &st);
	pthread_create(&thrd2, NULL, sendsocket, &st);
	pthread_join(thrd1, NULL);
//	pthread_join(thrd2,NULL);
	close(st); //关闭socket
	return EXIT_SUCCESS;
}
