#include "../include/test_simulator.h"
 
//  int main() { //in case of compiling tests, just uncomment the main 

//     Client* clients[] = {
//         &(Client){5, 0.05},
//         &(Client){10, 0.05},
//         &(Client){15, 0.10},
//         &(Client){20, 0.10},
//         &(Client){25, 0.30},
//         &(Client){30, 0.20},
//         &(Client){35, 0.15},
//         &(Client){40, 0.05}
//     };  
//     int clientsSize = 8;

//     Service* services[] = {
//         &(Service){NULL, 10, 0.15, 5000, 0, -1},
//         &(Service){NULL, 20, 0.25, 7000, 0, -1},
//         &(Service){NULL, 30, 0.40, 9000, 0, -1},
//         &(Service){NULL, 40, 0.20, 11000, 0, -1}
//     };
//     int servicesSize = 4;

//     testRandomChoice(clients, clientsSize);
//     testOneClientUsesService();
//     testManyClientsUsingService();
//     testOnlyClientLeavesService();
//     testOneOfManyClientsLeavesService();
//     testCheckLeavingServices();
//  }
 
 void testOneClientUsesService() {
    Service service = {NULL, 10, 0.15, 5000, 0, -1};
    Service* servicePtr = &service;
    
    clientUsesService(&servicePtr, 5);
    
    assert(servicePtr->isUsed == 1);
    assert(servicePtr->currentClientLeavingTime == 5); 

    assert(isQueueEmpty(servicePtr->queue)); 
}
 
void testManyClientsUsingService() {
    Service service = {NULL, 10, 0.15, 5000, 0, -1};
    Service* servicePtr = &service;
    
    clientUsesService(&servicePtr, 5);
    clientUsesService(&servicePtr, 2);

    assert(servicePtr->isUsed == 1);
    assert(!isQueueEmpty(servicePtr->queue));
}

void testOnlyClientLeavesService() {
    Service service = {NULL, 10, 0.15, 5000, 0, -1};
    Service* servicePtr = &service;

    clientUsesService(&servicePtr, 5);

    int result = clientLeavesService(&servicePtr);


    assert(result == 1);

    assert(servicePtr->isUsed == 0);
    assert(servicePtr->currentClientLeavingTime == -1); 
}

void testOneOfManyClientsLeavesService() {
    Service service = {NULL, 10, 0.15, 5000, 0, -1};
    Service* servicePtr = &service;

    clientUsesService(&servicePtr, 5);
    clientUsesService(&servicePtr, 10);

    int result = clientLeavesService(&servicePtr);

    assert(result == 1); 

    assert(servicePtr->isUsed == 1);
    assert(servicePtr->currentClientLeavingTime == 10);
}

void testCheckLeavingServices() {
    Service service1 = {NULL, 10, 0.15, 5000, 1, 2}; 
    Service service2 = {NULL, 20, 0.25, 7000, 1, 9}; 

    Service* services[] = {&service1, &service2};
    size_t servicesSize = 2;

    checkLeavingServices(services, servicesSize);

    assert(services[0]->currentClientLeavingTime == 1); 
    assert(services[1]->currentClientLeavingTime == 8); 

    clientUsesService(&services[0], 2);
    checkLeavingServices(services, servicesSize);

    assert(service1.currentClientLeavingTime == 2);
    assert(isQueueEmpty(services[0]->queue));
    assert(service2.currentClientLeavingTime == 7);
}


 void testRandomChoice(Client* clients[], int sizeClients) {
     int totalTimesOfCalls[] = {0, 0, 0, 0, 0, 0, 0, 0};
     int i = 100000;
     while(i--) {
         int indexOfSelectedClient = selectRandomElement(sizeClients, clients, sizeof(Client*), offsetof(Client, probability));
         totalTimesOfCalls[indexOfSelectedClient] += 1;
     }
     printf("Call number 1; %d\n", totalTimesOfCalls[0]);
     printf("Call number 2; %d\n", totalTimesOfCalls[1]);
     printf("Call number 3; %d\n", totalTimesOfCalls[2]);
     printf("Call number 4; %d\n", totalTimesOfCalls[3]);
     printf("Call number 5; %d\n", totalTimesOfCalls[4]);
     printf("Call number 6; %d\n", totalTimesOfCalls[5]);
     printf("Call number 7; %d\n", totalTimesOfCalls[6]);
     printf("Call number 8; %d\n", totalTimesOfCalls[7]);
 }