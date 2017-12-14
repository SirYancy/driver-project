#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "producer.h"

void *producer_func(void *arg)
{
    struct Producer * p = (struct Producer*) arg;
    int i;
    for (i=0; i<10;i++)
    {
        FILE * fp = fopen(p->device, "w");
        int out = fprintf(fp, "Message from Producer: %d, Iter: %d\n", p->id, i);
        fclose(fp);
    }
    free(p);
}
    

struct Producer * producer_init(int i, char * d)
{
    struct Producer *p = (struct Producer *)malloc(sizeof(struct Producer));
    p->id = i;
    strcpy(p->device, d);
    pthread_t tid;
    p->tid = tid;
    return p;
}

