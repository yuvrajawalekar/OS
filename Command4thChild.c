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
			sleep(5);
			
	                //execlp("gedit", "gedit",NULL, NULL);
			if(i==1)
			{
			printf("Gedit process from child with pid == %d\n", getpid());
			execlp("gedit", "gedit",NULL, NULL);
			}
			if(i==2)
			{
			 printf("Firefox process from child with pid == %d\n", getpid());
			 execlp("firefox", "firefox",NULL, NULL);
			}
			if(i==3)
			{
			printf("gcc process from child with pid == %d\n", getpid());
			 execlp("gcc", "gcc", "-v", NULL);
			}
			exit(0);

		}
	}
	
	for(i=1;i<=5;i++)
	{
		int status=0;
		waitpid(pid[i], &status, 0);

		printf("Exited status of child with pid %d with status %d \n", pid[i], status);
		
		if(WIFEXITED(status))
		printf("Child has terminated normally.\n");

		else
		printf("Child has been killed with status %d\n", status);

		if(WIFSIGNALED(status))
		printf("Child has been killed due to signal: %d\n", WTERMSIG(status));

		
	}
	return 0;
}
