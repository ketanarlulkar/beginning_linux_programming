#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("\nGot it !!! %d",sig);
//	(void) signal(SIGINT, SIG_DFL);
}

int main()
{
	(void) signal(SIGINT, ouch);
	while(1)
	{
		printf("\nHello");
		sleep(1);
	}
	return 0;
}
