#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

sem_t bin_sem;
char work_area[2048];

void *thread_function(void* args)
{
	while(strncmp(work_area, "end", 3) != 0){
		sem_wait(&bin_sem);
		printf("You entered %lu characters\n",strlen(work_area) - 1);
	}
	pthread_exit("Bye");
}

int main()
{
	pthread_t a_thread;
	void* thread_result;
	if(sem_init(&bin_sem, 0, 0) != 0){
		perror("Semaphore initialization failed");
		exit(EXIT_FAILURE);
	}
	if( pthread_create(&a_thread, NULL, thread_function, NULL) !=0 ){
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Enter some text end to stop\n");
	while(strncmp(work_area, "end", 3) != 0){
		fgets(work_area, 2048, stdin);
		sem_post(&bin_sem);
	}
	if( pthread_join(a_thread, &thread_result) != 0 ){
		perror("Thread Joining failed");
                exit(EXIT_FAILURE);
	}
	printf("\nThread joined");
	printf("\nGot %s from thread\n",(char*)thread_result);
	sem_destroy(&bin_sem);
	return 0;
}
