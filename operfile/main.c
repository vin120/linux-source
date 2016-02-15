#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//struct abc{
//	char name[5];
//	int i ;
//};

/**
 * fread
 */
/*
int main(int arg,char *args[])
{
	FILE *p = fopen(args[1],"r+");
//	FILE *p = fopen(s,"r+");
	if( p == NULL)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{
		printf("success\n");
		char buf[100];
		size_t rc = 0;
//		memset(buf,0,sizeof(buf));
		while(1)
		{
			size_t tmp = fread(buf,1,sizeof(buf),p);
			rc += tmp ;
			if(tmp == 0)
				break;
		}
//		fread(a,sizeof(struct abc),3,p);
		printf("rc = %d\n",rc);
		fclose(p);
	}
	return 0;
}
*/



/**
 * fwrite
 */

struct person
{
	int id;
	char name[20];
	int age;
	int sex;
	int tel[20];

};

/*
int main(int arg,char *args[])
{
	FILE *p = fopen(args[1],"a");
	if(p == NULL)
	{
		printf("error is %s\n",strerror(errno));
	}
	else
	{
		printf("success\n");
//		char buf[100];
//		memset(buf,0,sizeof(buf));
//		strcpy(buf,"hello world\n");

		struct person man[10];
		memset(&man,0,sizeof(man));

		man[0].id = 0;
		strcpy(man[0].name,"小罗");
		man[0].age = 50;
		man[0].sex = 1;
		strcpy(man[0].tel,"991");

		man[1].id = 1;
		strcpy(man[1].name,"大罗");
		man[1].age = 20;
		man[1].sex = 2;
		strcpy(man[1].tel,"9911");

		fwrite(&man,sizeof(struct person),2,p);
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

		struct person man;
		memset(&man,0,sizeof(man));

		while(fread(&man,sizeof(struct person),1,p))
		{
			printf("id=%d\n",man.id);
			printf("name=%d\n",man.name);
			printf("age=%d\n",man.age);
			printf("tel=%d\n",man.tel);
			printf("sex=%d\n",man.sex);
		}
		fclose(p);
	}
	return 0;

}





