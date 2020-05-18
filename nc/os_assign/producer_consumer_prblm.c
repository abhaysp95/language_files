/**
    _    ____  ____
   / \  / ___||  _ \   Abhay Shanker Pathak
  / _ \ \___ \| |_) |  abhaysp9955@gmail.com
 / ___ \ ___) |  __/   https://github.com/coolabhays
/_/   \_\____/|_|

Showing the implementation of producer consumer problem */


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define max_items 5 // maximum number of items a produecer can produce or a consumer can cosume
#define buf_size 5 // size of buffer

sem_t empty;
sem_t full;
int get_in = 0, get_out = 0;
int buffer[buf_size];
pthread_mutex_t mutex;

// function for producer part
void *producer(void *pnum) {
	int item;
	for (int i = 0; i < max_items; i++) {
		item = rand();  // produce a random item
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[get_in] = item;
		printf("Producer %d: Inserted item %d at %d\n", *((int *)pnum), buffer[get_in], get_in);
		get_in = (get_in + 1) % buf_size;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

// function for consumer part
void *consumer(void *cnum) {
	for (int i = 0; i < max_items; i++) {
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[get_out];
		printf("Consumer %d: Removed item %d from %d\n", *((int *)cnum), item, get_out);
		get_out = (get_out + 1) % buf_size;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

// main function
int main(int argc, char* argv[]) {
	pthread_t pro[5], con[5];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, buf_size);
	sem_init(&full, 0, 0);

	// used for numbering of producer and consumer
	int arr[5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++) {
		pthread_create(&pro[i], NULL, (void *)producer, (void *)&arr[i]);
	}
	for (int i = 0; i < 5; i++) {
		pthread_create(&con[i], NULL, (void *)consumer, (void *)&arr[i]);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(pro[i], NULL);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(con[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	return 0;
}
