/*
3.Write a program to copy a string from one process to another using shared memory.
*/
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>      /* For mode constants */
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
key_t key = ftok("mykey", 1);
int fd;
char shmname[10] = "myshm";
//char buf[100] = "";

	int shared_id = shmget(key, 1024, IPC_CREAT | 0666);

	char *buf = shmat(shared_id, NULL, 0);

	printf("\nEnter a string:");
	scanf("%s", buf);

	shmdt(buf);

return 0;
}
