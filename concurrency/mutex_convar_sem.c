/* mutex locks */
pthread_mutex_t bufLock;

void producer(char *buf1)
{
    char *buf = (char *) buf1;
    for (;;) {
        while (count == MAX_SIZE)
            ;
        pthread_mutex_lock(&bufLock);
        buf[count] = (char) ((int) ('a') + count);
        count++;
        printf("%d ", count);
        pthread_mutex_unlock(&bufLock);
    }
}

void consumer(void *buf1)
{
    char *buf = (char *) buf1;
    for (;;) {
        while (count == 0)
            ;
        pthread_mutex_lock(&bufLock);
        count--;
        printf("%d ", count);
        pthread_mutex_unlock(&bufLock);
    }
}

/* condition variables  */
pthread_mutex_t *lock;
pthread_cond_t *notFull, *notEmpty;

void consumer(char *buf)
{
    for (;;) {
        pthread_mutex_lock(lock);
        while (count == 0)
            pthread_cond_wait(notEmpty, lock);
        useChar(buf[count - 1]);
        count--;
        pthread_cond_signal(notFull);
        pthread_mutex_unlock(lock);
    }
}

void producer(char *buf)
{
    for (;;) {
        pthread_mutex_lock(lock);
        while (count == MAX_SIZE)
            pthread_cond_wait(notFull, lock);
        buf[count] = getChar();
        count++;
        pthread_cond_signal(notEmpty);
        pthread_mutex_unlock(lock);
    }
}

/* semaphores */
sem_t empty, full;
void producer(char *buf)
{
    int in = 0;
    for (;;) {
        sem_wait(&empty);
        buf[in] = getChar();
        in = (in + 1) % MAX_SIZE;
        sem_post(&full);
    }
}

void consumer(char *buf)
{
    int out = 0;
    for (;;) {
        sem_wait(&full);
        useChar(buf[out]);
        out = (out + 1) % MAX_SIZE;
        sem_post(&empty);
    }
}
