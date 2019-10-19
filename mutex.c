#include <pthread.h>
#include <stdio.h>

int a = 0;
pthread_mutex_t mutex;
int val = 0;

void* inc()
{	

	pthread_mutex_lock(&mutex);

	//int temp = a;
	//++a;
	//printf("\nPrevious value= %d, New value= %d", temp, a);
	//printf("\n");
	
	for(int i=0;i<50;i++)
	{
		int temp = a;
		++a;
		printf("\n1.Previous value= %d, New value= %d", temp, a);
		printf("\n");
	}
	
	
	pthread_mutex_unlock(&mutex);

	return NULL;
}

void* inc2()
{	

	pthread_mutex_lock(&mutex);

	//int temp = a;
	//++a;
	//printf("\nPrevious value= %d, New value= %d", temp, a);
	//printf("\n");
	
	for(int i=0;i<50;i++)
	{
		int temp = a;
		++a;
		printf("\n2.Previous value= %d, New value= %d", temp, a);
		printf("\n");
	}
	
	
	pthread_mutex_unlock(&mutex);

	return NULL;
}

int main()
{

	pthread_mutex_init(&mutex,NULL);

	int tid1,tid2;
	int val = 0;
	pthread_t newThread1,newThread2;
	
	//sleep(1);
	tid1 = pthread_create(&newThread1, NULL, inc, NULL);
	
	//sleep(5);
	tid2 = pthread_create(&newThread2, NULL, inc2, NULL);
	
	pthread_join(newThread1, NULL);
	pthread_join(newThread2, NULL);

	pthread_mutex_destroy(&mutex);


return 0;
}
