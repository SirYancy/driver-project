#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "producer.h"
#include "consumer.h"

int num_of_threads = 10;

int main()
{
    char *file = "/dev/scullBuffer0";

    int i;

    pthread_t producers[num_of_threads];
    pthread_t consumers[num_of_threads];


    for(i = 0; i < num_of_threads; i++)
    {
        struct Producer * p = producer_init(0, file);
        pthread_t tid;
        pthread_create(&tid, NULL, producer_func, (void*)p);
        producers[i] = tid;
    }
    for(i = 0; i < num_of_threads; i++)
    {
        struct Consumer* p = consumer_init(0, file);
        pthread_t tid;
        pthread_create(&tid, NULL, consumer_func, (void*)p);
        consumers[i] = tid;
    }

    for(i = 0; i < num_of_threads; i++)
    {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    return 0;
}
