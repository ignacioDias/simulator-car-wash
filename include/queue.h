#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Q {
    int id;
    struct Q* next;
} Queue;


int isQueueEmpty(Queue *queue);
int popFromQueue(Queue **queue);
void pushToQueue(int id, Queue **queue);
void printQueue(Queue *queue);

#endif