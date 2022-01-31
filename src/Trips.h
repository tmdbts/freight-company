//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_TRIPS_H
#define FREIGHT_COMPANY_TRIPS_H

typedef struct trip {
    int id;
    int vehicleId;
    int driverId;
    char date[10];
    int freightId[20];
} TRIP;

TRIP trips[100];

void createTrip();

void readTrips();

void updateTrip();

void deleteTrip();

TRIP getTrip(int id);

#endif //FREIGHT_COMPANY_TRIPS_H
