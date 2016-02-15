/*
 * shmem.c
 *
 *  Created on: Jan 20, 2016
 *      Author: cc
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc,char *argv[])
{
//	int shmid = shmget(IPC_PRIVATE,1024,0666);
//	if(shmid < 0)
//		printf("error\n");
//	else
//		printf("success\n");


//	char *shmbuf;
//	int shmid = 0;
//	if(argc > 1)
//	{
//		shmid =atoi(argv[1]); // 通过命令行传递共享内存id号
//		shmbuf = shmat(shmid,0,0);
//		sleep(60);
//		shmdt(shmbuf);
//	}


	char *shmbuf;
	int shmid = 0;
	if(argc > 2)
	{
		shmid = atoi(argv[1]);//通过参数得到共享内存ID号

		shmbuf = shmat(shmid,0,0);//附加到该共享内存
		if(atoi(argv[2]) == 1)
		{
			scanf("%s",shmbuf); //write share memory
		}
		if(atoi(argv[2]) == 2)
		{
			printf("%s\n",shmbuf);//read share memory
		}
		shmdt(shmbuf);
	}

	return 0;
}
