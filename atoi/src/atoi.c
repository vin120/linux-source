/*
 ============================================================================
 Name        : atoi.c
 Author      : cc
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int len(const char *str)	//得到字符串长度，类似strlen函数功能
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

int char2i(char c)			//将参数c转换为整数
{
	if ((c >= '0') && (c <= '9'))
		return c - 0x30;
	return 0;
}

int power10(int n)			//求10的n次幂
{
	if (n == 0)
		return 1;		//0次幂总是返回1
	int i = 1;
	int val = 10;
	for (; i < n; i++)
	{
		val *= 10;
	}
	return val;
}

int myatoi(const char *str)		//将字符str转换为整数
{
	const char *p = NULL;
	int neg;	//标志位，0代表负数，1代表正数
	if (str[0] == '-')	//str为负整数，置neg标志位为0
	{
		neg = 0;
		p = ++str;	//将字符串str字符串中的'-'去除，从str的第二位开始转化
	}
	else	//否则置neg标志位为1
	{
		neg = 1;
		p = str;
	}

	int i_len = len(p);	//调到字符串长度
	int i_temp = i_len;
	int value = 0;

	int i = 0;
	for (; i < i_len; i++)	//从str[0]开始遍历字符串
	{
		value += (power10(i_temp - 1) * char2i(p[i]));
		i_temp--;
	}

	if (neg == 0)	//str为负数 ，将转化后的字符串前
	{
		return 0 - value;
	}
	else
	{
		return value;
	}
}

int main(void)
{
	const char *s = "100";
	printf("%d\n", myatoi(s));
	return EXIT_SUCCESS;
}
