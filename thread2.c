#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int run_now = 1;

void *thread_function(void* args)
{
	int print_count2 = 0;
	while(print_count2++ < 20){
                if(run_now == 2){
                       printf("2");
	               run_now = 1;
                }
                else
                        sleep(1);
        }
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
	int print_count1 = 0;

	while(print_count1++ < 20){
		if(run_now == 1){
			printf("1");
			run_now = 2;
		}
		else
			sleep(1);
	}
	if( pthread_join(a_thread, &thread_result) != 0 ){
		perror("Thread Joining failed");
                exit(EXIT_FAILURE);
	}
	printf("\nThread joined");
	printf("\nGot %s from thread\n",(char*)thread_result);
	return 0;
}

