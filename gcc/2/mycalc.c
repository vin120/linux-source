#include <stdio.h>
#include <stdlib.h>


int main(int arg,char *args[])
{
	if(arg < 4)
	{	
		printf("error\n");
		return -1;
	}

	int a = atoi(args[1]);
	char  b = args[2][0];
	int c = atoi(args[3]);

	switch(b)
	{
	case '+':
		printf("%d + %d = %d\n",a,c,a+c);
		break;
	case '-':
		printf("%d - %d = %d\n",a,c,a-c);
		break;
	case '*':
		printf("%d * %d = %d\n",a,c,a*c);
		break;

	case '/':
		if(c == 0)
			return 0;
		printf("%d / %d = %d\n",a,c,a/c);
		break;
	default:
		break;
	}
	
	return 0;

}
