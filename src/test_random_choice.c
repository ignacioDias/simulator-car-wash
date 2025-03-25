#include "../include/test_random_choice.h"

Client* clients[] = {
    &(Client){5, 0.05},
    &(Client){10, 0.05},
    &(Client){15, 0.10},
    &(Client){20, 0.10},
    &(Client){25, 0.30},
    &(Client){30, 0.20},
    &(Client){35, 0.15},
    &(Client){40, 0.05}
};

int sizeClients = 8;

int main() {
    testRandomChoice();
}

void testRandomChoice() {
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

