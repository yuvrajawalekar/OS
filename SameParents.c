#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid[5];

	int i;

	for(i=1;i<=5;i++)
	{
		pid[i]=fork();  
		if( pid[i] == 0)
		{
			printf("Child %d with id %d and parent's pid %d \n",i,getpid(), getppid());
			sleep(10);
			exit(0);

		}
	}
	
	for(i=1;i<=5;i++)
	{
		int status=0;
		waitpid(pid[i], &status, 0);
	
		printf("Exited child with id %d status is: %d\n",pid[i],status);

		if (WIFEXITED(status))
		{
			printf("Child has terminated normally\n");
		}
		else
		{
			printf("Child has been killed, status: %d\n", status);
		}

		if (WIFSIGNALED(status))
		{
			printf("Child has been killed due to signal: %d\n", WTERMSIG(status));
		}
	}
	return 0;
}
