//
// Created by James Whitever on 24/01/2022.
//

#include "Vehicles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants/terminalColors.h"

void writeVehiclesToFile() {
    FILE *file;

    file = fopen("../persistence/vehicles.txt", "w");

    for (int i = 0; i < 100; ++i) {
        if (vehicles[i].id == 0) continue;

        fprintf(file, "%i %25s %25s %8s %f %i %i %f\n",
                vehicles[i].id,
                vehicles[i].manufacturer,
                vehicles[i].model,
                vehicles[i].licensePlate,
                vehicles[i].mileage,
                vehicles[i].maxCargoWeight,
                vehicles[i].maxCargoVolume,
                vehicles[i].consumption
        );
    }

    fclose(file);
}

void bootstrapVehicles() {
    FILE *file;

    file = fopen("../persistence/vehicles.txt", "w");

    if (file == NULL) {
        printf("\n%sError loading file. Exiting.", TERMINAL_COLOR_RED);

        fclose(file);
    }

    vehicles[0].id = 1;
    strcpy(vehicles[0].manufacturer, "Ford");
    strcpy(vehicles[0].model, "Transit");
    strcpy(vehicles[0].licensePlate, "AA-00-BB");
    vehicles[0].mileage = 200000;
    vehicles[0].maxCargoWeight = 200;
    vehicles[0].maxCargoVolume = 40000;
    vehicles[0].consumption = 9.3;

    fprintf(file, "%i %25s %25s %8s %f %i %i %f\n",
            vehicles[0].id,
            vehicles[0].manufacturer,
            vehicles[0].model,
            vehicles[0].licensePlate,
            vehicles[0].mileage,
            vehicles[0].maxCargoWeight,
            vehicles[0].maxCargoVolume,
            vehicles[0].consumption
    );

    fclose(file);
}

void printVehicles() {
    numberOfVehicles = readVehicles();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+-----------------------------------------------------------------------------------------------------+ \n");
    printf("|                                           List of Vehicles                                          | \n");
    printf("+-----------------------------------------------------------------------------------------------------+ \n");
    printf("| ID | Manufacturer |    Model    | License Plate |  Mileage  | Max Weight | Max Volume | Consumption | \n");

    for (int i = 0; i < numberOfVehicles; ++i) {
//        if (selectedVehicle.id == 0) return;

        printf("| %2i | %12s | %11s |   %8s    | %6.1f  |    %4i    |    %5i   |    %3.2f    | \n",
               vehicles[i].id,
               vehicles[i].manufacturer,
               vehicles[i].model,
               vehicles[i].licensePlate,
               vehicles[i].mileage,
               vehicles[i].maxCargoWeight,
               vehicles[i].maxCargoVolume,
               vehicles[i].consumption
        );
    }
}

void createVehicle() {
    int currentId = 0;
    int currentIndex;
    int nextId;
    int nextIndex;

    numberOfVehicles = readVehicles();

    for (int i = 0; i < numberOfVehicles; ++i) {
        if (vehicles[i].id <= currentId) continue;

        currentId = vehicles[0].id;
        currentIndex = i;
    }

    nextId = ++currentId;
    nextIndex = ++currentIndex;

    printf("Insert the manufacturer:\n");
    scanf("%s", vehicles[nextIndex].manufacturer);

    printf("Insert the model:\n");
    scanf("%s", vehicles[nextIndex].model);

    printf("Insert the license plate: (AA-00-BB)\n");
    scanf("%s", vehicles[nextIndex].licensePlate);

    printf("Insert the mileage: (kilometers)\n");
    scanf("%f", &vehicles[nextIndex].mileage);

    printf("Insert the max cargo weight: (kilograms)\n");
    scanf("%i", &vehicles[nextIndex].maxCargoWeight);

    printf("Insert the max cargo volume: (cubic meters)\n");
    scanf("%i", &vehicles[nextIndex].maxCargoVolume);

    printf("Insert the consumption: (liters per kilometers)\n");
    scanf("%f", &vehicles[nextIndex].consumption);
}

int readVehicles() {
    FILE *file;
    int fileLine = 0;

    file = fopen("../persistence/vehicles.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file vehicles.txt. File does not exist.", TERMINAL_COLOR_RED);

        fclose(file);
        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%i %25s %25s %8s %f %i %i %f ",
               &vehicles[fileLine].id,
               vehicles[fileLine].manufacturer,
               vehicles[fileLine].model,
               vehicles[fileLine].licensePlate,
               &vehicles[fileLine].mileage,
               &vehicles[fileLine].maxCargoWeight,
               &vehicles[fileLine].maxCargoVolume,
               &vehicles[fileLine].consumption);

        fileLine++;
    }

    fclose(file);

    return fileLine;
}

void updateVehicle() {}

void deleteVehicle() {}