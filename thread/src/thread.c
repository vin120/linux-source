/*
 ============================================================================
 Name        : thread.c
 Author      : cc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>



void test()
{
	pthread_exit(NULL);
}


void *func1(void *arg)
{
	int *p = (int *)arg;
	int i = *p;
	free(p);

	printf("pthread is start%d\n",i);
	int a ;
	for (a = 0; a < i; ++a)
	{
		printf("pthread hehe%d\n",a);
		sleep(1);
	}
	printf("pthread is end%d\n",i);
	return NULL;
}


void *func2(void *arg)
{
	printf("phread start\n");
	while(1)
	{
		printf("pthread living\n");
		sleep(1);
	}
	printf("pthread end\n");
	return NULL;
}

void *func3(void *arg)
{
	sleep(5);
	pthread_t thr;
	thr = *(pthread_t *)arg;
	pthread_cancle(thr);
	return NULL;
}


//void *func2(void *arg)
//{
//	printf("pthread start\n");
//	while(1)
//	{
//		printf("pthread2 hehe\n");
//		sleep(1);
//	}
//
//	printf("pthread2 end\n");
//	return NULL;
//}


int main(void) {
//	pthread_t thrd1,thrd2;
//	int *i1 = malloc(sizeof(int));
//	int *i2 = malloc(sizeof(int));
//	*i1 = 3;
//	*i2 = 10;
//
//	if(pthread_create(&thrd1,NULL,func1,i1) != 0)
//	{
//		printf("error is %s\n",strerror(errno));
//	}
//	if(pthread_create(&thrd2,NULL,func1,i2) != 0)
//	{
//		printf("error is %s\n",strerror(errno));
//	}
//
//	pthread_join(thrd1,NULL); //主线程挂起，等待thrd1退出
//	pthread_join(thrd2,NULL);
//	printf("main end\n");

//	while(1)
//	{
//		sleep(1);
//	}



//	pthread_t thrd1;
//
//	if(pthread_create (&thrd1,NULL,func1,NULL) != 0)
//	{
//		printf("error is %s\n",strerror(errno));
//	}
//	pthread_detach(thrd1);



//	pthread_t thrd1,thrd2;
//	if(pthread_create(&thrd1,NULL,func2,NULL) != 0)
//	{
//		printf("error is %s\n",strerror(errno));
//	}
//
//	if(pthread_create(&thrd2,NULL,func3,&thrd1) != 0)
//	{
//		printf("error is %s\n",strerror(errno));
//	}
//
//	pthread_join(thrd1, NULL);
//	pthread_join(thrd2, NULL);


	pthread_t thrd1,thrd2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);//设置线程参数为可分离
	if(pthread_create(&thrd1,&attr,func2,NULL) != 0)
	{
		printf("error is %s\n",strerror(errno));
	}

	if(pthread_create(&thrd2,NULL,func3,&thrd1) != 0)
	{
		printf("error is %s\n",strerror(errno));
	}
	pthread_attr_destroy(&attr);
	pthread_join(thrd1,NULL);





	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
