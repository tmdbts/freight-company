//
// Created by James Whitever on 24/01/2022.
//

#include "Vehicles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants/terminalColors.h"

VEHICLE vehicles[100];

void bootstrapVehicles() {
    FILE *file;

    file = fopen("../persistence/vehicles.txt", "w");

    if (file == NULL) {
        printf("\n%sError loading file. Exiting.", TERMINAL_COLOR_RED);

        fclose(file);
    }

    fprintf(file, "%i %25s %25s %12s %i %i %i %f\n",
            1,
            "Ford",
            "Transit",
            "00 - AB - 01",
            20,
            500,
            5000,
            7.8
    );

    fclose(file);
}

void printVehicles() {
    readVehicles();

    printf("Done!\n\n");

    for (int i = 0; i < 100; ++i) {
        printf("ID: %i Mileage: %f\n", vehicles[i].id, vehicles[i].consumption);
    }
}

void createVehicles() {
    int currentId = 0;
    int nextId;
    readVehicles();

    for (int i = 0; i < 100; ++i) {
        if (vehicles[i].id <= currentId) continue;

        currentId = vehicles[0].id;
    }

    nextId = ++currentId;

//    TODO: implement create method
}

void readVehicles() {
    FILE *file;
    int fileLine = 0;

    file = fopen("../persistence/vehicles.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file vehicles.txt. File does not exist.", TERMINAL_COLOR_RED);

        fclose(file);
        return;
    }

    printf("Reading\n\n");

//    for (int i = 0; i < 100; ++i) {
//        fscanf(file, "%i %25s %25s %12s %i %i %i %f",
//               &vheicles[i].id,
//               vheicles[i].manufacturer,
//               vheicles[i].model,
//               vheicles[i].licensePlate,
//               &vheicles[i].mileage,
//               &vheicles[i].maxCargoWeight,
//               &vheicles[i].maxCargoVolume,
//               &vheicles[i].consumption);
//    }

    while (!feof(file)) {
        printf("%i", fileLine);
        fscanf(file, "%i %25s %25s %12s %i %i %i %f ",
               &vheicles[fileLine].id,
               vheicles[fileLine].manufacturer,
               vheicles[fileLine].model,
               vheicles[fileLine].licensePlate,
               &vheicles[fileLine].mileage,
               &vheicles[fileLine].maxCargoWeight,
               &vheicles[fileLine].maxCargoVolume,
               &vheicles[fileLine].consumption);

        fileLine++;
    }

    printf("%i\n %s", vheicles[0].id, vehicles[0].manufacturer);

    fclose(file);
}

VEHICLE getVehicles(int id) {
    return vehicles[id];
}