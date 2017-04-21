#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ouch(int sig)
{
	printf("\nGot it, It's %d",sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = ouch;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);

	sigaction(SIGINT, &act, 0);

	while(1)
	{
		printf("\nHello");
		sleep(1);
	}

	return 0;
}

