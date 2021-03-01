#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	int pidmacierzysty = getpid();
	char polecenie[35];
	
	sprintf(polecenie, "pstree -ph %d", pidmacierzysty);
	printf("Proces macierzysty: PID: %d, PPID: %d\n", getpid(), getppid());
	for (int i = 1; i <= 1; i++)
	{
		switch (fork())
		{
		case -1:
			perror("Fork Error");
			exit(1);
		case 0:
			printf("Potomek %d: \n", i);
			printf("UID: %d, GID: %d, PID: %d, PPID: %d\n\n", getuid(), getgid(), getpid(), getppid());
		break;
		default:
		printf("Proces macierzysty\n");
		 }
	 }
	if (pidmacierzysty == getpid())
	system(polecenie);
	sleep(1);
	return 0;
}
