#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void* thread_f1 (void* param){
    pthread_mutex_lock(&lock1);
    printf("New thread (1) ID = %llu\n", pthread_self());
    printf("Thread (1) ended\n");
    pthread_cond_signal(&cond2);
    pthread_exit(NULL);
}

void* thread_f2 (void* param){
    printf("New thread (2) ID = %llu\n", pthread_self());
    printf("Thread (2) ended\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t thr1, thr2, thr3;
    int error;
    if (pthread_create(&thr1, NULL, thread_f1, NULL) != 0)
        printf("Failed to create thread1\n");
    if (pthread_create(&thr2, NULL, thread_f2, NULL) != 0)
        printf("Failed to create thread2\n");
    pthread_cond_signal(&cond1); //pass control to the first thread
    sleep(2);
    return 0;
}