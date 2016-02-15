/*
 * test1.c
 *
 *  Created on: Feb 14, 2016
 *      Author: cc
 */

#include <stdio.h>
#include <string.h>
#include "upper.h"

int main(int arg,char *args[])
{
	const char *s = "abc100def";
	char buf[100];
	memset(buf,0,sizeof(buf));
	upper(s,buf);
	printf("%s\n",buf);
	return 0;
}
