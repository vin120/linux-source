#include <stdio.h>

void test(void)
{
	int *i = NULL;
	*i = 2;
}


int main(int arg,char *args[])
{
	printf("hello worlnd\n");
	test();
	return 0;
}
