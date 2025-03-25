#ifndef TEST_RANDOM_CHOICE_H
#define TEST_RANDOM_CHOICE_H

#include "simulator.h"

#define EMPTY_QUEUE (Queue*)malloc(sizeof(Queue))

void testRandomChoice();
int selectRandomElement(int size, void* array, size_t elementSize, size_t probabilityOffset);


#endif