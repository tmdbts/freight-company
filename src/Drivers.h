//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_DRIVERS_H
#define FREIGHT_COMPANY_DRIVERS_H

static const int MAX_DRIVERS = 100;

typedef struct driver {
    int id;
    char name[26];
} DRIVER;

DRIVER drivers[MAX_DRIVERS];

void writeDriversToFile();

void readDriverInputProperties(int index);

static int getIndex(int id, int totalDrivers);

static int getLastUsedIndex(int totalDrivers);

static int getMaxId(int totalDrivers);

void printDrivers();

void createDriver();

int readDrivers();

void updateDriver();

void deleteDriver();

#endif //FREIGHT_COMPANY_DRIVERS_H
