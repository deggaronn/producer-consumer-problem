#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
void *producer();
void *consumer();
sem_t full, empty, mutex;
int main()
{
int i;
printf("enter the value of buffer\t");
scanf("%d",&i);
sem_init(&full,0,0);
sem_init(&empty,0,i);
sem_init(&mutex,0,1);
pthread_t p,c;
pthread_create(&p,NULL,&producer,NULL);
pthread_create(&c,NULL,&consumer,NULL);
pthread_join(p,NULL);
pthread_join(c,NULL);

}
void *producer()
{
	sem_wait(&empty);
	sem_wait(&mutex);
	printf("\n\n\n\nnow the producer is working\n\n\\n\n");
	sleep(5);
	sem_post(&mutex);
	sem_post(&full);
}
void *consumer()
{
	sem_wait(&full);
	sem_wait(&mutex);
	printf("now the consumer is working");
	sem_post(&mutex);
	sem_post(&empty);
}
