#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
int main(int arg,char *args[])
{
	FILE *p = fopen(args[1],"w");
	if(p == NULL)
	{
		printf("error is %s]\n",strerror(errno));
	}
	else
	{
		printf("success\n");
		char buf[100];
		memset(buf,0,sizeof(100));
//		strcpy(buf,"hello world\n");
//		int a = 9;
//		int b = 10;
//		fprintf(p, "a + b = %d\n",a + b);
//		fprintf(p,"%s\n",buf);

//		while(fscanf(p,"%s",buf) != EOF)
//		{
//			printf("%s\n",buf);
//		}

		int i = 0;
		for(; i < 100; i++)
		{
			sprintf(buf,"%d\n",i);
			fputs(buf,p);
		}

		fclose(p);
	}
	return 0;
}
*/
int main(int arg,char *args[])
{
	FILE *p = fopen(args[1],"r");
	if(p == NULL)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{
		printf("success\n");

		char buf[10];
		memset(buf,0,sizeof(buf));
		while(fgets(buf,sizeof(buf),p))
		{
			printf("%s",buf);
		}
		fclose(p);
	}
	return 0;
}
