#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *f(void *a) {
    int *num = (int *)a;

    while (*num < 10000) {
        pthread_mutex_lock(&mutex);
        (*num)++;
        pthread_mutex_unlock(&mutex);    
		usleep(10);
	}

    return NULL;
}

int main() {
    pthread_t thread;
    int i = 0;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread, NULL, f, &i);

    while (i < 10000) {
        pthread_mutex_lock(&mutex);
        printf("%d\n", i);
        pthread_mutex_unlock(&mutex);
		usleep(10);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}

