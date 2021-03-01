#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int i, w, x, exec;
	char polecenie[35];
	int pidmacierzysty = getpid();
	sprintf(polecenie, "pstree -ph %d", pidmacierzysty);
	for (i = 1; i <= 3; i++)
	{
		switch (fork())
		{
		case -1:
		perror("Fork Error");
		exit(1);
		case 0:
		exec = execl("./program1", "program1", NULL);
		if (exec == -1)
		{
			perror("Execl Error");
			exit(1);
		}
		break;
		default:
		printf("Proces macierzysty\n");
		sleep(3);
		}

	}
	
	if (pidmacierzysty == getpid())
	{
		system(polecenie);
	}
	
	for (int j = 0; j < 3; j++)
	{
		w = wait(&x);
		if (w == -1)
		{
			printf("Wait error\n");
		}
		else
		{
			printf("Kod powrotu potomka %d , o PID rownym %d = %d\n", j, w, x);
		}
	}
return 0;
}

