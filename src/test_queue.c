#include "../include/test_queue.h"

int isQueueEmpty(Queue *queue);
int popFromQueue(Queue **queue);
void pushToQueue(int id, Queue **queue);
void printQueue(Queue *queue);


int main() {
    Queue *queue;
    
    CHECK_QUEUE_EMPTY(queue);
    printQueue(queue);
    printf("Tried to pop: %d\n", popFromQueue(&queue));
    CHECK_QUEUE_EMPTY(queue);
    printQueue(queue);
    printf("push one elment: 1\n");
    pushToQueue(1, &queue);
    CHECK_QUEUE_EMPTY(queue);
    printQueue(queue);
    printf("push one elment: 2\n");
    pushToQueue(2, &queue);
    pushToQueue(3, &queue);
    printQueue(queue);
    printf("Tried to pop: %d\n", popFromQueue(&queue));
    printf("Tried to pop: %d\n", popFromQueue(&queue));
    CHECK_QUEUE_EMPTY(queue);
    printQueue(queue);

}