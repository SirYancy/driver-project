#ifndef _CONSUMER_H_
#define _CONSUMER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct Consumer{
    int id;
    char device[64];
};

void *consumer_func(void *arg);

struct Consumer * consumer_init(int i, char * d);

#endif //_CONSUMER_H_
