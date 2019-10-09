#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>


void handler(int sig_no)
{
	printf("We are handling: %d\n", sig_no);
}

int main()
{
	int i=0;
	struct sigaction sig_act,sig_act1,sig_act2,sig_act3,sig_act4;

	memset(&sig_act, 0, sizeof (struct sigaction));

	memset(&sig_act1, 0, sizeof (struct sigaction));
	memset(&sig_act2, 0, sizeof (struct sigaction));
	memset(&sig_act3, 0, sizeof (struct sigaction));
	memset(&sig_act4, 0, sizeof (struct sigaction));
	sig_act.sa_handler = handler;
	sig_act1.sa_handler = handler;
	sig_act2.sa_handler = handler;
	sig_act3.sa_handler = handler;
	sig_act4.sa_handler = handler;


	//sig_act.sa_mask = 3; Will do it little later
	sigaction(SIGINT, &sig_act, NULL);
	sigaction(SIGQUIT, &sig_act1, NULL);
	sigaction(SIGTERM, &sig_act2, NULL);
	sigaction(SIGSTOP, &sig_act3, NULL);
	sigaction(SIGKILL, &sig_act4, NULL);

	while(1)
	{
		printf("%d\n", i++);
		sleep(1);
	}
	return 0;
}
