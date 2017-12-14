#ifndef _PRODUCER_H_
#define _PRODUCER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct Producer {
    pthread_t tid;
    int id;
    char device[64];
};

void *producer_func(void *arg);

struct Producer * producer_init(int i, char * d);

#endif //_PRODUCER_H_
