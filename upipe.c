#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
       {
           int fd[2];
           pid_t pid;
           char buf[50];
           int stat = 0;
           
           pipe(fd);
           
           pid = fork();
           if (pid < 0) {
           	printf("Fork failed");
           	return -1;
           }

           if (pid == 0) {
	       char ip[100];
               close(fd[0]);
               printf("Enter a String: ");
               scanf("%s", buf);
               write(fd[1], buf, sizeof(buf));
               close(fd[1]);
           
           } else {
               waitpid(pid, &stat, 0);
               
               close(fd[1]);
               read(fd[0], buf, sizeof(buf));
               printf("%s", buf);
               close(fd[0]);
           }
           
           return 0;
       }
