#include "../include/queue.h"

int isQueueEmpty(Queue *queue) {
    return !queue;
}

int popFromQueue(Queue **queue) {
    if(!(*queue)) 
        return -1;
    int id = (*queue)->id;
    Queue *aux = *queue;
    *queue = aux->next;
    free(aux);
    return id;
}

void pushToQueue(int id, Queue **queue) {
    Queue* newClient = (Queue*)malloc(sizeof(Queue));
    newClient->id = id;
    newClient->next = NULL;
    if (!(*queue)) {
        *queue = newClient;
        return;
    }
    Queue *aux = *queue;
    while (aux->next)
        aux = aux->next;
    if(!aux->next)
        aux->next = (Queue*)malloc(sizeof(Queue));
    aux->next = newClient;
}

void printQueue(Queue *queue) {
    Queue *aux = queue;
    printf("<- ");
    while(aux) {
        printf("Id: %d ", aux->id);
        aux = aux->next;
    }
    printf("<-\n");
}

