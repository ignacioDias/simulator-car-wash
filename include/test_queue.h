#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#include "queue.h"
#include <stdlib.h>

#define CHECK_QUEUE_EMPTY(queue) \
    if (isQueueEmpty(queue)) { \
        printf("The queue is empty\n"); \
    } else { \
        printf("The queue is not empty\n"); \
    }


int isQueueEmpty(Queue *queue);
int popFromQueue(Queue **queue);
void pushToQueue(int id, Queue **queue);
void printQueue(Queue *queue);


#endif