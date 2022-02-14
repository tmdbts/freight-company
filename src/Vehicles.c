//
// Created by James Whitever on 24/01/2022.
//

#include "Vehicles.h"
#include <stdio.h>
#include <string.h>
#include "constants/terminalColors.h"
#include <ctype.h>
#include <limits.h>
#include "helpers/terminal.h"

void writeVehiclesToFile() {
    FILE *file;

    file = fopen("../persistence/vehicles.txt", "w");

    for (int i = 0; i < MAX_VEHICLES; ++i) {
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

    fprintf(file, "%i %26s %26s %8s %f %i %i %f\n",
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

void readVehicleInputProperties(int index) {
    int canProceed = 0;

    clear();

    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the manufacturer:\n");
        scanf("%s", vehicles[index].manufacturer);

        if (strlen(vehicles[index].manufacturer) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is too long. Insert a shorter input. \n");
    } while (canProceed == 0);

    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the model:\n");
        scanf("%s", vehicles[index].model);

        if (strlen(vehicles[index].model) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is too long. Insert a shorter input. \n");
    } while (canProceed == 0);


    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the license plate: (AA-00-BB)\n");
        scanf("%s", vehicles[index].licensePlate);

        if (strlen(vehicles[index].licensePlate) == 8
            && vehicles[index].licensePlate[2] == '-'
            && vehicles[index].licensePlate[5] == '-')
            break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("Wrong format please use the specified format. \n");
    } while (canProceed == 0);

    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the mileage: (kilometers)\n");
        scanf("%f", &vehicles[index].mileage);

        if (isnumber(vehicles[index].mileage)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given either is not a number. \n");
    } while (canProceed == 0);

    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the max cargo weight: (kilograms)\n");
        scanf("%i", &vehicles[index].maxCargoWeight);

        if (isnumber(vehicles[index].maxCargoWeight)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given either is not a number. \n");
    } while (canProceed == 0);

    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the max cargo volume: (cubic meters)\n");
        scanf("%i", &vehicles[index].maxCargoVolume);

        if (isnumber(vehicles[index].maxCargoVolume)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given either is not a number. \n");
    } while (canProceed == 0);


    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the consumption: (liters per kilometers)\n");
        scanf("%f", &vehicles[index].consumption);

        if (isnumber(vehicles[index].consumption)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given either is not a number. \n");
    } while (canProceed == 0);

}

int getIndex(int id, int totalClients) {
    for (int i = 0; i < totalClients; ++i) {
        if (vehicles[i].id == id) return i;
    }

    return -1;
}

int getLastUsedIndex(int totalVehicles) {
    int lastIndex;

    if (totalVehicles == 0) return -1;

    for (int i = 0; i < totalVehicles; ++i) {
        if (vehicles[i].id != 0) lastIndex = i;
    }

    return lastIndex;
}

int getMaxId(int totalClients) {
    int maxId = INT_MIN;

    if (totalClients == 0) return 0;

    for (int i = 0; i < totalClients; ++i) {
        if (vehicles[i].id > maxId && vehicles[i].id != 0) maxId = vehicles[i].id;
    }

    return maxId;
}

void printVehicles() {
    numberOfVehicles = readVehicles();

    clear();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+------------------------------------------------------------------------------------------------------------------------------------+ \n");
    printf("|                                                          List of Vehicles                                                          | \n");
    printf("+------------------------------------------------------------------------------------------------------------------------------------+ \n");
    printf("| ID |        Manufacturer        |            Model           | License Plate |   Mileage   | Max Weight | Max Volume | Consumption | \n");

    if (numberOfVehicles == 0) {
        printf("|NONE|            NONE            |            NONE            |     NONE      |     NONE    |    NONE    |    NONE    |     NONE    | \n");
        printf("+------------------------------------------------------------------------------------------------------------------------------------+ \n");

        return;
    }


    for (int i = 0; i < numberOfVehicles; ++i) {
        printf("| %2i | %26s | %26s |   %8s    | %11.2f  |    %4i    |    %5i   |    %5.2f    | \n",
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

    printf("+------------------------------------------------------------------------------------------------------------------------------------+ \n");
}

void createVehicle() {
    int nextId;
    int nextIndex;

    clear();

    numberOfVehicles = readVehicles();

    nextId = getMaxId(numberOfVehicles) + 1;
    nextIndex = getLastUsedIndex(numberOfVehicles) + 1;

    vehicles[nextIndex].id = nextId;

    readVehicleInputProperties(nextIndex);
    writeVehiclesToFile();
}

int readVehicles() {
    FILE *file;
    int fileLine = 0;

    file = fopen("../persistence/vehicles.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file vehicles.txt. File does not exist. \n", TERMINAL_COLOR_RED);

        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%i %26s %26s %8s %f %i %i %f ",
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

void updateVehicle() {
    int index, id;

    clear();

    printVehicles();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the vehicle you want to change: ");
    scanf("%i", &id);

    numberOfVehicles = readVehicles();
    index = getIndex(id, numberOfVehicles);

    readVehicleInputProperties(index);

    writeVehiclesToFile();
}

void deleteVehicle() {
    int index, id;

    clear();

    printVehicles();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the vehicle you want to delete.");
    scanf("%i", &id);

    numberOfVehicles = readVehicles();
    index = getIndex(id, numberOfVehicles);

    vehicles[index].id = 0;

    writeVehiclesToFile();
}