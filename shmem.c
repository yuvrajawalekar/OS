/*
3.Write a program to copy a string from one process to another using shared memory.
*/
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>      /* For mode constants */
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

int fd;

char shmname[10] = "myshm";
char buf[100] = "";

pid_t pid;

pid = fork();

if(pid < 0)
{
	printf("Fork has failed!");
}

if(pid == 0)
{
	fd = shm_open(shmname, O_CREAT | O_RDWR, 0600);

	printf("\nEnter a string:");
	scanf("%s", buf);

	write(fd, buf, sizeof(buf));

	if(shm_unlink(shmname) == 0)
	{
		printf("\nFile Descriptor from child closed successfully!");
	}
	else
	{
		printf("\nSomething went wrong!");
	}
}else
{
	int status = 0;
	waitpid(pid, &status, 0);
	fd = shm_open(shmname,  O_RDONLY, 0200);
	
	printf("\nUser has entered: %s", buf);

	if(shm_unlink(shmname) == 0)
	{
		printf("\nFile Descriptor from parent closed successfully!");
	}
	else
	{
		printf("\nSomething went wrong!");
	}
}

return 0;
}
