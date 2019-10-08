#include <pthread.h>
#include <stdio.h>

int a = 1;

void* inc()
{	
	
	int temp = a;
	++a;
	printf("\nPrevious value= %d, New value= %d", temp, a);
	printf("\n");
	
	/* for(int i=0;i<=100;i++)
	{
		int temp = a;
		++a;
		printf("\nPrevious value= %d, New value= %d", temp, a);
		printf("\n");
	}
	*/
	return NULL;
}

int main()
{
	int tid1,tid2;
	pthread_t newThread1,newThread2;
	
	tid1 = pthread_create(&newThread1, NULL, inc, NULL);
	tid2 = pthread_create(&newThread2, NULL, inc, NULL);
	
	pthread_join(newThread1, NULL);
	pthread_join(newThread2, NULL);

return 0;
}


/***************OUTPUT***********************

dac@dac-Veriton-M200-H310:~/Desktop/8393/OSC/day5$ gcc threadAdd.c -lpthread
dac@dac-Veriton-M200-H310:~/Desktop/8393/OSC/day5$ ./a.out

Previous value= 1, New value= 2

Previous value= 2, New value= 3
dac@dac-Veriton-M200-H310:~/Desktop/8393/OSC/day5$ 


*/
