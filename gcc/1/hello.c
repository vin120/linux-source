#include <stdio.h>
#include <stdlib.h>
#include "add.h"


int main(int arg, char *args[])
{
	if(arg < 3)
		printf("请输入2个参数");
	else
	{
		int a = atoi(args[1]);
		int b = atoi(args[2]);
		printf("%d 加 %d 等于 %d\n",a,b,add(a,b));
	}
	return 0;

}
