#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "producer.h"


int main()
{
    char *file = "/dev/scullBuffer0";
    struct Producer * p = producer_init(0, file);
    pthread_t tid;
    pthread_create(&tid, NULL, producer_func, (void*)p);
    pthread_join(tid,NULL);

    return 0;
}
