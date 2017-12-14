#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "consumer.h"

void *consumer_func(void *arg)
{
    struct Consumer * c = (struct Consumer*) arg;
    int i;
    for(i = 0; i<10; i++)
    {
        char buff[512];
        FILE * fp = fopen(c->device, "r");
        fgets(buff, 512, fp);
        printf("Consumer %d reading: %s\n", c->id, buff);
        fclose(fp);
    }
    free(c);
}

struct Consumer * consumer_init(int i, char * d)
{
    struct Consumer *c = (struct Consumer *)malloc(sizeof(struct Consumer));
    c->id = i;
    strcpy(c->device, d);
    return c;
}
