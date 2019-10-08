#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{

	pid_t pid[5], cpid[5];
	int status = 0;

	for(int i=0; i<5; i++)
	{
		pid[i]=fork();

		if(pid[i] < 0)
		{
			printf("Fork has been failed successfully\n");
			return -1;
		}

		//sleep(5);
		if(pid[i] == 0)
		{
			printf("%d = child %d \n", i, getpid());
			sleep(5);
			//printf("PID of child is: %d and parent %d \n",getpid(),getppid());
			//sleep(5);
			cpid[i] = fork();
			if(cpid[i] == 0)
			{
				sleep(5);
				printf("Parents = %d 's child = %d \n", i, getpid());
			}
			break;
		}
		else
		{
			waitpid(pid[i], &status, 0);
			if (WIFEXITED(status))
			{
				printf("Child has terminated normally\n");
			}
			else if (WIFSIGNALED(status))
			{
				printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
			}
		}
		/*else
		{
			//waitpid(pid, &status, 0);
			sleep(5);
			printf("Parent's own id: %d\n", getpid());
			printf("Parent's child id: %d\n", pid[i]);
			printf("Parent's parent (terminal) id: %d\n", getppid());
			sleep(5);
		}*/
	}
	/*
	for(int i=0;i<5;i++)
	{
		waitpid(pid[i], &status, 0);
		waitpid(cpid[i], &status, 0);
		//printf("%d\n",status);
		if (WIFEXITED(status))
		{
			printf("Child has terminated normally\n");
		}
		else if (WIFSIGNALED(status))
		{
			printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
		}
	}
*/
	return 0;
}
