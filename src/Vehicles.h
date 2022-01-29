//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_VEHICLES_H
#define FREIGHT_COMPANY_VEHICLES_H

//const char fileDirectory[] = "../persistence/vehicles.txt";

typedef struct vehicle {
    int id;
    char manufacturer[25];
    char model[25];
    char licensePlate[12];
    int mileage;
    int maxCargoWeight;
    int maxCargoVolume;
    float consumption;
} VEHICLE;

VEHICLE vheicles[100];

void bootstrapVehicles();

void printVehicles();

void createVehicles();

void readVehicles();

void updateVehicle();

void deleteVehicle();

VEHICLE getVehicles(int id);

#endif //FREIGHT_COMPANY_VEHICLES_H
