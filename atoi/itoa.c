#include <stdio.h>

int len(const char *str) // 得到字符串长度，类似strlen函数功能
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return i;
}


void reverse(char *str) //将字符串中字符顺序首尾颠倒
{
	int i_len = len(str);
	char tmp = 0;
	int i = 0;
	for(; i < (i_len / 2);i++)
	{
		tmp = str[i];
		str[i] = str[i_len - 1 - i];
		str[i_len - 1 - i] = tmp;
	}
}

void strneg(char *str) // 将字符串前面加负数符号 '-'
{
	int i_len = len(str);
	int i = i_len - 1;
	for(; i >= 0; i--)
	{
		str[i+1] = str[i];
	}
	str[0] = '-';
}

const char *myitoa(int src) // 将整数src转化为字符串
{
	static char buf[128];
	int i = 0;
	for(; i < sizeof(buf);i++) //将char buf[]数组元素全部初始化为0
	{
		buf[i] = 0;
	}
	int neg ;

	if(src >= 0)
	{
		neg = 1;
	}
	else
	{
		src = 0 - src;
		neg = 0;
	}

	i = 0;

	while(1)
	{
		int n = src % 10;
		buf[i] = n + 0x30;
		i++;
		src /= 10;
		if (src == 0)
			break;
	}

	reverse(buf);
	if(neg == 0)
		strneg(buf);
	return buf;
}

int main(int arg,char *args[])
{
	int i = 10000;
	printf("%s\n",myitoa(i));
	return 0;
}






