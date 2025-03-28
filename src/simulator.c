#include "../include/simulator.h"

int time = 0;
int recaudatedMoney = 0;

int main() {

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
    int clientsSize = 8;

    Service* services[] = {
        &(Service){NULL, 10, 0.15, 5000, 0, -1},
        &(Service){NULL, 20, 0.25, 7000, 0, -1},
        &(Service){NULL, 30, 0.40, 9000, 0, -1},
        &(Service){NULL, 40, 0.20, 11000, 0, -1}
    };
    int servicesSize = 4;

    int nextArrival = 0;
    while(time++ < TIME_IN_MINUTES) {
        if(nextArrival-- == 0) {
            int indexOfSelectedClient = selectRandomElement(clientsSize, clients, sizeof(Client), offsetof(Client, probability));
            int indexOfSelectedService = selectRandomElement(servicesSize, services, sizeof(Service), offsetof(Service, probability));
            nextArrival = clients[indexOfSelectedClient]->time;
            clientUsesService(&(services[indexOfSelectedService]), clients[indexOfSelectedClient]->time);
        }
        checkLeavingServices(services, servicesSize);
    }
    return 0;
}

int selectRandomElement(int size, void* array, size_t structSize, size_t probabilityOffset) { //tamaño del array, el array de un tipo genérico, tamaño del tipo (struct) del array, la posición en bytes del campo probability dentro de la struct
    float randomNumber = (float)rand() / RAND_MAX;  // Genera número entre 0 y 1
    float cumulativeProbability = 0.0;
    for (int i = 0; i < size; i++) {
        void* element = ((void**)array)[i];  // Obtiene el puntero real a la estructura
        float probability = *(float*)((char*)element + probabilityOffset);    //muy resumidamente, obtenemos el valor del campo probability    
        cumulativeProbability += probability;
        if (randomNumber <= cumulativeProbability) { //mientras más grande sea la probabilidad acumulada, más probable es que se elija el índice
            return i;  
        }
    }
    return size - 1;  // Solo para evitar errores, pero nunca debería llegar acá
}

void checkLeavingServices(Service *services[], size_t sizeServices) {
    for(int i = 0; i < sizeServices; i++) {
        services[i]->currentClientLeavingTime -= 1;
        if(services[i]->currentClientLeavingTime == 0) {
            clientLeavesService(&(services[i]));
        }
    }
}

void clientUsesService(Service **service, int clientTime) { 
    if((*service)->isUsed) {
        pushToQueue(clientTime, &(*service)->queue);
    } else {
        (*service)->isUsed = 1;
        (*service)->currentClientLeavingTime = (*service)->time;
    }
}

int clientLeavesService(Service **service) { 
    if((*service)->isUsed == 0)
        return 0;
    recaudatedMoney += (*service)->cost;
    if(isQueueEmpty((*service)->queue)) {
        (*service)->isUsed = 0;
        (*service)->currentClientLeavingTime = -1;
    } else {
        popFromQueue(&(*service)->queue);
        (*service)->currentClientLeavingTime = (*service)->time;
    }
    return 1;
}
