#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>


int main() 
{ 
    int pid, pid1, pid2, pid3, pid4; 
    int status = 0;
    pid = fork(); 

    if (pid == 0) { 
        sleep(5);
        printf("child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
    }
    else{
    	waitpid(pid, &status, 0);
    	if (WIFEXITED(status))
					{
						printf("Child has terminated normally\n");
					}
					else if (WIFSIGNALED(status))
					{
						printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
					}
        sleep(5);
        pid1 = fork(); 

        if (pid1 == 0) { 
            sleep(5); 
            printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
            //waitpid(getpid(), &status, 0);
        } 
        else {
		waitpid(pid1, &status, 0);
		if (WIFEXITED(status))
					{
						printf("Child has terminated normally\n");
					}
					else if (WIFSIGNALED(status))
					{
						printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
					}
		sleep(5);
            pid2 = fork(); 

            if (pid2 == 0) {
            	sleep(5); 
                printf("child[3] --> pid = %d and ppid = %d\n", getpid(), getppid());
                //waitpid(getpid(), &status, 0);
            } 
            else {
		waitpid(pid2, &status, 0);
		if (WIFEXITED(status))
					{
						printf("Child has terminated normally\n");
					}
					else if (WIFSIGNALED(status))
					{
						printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
					}
                sleep(5);
                pid3 = fork(); 
		    if (pid3 == 0) {
		    	sleep(5); 
		        printf("child[4] --> pid = %d and ppid = %d\n", getpid(), getppid());
		        //waitpid(getpid(), &status, 0);
		    } 
		    else {
		    		waitpid(pid3, &status, 0);
		    		if (WIFEXITED(status))
					{
						printf("Child has terminated normally\n");
					}
					else if (WIFSIGNALED(status))
					{
						printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
					}
				sleep(5);
				pid4 = fork(); 
				    if (pid4 == 0) {
				    	sleep(5); 
					printf("child[5] --> pid = %d and ppid = %d\n", getpid(), getppid()); 
					//waitpid(getpid(), &status, 0);
				    } 
				    else {
				    	waitpid(pid4, &status, 0);
				    	if (WIFEXITED(status))
					{
						printf("Child has terminated normally\n");
					}
					else if (WIFSIGNALED(status))
					{
						printf("Child has been killed due to signal: %d.\n", WTERMSIG(status));
					}
					sleep(3); 
					printf("parent --> pid = %d\n", getpid()); 
				    } 
		    } 
            } 
        } 
    } 
    return 0; 
}

/*******************OUTPUT****************************

dac@dac-Veriton-M200-H310:~/Desktop/8393/OSC/day4$ gcc wait1.c -o wait1
dac@dac-Veriton-M200-H310:~/Desktop/8393/OSC/day4$ ./wait1 
child[1] --> pid = 7676 and ppid = 7675
child[2] --> pid = 7677 and ppid = 7675
child[3] --> pid = 7678 and ppid = 7675
child[4] --> pid = 7680 and ppid = 7675
Child has been killed due to signal: 9.
parent --> pid = 7675
dac@dac-Veriton-M200-H310:~/Desktop/8393/OSC/day4$ 

*/
