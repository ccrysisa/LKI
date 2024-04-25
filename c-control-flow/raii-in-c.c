/* 
 * The conventional wisdom in most C textbooks says that one shouldn't use
 * the "goto" command because it's bad programming practice.
 * 
 * It's mostly true. But there's one exception (pun intended) I've run into.
 * 
 * If you have functions or control flows that allocate resources and a 
 * failure occurs, then goto turns out to be one of the nicest ways to 
 * unwind all resources allocated before the point of failure. 
 * 
 * It's Resource-Allocation-Is-Initialization (RAII) in C, basically.
 */

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include <semaphore.h> 

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/* Generate errors 25% of the time. */
int randBomb(void)
{
    static int seeded = 0;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = 1;
    }

    /* Flip a coin. */
    return (rand() % 5) / 4;
}


static char *shmRegion;
static sem_t st;

int main(int argc, char **argv)
{
    int retVal = 0;
    
    printf("Allocate a memory buffer.\n");
    char *memBuf = (char *) malloc(256 * 1024);
    if (NULL == memBuf)
    {
        fprintf(stderr, "malloc() failed.\n");
        retVal = -1;
        goto cleanup_generic;
    }
    
    /* Fifty-bomb. */
    if (randBomb())
    {
        fprintf(stderr, "Random exception after malloc()!\n");
        retVal = -1;
        goto cleanup_malloc;
    }

    printf("Open a file.\n");
    FILE *fp = fopen("dummy-file.txt", "w");
    if (NULL == fp)
    {
        fprintf(stderr, "fopen() failed.\n");
        retVal = -1;
        goto cleanup_malloc;
    }
    
    if (randBomb())
    {
        fprintf(stderr, "Random exception after fopen()!\n");
        retVal = -1;
        goto cleanup_file;
    }

    printf("Open a socket.\n");
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sock)
    {
        fprintf(stderr, "socket() failed.\n");
        retVal = -1;
        goto cleanup_file;
    }
    
    if (randBomb())
    {
        fprintf(stderr, "Random exception after socket()!\n");
        retVal = -1;
        goto cleanup_socket;
    }

    printf("Create a shared-memory region.\n");
    int shmId = shmget(0x1234ABCD, 256*1024, IPC_CREAT);
    if (-1 == shmId)
    {
        fprintf(stderr, "shmget() failed!\n");
        retVal = -1;
        goto cleanup_socket;
    }
    
    shmRegion = (char *) shmat(shmId, NULL, 0);
    if ((char *) -1 == shmRegion)
    {
        fprintf(stderr, "shmat() failed.\n");
        retVal = -1;
        goto cleanup_socket;
    }

    if (randBomb())
    {
        fprintf(stderr, "Random exception after shmat()!\n");
        retVal = -1;
        goto cleanup_shm;
    }

    printf("Create/grab a semaphore.\n");
    /* semaphore's only available to this process and children. */
    if (-1 == sem_init(&st, 0, 1))
    {
        fprintf(stderr, "sem_init() failed.\n");
        retVal = -1;
        goto cleanup_shm;
    }
    
    if (randBomb())
    {
        fprintf(stderr, "Random exception after sem_init()!\n");
        retVal = -1;
        goto cleanup_semaphore;
    }
    
    printf("--> All Resources Allocated!\n");
    printf("--> Perform some normal operations, sing a song, take a dump.\n");
    
    /* Here's the normal control flow return.
     * It's shared with the cleanup goto labels. */

cleanup_semaphore:
    sem_destroy(&st);
    printf("Semaphore destroyed!\n");
cleanup_shm:
    shmctl(shmId, IPC_RMID, NULL);
    printf("Shared memory region destroyed!\n");
cleanup_socket:
    close(sock);
    printf("Socket closed!\n");
cleanup_file:
    fclose(fp);
    printf("File handle closed!\n");
cleanup_malloc:
    free(memBuf);
    printf("Memory buffer freed!\n");
cleanup_generic:
    printf("retVal: %d\n", retVal);
    return retVal;    
}
