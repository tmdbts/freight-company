//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_VEHICLES_H
#define FREIGHT_COMPANY_VEHICLES_H

static const int MAX_VEHICLES = 100;

typedef struct vehicle {
    int id;
    char manufacturer[27];
    char model[27];
    char licensePlate[9];
    float mileage;
    int maxCargoWeight;
    int maxCargoVolume;
    float consumption;
} VEHICLE;

VEHICLE vehicles[MAX_VEHICLES];

int numberOfVehicles;

void writeVehiclesToFile();

void bootstrapVehicles();

void readVehicleInputProperties(int index);

static int getIndex(int id, int totalDrivers);

static int getLastUsedIndex(int totalDrivers);

static int getMaxId(int totalDrivers);

void printVehicles();

void createVehicle();

int readVehicles();

void updateVehicle();

void deleteVehicle();

//VEHICLE getVehicles(int id);

#endif //FREIGHT_COMPANY_VEHICLES_H
