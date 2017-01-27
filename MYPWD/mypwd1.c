#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	char buff[1024];
	char* cwd;
	cwd = getcwd(buff, sizeof(buff));
	if (!cwd)
		printf("current directory doesn't exit\n");
	else
		printf("current durectory : %s\n", cwd);
	return 0;
}