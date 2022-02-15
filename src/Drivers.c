//
// Created by James Whitever on 24/01/2022.
//

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "Drivers.h"
#include "Clients.h"
#include "constants/terminalColors.h"
#include "helpers/terminal.h"

void writeDriversToFile() {
    FILE *file;

    file = fopen("../persistence/drivers.txt", "w");

    for (int i = 0; i < MAX_DRIVERS; ++i) {
        if (drivers[i].id == 0) continue;

        fprintf(file, "%i %26s\n",
                drivers[i].id,
                drivers[i].name
        );
    }

    fclose(file);
}

void readDriverInputProperties(int index) {
    int canProceed = 0;

    printf("%s", TERMINAL_COLOR_DEFAULT);

    getchar();
    do {
        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the driver's name: \n");
        gets(drivers[index].name);

        if (strlen(drivers[index].name) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed);
}

static int getIndex(int id, int totalDrivers) {
    for (int i = 0; i < totalDrivers; ++i) {
        if (drivers[i].id == id) return i;
    }

    return -1;
}

static int getLastUsedIndex(int totalDrivers) {
    int lastIndex;

    if (totalDrivers == 0) return -1;

    for (int i = 0; i < totalDrivers; ++i) {
        if (drivers[i].id != 0) lastIndex = i;
    }

    return lastIndex;
}

static int getMaxId(int totalDrivers) {
    int maxId = INT_MIN;

    if (totalDrivers == 0) return 0;

    for (int i = 0; i < totalDrivers; ++i) {
        if (drivers[i].id > maxId && drivers[i].id != 0) maxId = drivers[i].id;
    }

    return maxId;
}

void printDrivers() {
    int numberOfDrivers = readDrivers();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+---------------------------------+ \n");
    printf("|         List of Clients         | \n");
    printf("+---------------------------------+ \n");
    printf("| ID |            Name            | \n");

    if (numberOfDrivers == 0) {
        printf("|NONE|            NONE            | \n");
        printf("+---------------------------------+ \n");

        return;
    }

    for (int i = 0; i < numberOfDrivers; ++i) {
        if (drivers[i].id == 0) continue;

        printf("| %2i | %26s | \n",
               drivers[i].id,
               drivers[i].name
        );
    }

    printf("+---------------------------------+ \n");
}

void createDriver() {
    int nextId, nextIndex;

    clear();

    int numberOfDrivers = readDrivers();

    nextId = getMaxId(numberOfDrivers) + 1;
    nextIndex = getLastUsedIndex(numberOfDrivers) + 1;

    drivers[nextIndex].id = nextId;

    readDriverInputProperties(nextIndex);
    writeDriversToFile();
}

int readDrivers() {
    FILE *file;
    int fileLine = 0;

    clear();

    file = fopen("../persistence/drivers.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file drivers.txt. File does not exist. \n", TERMINAL_COLOR_RED);

        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%i ", &drivers[fileLine].id);
        fgets(drivers[fileLine].name, 26, file);

        drivers[fileLine].name[strlen(drivers[fileLine].name)] = '\0';

        fileLine++;
    }

    fclose(file);

    return fileLine;
}

void updateDriver() {
    int index, id;

    clear();

    printDrivers();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the driver you want to change: ");
    scanf("%i", &id);

    int numberOfDrivers = readDrivers();
    index = getIndex(id, numberOfDrivers);

    if (index == -1) {
        printf("%sThere are no drivers with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    readDriverInputProperties(index);

    writeDriversToFile();
}

void deleteDriver() {
    int index, id;

    clear();

    printDrivers();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the client you want to delete: ");
    scanf("%i", &id);

    int numberOfDrivers = readDrivers();
    index = getIndex(id, numberOfDrivers);

    if (index == -1) {
        printf("%sThere are no drivers with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    drivers[index].id = 0;

    writeDriversToFile();
}