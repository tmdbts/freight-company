//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_DRIVERS_H
#define FREIGHT_COMPANY_DRIVERS_H

typedef struct driver {
    int id;
    char name[46];
} DRIVER;

DRIVER drivers[100];

void createDriver();

void readDrivers();

void updateDriver();

void deleteDriver();

#endif //FREIGHT_COMPANY_DRIVERS_H
