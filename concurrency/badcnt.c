#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

volatile long cnt = 0;

void *thread(void *vargp)
{
    long niters = *((long *) vargp);
    for (long i = 0; i < niters; i++)
        cnt++;
    return NULL;
}

int main(int argc, char **argv)
{
    long niters;
    pthread_t tid1, tid2;

    niters = atoi(argv[1]);
    pthread_create(&tid1, NULL, thread, &niters);
    pthread_create(&tid2, NULL, thread, &niters);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    if (cnt != (2 * niters))
        printf("Wrong! cnt=%ld\n", cnt);
    else
        printf("Correct! cnt=%ld\n", cnt);
    exit(0);
}
