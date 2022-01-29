//
// Created by James Whitever on 24/01/2022.
//

#include "Trips.h"
#include "Freight.h"

typedef struct trip {
    int id;
    int vehicleId;
    int driverId;
    char date[10];
    int freightId[20]; //Define a max constant.
} TRIP;