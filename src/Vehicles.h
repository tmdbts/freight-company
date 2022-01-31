//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_VEHICLES_H
#define FREIGHT_COMPANY_VEHICLES_H

//const char fileDirectory[] = "../persistence/vehicles.txt";

typedef struct vehicle {
    int id;
    char manufacturer[26];
    char model[26];
    char licensePlate[9];
    float mileage;
    int maxCargoWeight;
    int maxCargoVolume;
    float consumption;
} VEHICLE;

VEHICLE vehicles[100];

int numberOfVehicles;

void writeVehiclesToFile();

void bootstrapVehicles();

void printVehicles();

void createVehicle();

int readVehicles();

void updateVehicle();

void deleteVehicle();

//VEHICLE getVehicles(int id);

#endif //FREIGHT_COMPANY_VEHICLES_H
