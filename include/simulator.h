#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "queue.h"

#define EMPTY_QUEUE (Queue*)malloc(sizeof(Queue))
#define TIME_IN_SECONDS 180000 // 5 hours in minutes

typedef struct Ser {
    Queue *queue;
    int time;
    float probability;
    int cost;
    int isUsed; //boolean
    int currentClientLeavingTime; //-1 empty
} Service;

typedef struct C {
    int time;
    float probability;    
} Client;

void checkLeavingServices(Service *services[], size_t sizeServices);
int selectRandomElement(int size, void* array, size_t structSize, size_t probabilityOffset);
void clientUsesService(Service **service, int clientTime);
int clientLeavesService(Service **service);

#endif