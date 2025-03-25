#ifndef TEST_RANDOM_CHOICE_H
#define TEST_RANDOM_CHOICE_H

#include <assert.h>
#include "../include/simulator.h"
#include "../include/queue.h"

extern int recaudatedMoney;

void testOneClientUsesService();
void testManyClientsUsingService();
void testOnlyClientLeavesService();
void testOneOfManyClientsLeavesService();
void testCheckLeavingServices();
void testRandomChoice(Client* clients[], int sizeClients);

#endif