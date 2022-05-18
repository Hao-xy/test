#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	printf("USER1!=%s\n",getenv("USER"));
	setenv("USER","hehe",1);
	printf("USER2!=%s\n",getenv("USER"));
	putenv("AGE=20");
	printf("AGE!=%s\n",getenv("AGE"));
}