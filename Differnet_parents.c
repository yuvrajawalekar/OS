#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid[5], t;
	int i;
	for(i=1;i<=5;i++)
	{
		pid[i]=fork();
		if( pid[i] == 0)
		{
			printf("Child %d with id %d and parent's pid %d \n",i,getpid(), getppid());
			sleep(5);
			t=fork();
			break;
			

		}
	}
	if(t==0)
	{
		printf("Child's child with id %d and parent's pid %d \n",getpid(), getppid());
		
		
	}
	else if (pid[i]==0)
	{
		int status=0;
		kill(t,9);
		
		waitpid(t, &status, 0);

		if (WIFEXITED(status))
		{
			
			printf("Child  with pid == %d has terminated normally \n",t);
		}
		else
		{	
			printf("Child with pid == %d  has been killed, status: %d\n", t, status);
		}

		if (WIFSIGNALED(status))
		{
			printf("Child with pid == %d  has been killed due to signal: %d\n", t, WTERMSIG(status));
		}
	}
	
	for(int j=1;j<=5;j++)
	{
		if(pid[j]>0 && pid[i]!=0 )
		{
		int status=0;
	
		waitpid(pid[j], &status, 0);
		
		printf("Exited child with id %d status is: %d\n",pid[j],status);
		
		
		if (WIFEXITED(status))
		{
			printf("Child  with pid == %d has terminated normally \n",pid[j]);
			
		}
		else
		{	printf("Child with pid == %d  has been killed, status: %d\n", pid[j],status);
			
		}

		if (WIFSIGNALED(status))
		{
			printf("Child with pid == %d  has been killed due to signal: %d\n",pid[j],WTERMSIG(status));
		}
		}
	}
	return 0;
}
