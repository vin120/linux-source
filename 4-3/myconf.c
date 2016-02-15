#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *TrimStrR(char *SrcStr) //去掉字符串右边空格
{
	if(SrcStr == NULL)
		return NULL;
	int iLen = strlen(SrcStr);
	int i;
	for (i = (iLen - 1);i >= 0; i--)
	{
		if(SrcStr[i] == ' ')
			SrcStr[i] = 0;
		else
			break;
	}
	return SrcStr;
}

char *TrimStrL(char *SrcStr) // 去掉字符串左边的空格
{
	if(SrcStr == NULL)
		return NULL;
	if(SrcStr[0] != ' ')
		return SrcStr;
	int iLen = strlen(SrcStr);
	if(iLen == 0)
		return SrcStr;
	char *sTmp = (char *)malloc(iLen + 1);
	memset(sTmp, 0, iLen + 1);
	memcpy(sTmp, SrcStr, iLen);
	int i;
	for (i = 0; i < iLen; i++)
	{
		if (SrcStr[i] != ' ')
		{
			strcpy(sTmp, SrcStr + i);
			break;
		}
	}
	strcpy(SrcStr, sTmp);
	free(sTmp);
	return SrcStr;
}


void ParseValueStr(char *DestStr,char *SrcStr) //解析带等号的字符串并去掉字符串尾部空格
{
	int iLen = strlen (SrcStr);
	if(iLen == 0)
		return;

	if((SrcStr[iLen - 1] == '\n') || (SrcStr[iLen - 1] =='\r')) //为了兼容windows格式文本文件
		SrcStr[iLen - 1] ='\0';

	if(iLen > 1)
	{
		if((SrcStr[iLen - 2]== '\n') || (SrcStr[iLen - 2] == 'r'))
			SrcStr[iLen - 2] = '\0';
	}
	TrimStrR(SrcStr); // 去除尾部空格
	int i;
	for(i = 0;i < iLen; i++)
	{
		if((*SrcStr) == '=')
		{
			strcpy(DestStr,++SrcStr);
			break;
		}
		++SrcStr;
	}
	TrimStrL(DestStr);//去掉首部空格
}

int max(const int *buf,const int bufsize)
{
	int tmp = buf[0];
	int i = 0;
	for(; i < bufsize; i++)
	{
		if (tmp <= buf[i])
			tmp = buf[i];
	}
	return tmp;
}

int min(const int *buf, const int bufsize)
{
	int tmp = buf[0];
	int i = 0;
	for(; i < bufsize; i++)
	{
		if(tmp >= buf[i])
			tmp = buf[i];
	}
	return tmp;
}


float avg(const int *buf,const int bufsize)
{
	float sum = 0;
	int i = 0;
	for(; i < bufsize; i++)
	{
		sum += buf[i];
	}
	return sum / bufsize;
}


int main(int arg,char *args[])
{
	const char *filename = "c.txt";
	FILE *f = fopen(filename,"r");
	if(f == NULL)
	{
		printf("open %s failed %s\n",filename,strerror(errno));
		return -1;
	}

	char sValue[100];
	char buf[100];
	int iValue[1024];
	memset(iValue,0,sizeof(iValue));
	int i = 0;
	while(!(feof(f)))//循环遍历文件中每一行
	{
		memset(sValue, 0, sizeof(sValue));
		memset(buf, 0, sizeof(buf));
		fgets(sValue, sizeof(sValue),f);//从c.txt文件中读取一行
		ParseValueStr(buf, sValue);//解析带等号的字符串并去掉字符串尾部空格
		iValue[i] = atoi(buf);
		i++;//累加器，记载c.txt文件中总行数
	}
	fclose(f);
	printf("最大值为%d\n",max(iValue,i));
	printf("最小值为%d\n",min(iValue,i));
	printf("平均值为%f\n",avg(iValue,i));

	return 0;
}
