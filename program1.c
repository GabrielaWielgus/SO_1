#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	printf("UID: %d, \nGID: %d, \nPID: %d, \nPPID: %d\n", getuid(), getgid(), getpid(), getppid());
	
	exit(0);
}
