/*Write a program and do the following :using sigaction API, handle SIGINT, SIGTERM, SIGQUIT,
SIGSTOP,SIGTSTP and SIGKILL. Install dummy handlers for the mentioned signals Using
sigaction() system call API !!! */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>


void handle(int signum)
{
	printf("Signal Received:  %d", signum);
}

int main()
{
	int i=0;

	struct sigaction sig,sig2,sig3,sig4,sig5,sig6;
	
	memset(&sig, 0, sizeof (struct sigaction));
	sig.sa_handler = handle;	
	sigaction(SIGINT, &sig, NULL);				//2
	
	memset(&sig2, 0, sizeof (struct sigaction));
	sig2.sa_handler = handle;	
	sigaction(SIGTERM, &sig2, NULL);			//15
	
	memset(&sig3, 0, sizeof (struct sigaction));
	sig3.sa_handler = handle;	
	sigaction(SIGQUIT, &sig3, NULL);			//3
	
	memset(&sig, 0, sizeof (struct sigaction));		//cannot be handled
	sig4.sa_handler = handle;	
	sigaction(SIGSTOP, &sig4, NULL);			//17,19,23
	
	memset(&sig5, 0, sizeof (struct sigaction));
	sig5.sa_handler = handle;	
	sigaction(SIGTSTP, &sig5, NULL);			//18,20,24
	
	memset(&sig6, 0, sizeof (struct sigaction));		//cannot be handled
	sig6.sa_handler = handle;	
	sigaction(SIGKILL, &sig6, NULL);			//9
	
	while(1)
	{
		printf("%d\n", i++);
		sleep(1);
	}
	
return 0;
}
