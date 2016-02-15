#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/wait.h>
#include <string.h>
void myprintf(const char *s)
{
	write(STDOUT_FILENO,s,strlen(s));
}


int main(int argc,char *argv[])
{
//
//	printf("pid = %d\n",getpid());
//	printf("ppid = %d\n",getppid());


//	char *login = getlogin();
//	struct passwd *ps = getpwnam(login);
//	printf("user name = %s\n",ps->pw_name);
//	printf("UID=%d\n",ps->pw_uid);
//	printf("home idr=%s\n",ps->pw_dir);

//	system("ls");


//
//	pid_t child = fork();
//	if(child == -1)
//	{
//		printf("call fork error\n");
//		return -1;
//	}
//	if(child == 0)
//	{
//		printf("is child\n");
//	}
//	else
//	{
//		printf("child pid is %d\n", child);
//	}
//


//
//	int fd = open("abc.txt",O_RDONLY);
//	pid_t child = 0;
//	child = fork();
//
//	if(child == 0)
//	{
//		read(fd,buf,sizeof(buf));
//	}
//	if(child > 0)
//	{
//		close(fd);
//	}
//



//	char *args[] = {"/bin/ls","-l",NULL};
//	execve("/bin/ls",args,NULL);

//
//	pid_t pid = fork();
//	if(pid == 0)
//	{
//		printf("ASD");
//	}
//
//	if(pid > 0)
//	{
//		exit(0);
//	}


//	pid_t pid = fork();
//	int status;
//	if(pid == -1)
//	{
//		printf("fork failed\n");
//		return 0;
//	}
//
//	if(pid == 0)
//	{
////		printf("child process start\n");
////		sleep(2);
////		printf("child process end\n");
////		return 100;
//
//		char *args[] ={"/bin/ls","-l",NULL};
//		execve("/bin/ls",args,NULL);
//		return 0;
//
//	}
//	else
//	{
//		printf("parent process start\n");
//		wait(&status);
//		printf("status = %d\n",WEXITSTATUS(status));
//		printf("parent process end\n");
//		return 0;
//	}
//

//
//	close(STDOUT_FILENO);//关闭标准输出
//	int fd = open("/dev/pts/2",O_WRONLY);
//
//	while(1)
//	{
//		sleep(1);
////		printf("%d\n",fd);
//		myprintf("hello world\n");
//	}
//

//	close(STDOUT_FILENO);
//	int fd = open("/dev/pts/2",O_WRONLY);
//	pid_t pid = fork();
//	if(pid == 0)
//	{
//		char *args[] ={"/bin/ls","-l",NULL};
//		execve("/bin/ls",args,NULL);
//
//	}

//	pid_t  pid = fork();
//	int status;
//	if(pid == 0)
//	{
//		printf("child start\n");
//		sleep(5);
//		printf("child end\n");
//	}
//
//
//	if(pid > 0)
//	{
//		printf("parent start\n");
//		wait(&status);
//		printf("child return = %d\n",WEXITSTATUS(status));
//		printf("parent end\n");
//	}
//
//	printf("all end pid=%d\n",getpid());

//
//	pid_t pid = 0;
//	int i = 0;
//	pid = fork();
//
//	int status;
//	if(pid == 0)
//	{
////		while (1)
////		{
////			printf("child \n");
////			sleep(1);
////			printf("ppid = %d",getppid());
////		}
//
//		return 100;
//	}
//
//	if (pid > 0)
//	{
////		exit(0);
//		wait(&status);
//		printf("code = %d\n",WEXITSTATUS(status));
//
//	}

	if (argc > 1)
	{
		int pid = atoi(argv[1]);
//		kill(pid,SIGKILL);
		kill(pid,SIGINT);
	}
	else
	{
		printf("pid=%u\n",getpid());
		sleep(60);
	}

	return EXIT_SUCCESS;
}




























