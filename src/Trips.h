//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_TRIPS_H
#define FREIGHT_COMPANY_TRIPS_H

static const int MAX_TRIPS = 100;

typedef struct trip {
    int id;
    int vehicleId;
    int driverId;
    char date[11];
    int freightId;
} TRIP;

TRIP trips[MAX_TRIPS];

void writeTripsToFile();

void readTripInputProperties(int index);

static int getIndex(int id, int totalDrivers);

static int getLastUsedIndex(int totalDrivers);

static int getMaxId(int totalDrivers);

void printTrips();

void createTrip();

int readTrips();

void updateTrip();

void deleteTrip();

#endif //FREIGHT_COMPANY_TRIPS_H
