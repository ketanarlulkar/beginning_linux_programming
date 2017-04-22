#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void* args)
{
	printf("\nIn thread with args = %s",(char*)args);
	sleep(1);
	printf("\nThanks for the CPU time");
	pthread_exit("Bye");
}

int main()
{
	pthread_t a_thread;
	void* thread_result;
	if( pthread_create(&a_thread, NULL, thread_function, NULL) !=0 ){
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("\nThread Created");
	if( pthread_join(a_thread, &thread_result) != 0 ){
		perror("Thread Joining failed");
                exit(EXIT_FAILURE);
	}
	printf("\nThread joined");
	printf("\nGot %s from thread\n",(char*)thread_result);
	return 0;
}
