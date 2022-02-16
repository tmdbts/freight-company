//
// Created by James Whitever on 24/01/2022.
//

#include <stdio.h>
#include <limits.h>
#include "Trips.h"
#include "helpers/terminal.h"
#include "constants/terminalColors.h"
#include "Vehicles.h"
#include "Drivers.h"
#include "Freight.h"
#include "helpers/validators.h"

void writeTripsToFile() {
    FILE *file;

    file = fopen("../persistence/trips.txt", "w");

    for (int i = 0; i < MAX_TRIPS; ++i) {
        if (trips[i].id == 0) continue;

        fprintf(file, "%i %i %i %10s %i\n",
                trips[i].id,
                trips[i].vehicleId,
                trips[i].driverId,
                trips[i].date,
                trips[i].freightId
        );
    }

    fclose(file);
}

void readTripInputProperties(int index) {
    int canProceed = 0;

//    TODO: If the below properties are 0 return with "No available Freights."
    int numberOfVehicles = readVehicles();
    int numberOfDrivers = readDrivers();
    int numberOfFreights = readFreights();

    clear();
//    getchar();

    do {
        int existsVehicle = 0;

        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the vehicle's id: \n");
        scanf("%i", &trips[index].vehicleId);

        for (int i = 0; i < numberOfVehicles; ++i) {
            if (trips[index].vehicleId == vehicles[i].id) existsVehicle = 1;
        }

        if (existsVehicle) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("There is no vehicle with the specified id. \n");
    } while (canProceed == 0);

    do {
        int existsDiver = 0;

        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the drive's id: \n");
        scanf("%i", &trips[index].driverId);

        for (int i = 0; i < numberOfDrivers; ++i) {
            if (trips[index].driverId == drivers[i].id) existsDiver = 1;
        }

        if (existsDiver) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("There is no driver with the specified id. \n");
    } while (canProceed == 0);

    do {
        printf("%s\n", TERMINAL_COLOR_DEFAULT);
        printf("Insert the date (DD/MM/YYYY): \n");
        scanf("%s", trips[index].date);

        if (dateValidator(trips[index].date, 0)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given has a wrong format. \n");
    } while (canProceed == 0);

    do {
        int existsFreight = 0;

        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's id: \n");
        scanf("%i", &trips[index].freightId);

        for (int i = 0; i < numberOfFreights; ++i) {
            if (trips[index].freightId == freights[i].id) existsFreight = 1;
        }

        if (existsFreight) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given has a wrong format. \n");
    } while (canProceed == 0);
}

static int getIndex(int id, int totalTrips) {
    for (int i = 0; i < totalTrips; ++i) {
        if (trips[i].id == id) return i;
    }

    return -1;
}

static int getLastUsedIndex(int totalTrips) {
    int lastIndex;

    if (totalTrips == 0) return -1;

    for (int i = 0; i < totalTrips; ++i) {
        if (trips[i].id != 0) lastIndex = i;
    }

    return lastIndex;
}

static int getMaxId(int totalTrips) {
    int maxId = INT_MIN;

    if (totalTrips == 0) return 0;

    for (int i = 0; i < totalTrips; ++i) {
        if (trips[i].id > maxId && trips[i].id != 0) maxId = trips[i].id;
    }

    return maxId;
}

void printTrips() {
    int numberOfTrips = readTrips();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+--------------------------------------------------------+ \n");
    printf("|                      List of Trips                     | \n");
    printf("+--------------------------------------------------------+ \n");
    printf("| ID | Vehicle ID | Driver  ID |    Date    | Freight ID | \n");

    if (numberOfTrips == 0) {
        printf("|NONE|    NONE    |    NONE    |    NONE    |    NONE    | \n");
        printf("+--------------------------------------------------------+ \n");

        return;
    }

    for (int i = 0; i < numberOfTrips; ++i) {
        if (trips[i].id == 0) continue;

        printf("| %2i |     %2i     |     %2i     | %10s |     %2i     | \n",
               trips[i].id,
               trips[i].vehicleId,
               trips[i].driverId,
               trips[i].date,
               trips[i].freightId
        );
    }

    printf("+--------------------------------------------------------+ \n");
}

void createTrip() {
    int nextId, nextIndex;

    clear();

    int numberOfTrips = readTrips();

    nextId = getMaxId(numberOfTrips) + 1;
    nextIndex = getLastUsedIndex(numberOfTrips) + 1;

    trips[nextIndex].id = nextId;

    readTripInputProperties(nextIndex);
    writeTripsToFile();
}

int readTrips() {
    FILE *file;
    int fileLine = 0;

    clear();

    file = fopen("../persistence/trips.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file trips.txt. File does not exist. \n", TERMINAL_COLOR_RED);

        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%i %i %i %10s %i",
               &trips[fileLine].id,
               &trips[fileLine].vehicleId,
               &trips[fileLine].driverId,
               trips[fileLine].date,
               &trips[fileLine].freightId
        );

        fileLine++;
    }

    fclose(file);

    return fileLine;
}

void updateTrip() {
    int index, id;

    clear();

    printTrips();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the trip you want to change: ");
    scanf("%i", &id);

    int numberOfTrips = readTrips();
    index = getIndex(id, numberOfTrips);

    if (index == -1) {
        printf("%sThere are no trips with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    readTripInputProperties(index);

    writeTripsToFile();
}

void deleteTrip() {
    int index, id;

    clear();

    printTrips();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the client you want to delete: ");
    scanf("%i", &id);

    int numberOfClients = readTrips();
    index = getIndex(id, numberOfClients);

    if (index == -1) {
        printf("%sThere are no trips with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    trips[index].id = 0;

    writeTripsToFile();
}