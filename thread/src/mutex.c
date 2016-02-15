/*
 * mutex.c
 *
 *  Created on: Feb 15, 2016
 *      Author: cc
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//初始化一个mutex锁


void *func1(void *arg)
{
//	pthread_mutex_trylock(&mutex);
	pthread_mutex_lock(&mutex);//给mutex加锁，这是一个原子操作，不可能出现两个线程同时执行这个代码
	int *a = (int *)arg;
	printf("thread%d start\n");
	int i;
	for(i = 0; i < 10; ++i)
	{
		printf("thread%d is running\n",*a);
		sleep(1);
	}
	printf("thread%d end\n",*a);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

void *func2(void *arg)
{
	pthread_t thr = *(pthread_t *)arg;
	sleep(2);
	pthread_cancle(thr);
	return NULL;
}


int main(int arg,char *args[])
{
	printf("process start\n");
	pthread_t thr_d1,thr_d2,thr_d3;
	int i[2];
	i[0] = 1;
	i[1] = 2;
	pthread_create(&thr_d1,NULL,func1,&i[0]);
	pthread_create(&thr_d2,NULL,func1,&i[1]);
	pthread_create(&thr_d3,NULL,func2,&thr_d1);
	pthread_join(thr_d1,NULL);
	pthread_join(thr_d2,NULL);
	printf("process end\n");
	return 0;
}
