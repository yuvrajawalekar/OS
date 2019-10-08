#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{  
	pid_t pid;
	printf(" before fork\n");

	pid=fork();

	if(pid <0)
	{
		return -1;
	}
	if( pid==0 )  
	{           
		sleep(10);
		printf(" child 1 %d\n", getpid());
		printf(" child 1 parent %d \n", getppid());

	}
	else
	{     
		sleep(15);
                   int status =0;
		   waitpid(pid,&status,0);
		               printf(" child 1  Killed..\n");
                printf(" only basic parent %d\n", getpid());
                printf(" basic parents parent %d\n",getppid());
		pid = fork();
	               
		if( pid < 0 ) 
		{
			return -1;
		}
              
		if( pid==0 )
                    {
                         sleep(5);
                          printf(" child 2 %d\n",getpid());
			  printf(" child 2 parent %d\n", getppid());
		    }
	      	else
	      	{
	         	sleep(10);	
		          int status =0;
		       waitpid(pid,&status);
	                  dsjakjkasdl printf("child 2........");	       
			printf(" only parent %d\n", getpid());
			printf(" parents parent %d\n",getppid());
		}

       }
return 0;
}












