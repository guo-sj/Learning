#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread(void *vargp);

int main(void)
{
    int id;
    pthread_t tid;

    id = pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, NULL);
    printf("id: %d\n", id);
    exit(0);
}

void *thread(void *vargp)
{
    int i, sum;

    for (sum = i = 0; i < 100; ++i)
        sum += i;
    printf("sum: %d\n", sum);
    return NULL;
}
