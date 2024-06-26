#include <pthread.h>
#include <stdio.h>
// Compile with -pthread
// gcc -o ex1 ex1.c  -lpthread
// ./ex1

// Create a mutex this ready to be locked!
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;  // shared

void *countgold(void *param)
{
    int i;  // local to each thread
    int local = 0;

    // Same thread that locks the mutex must unlock it
    // Critical section is just 'sum += 1'
    // However locking and unlocking a million times
    // has significant overhead in this simple answer

    for (i = 0; i < 10000000; i++) {
        local += 1;
    }

    pthread_mutex_lock(&m);
    sum += local;
    pthread_mutex_unlock(&m);

    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, countgold, NULL);
    pthread_create(&tid2, NULL, countgold, NULL);

    // Wait for both threads to finish:
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("ARRRRG sum is %d\n", sum);
    return 0;
}
