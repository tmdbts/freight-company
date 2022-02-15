//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_DRIVERS_H
#define FREIGHT_COMPANY_DRIVERS_H

/**
 * The max number of drivers.
 */
static const int MAX_DRIVERS = 100;

/**
 * The driver's properties.
 */
typedef struct driver {
    int id;
    char name[26];
} DRIVER;

/**
 * The drivers.
 */
DRIVER drivers[MAX_DRIVERS];

/**
 * Writes the drivers to a file.
 */
void writeDriversToFile();

/**
 * Reads the properties of a driver for a specific index.
 *
 * @param index index where the properties will be stored
 */
void readDriverInputProperties(int index);

/**
 * Gets the index of a driver with a specific id.
 *
 * @param id the driver's id
 * @param totalDrivers the total number of drivers
 * @return the index where the driver is stored
 */
static int getIndex(int id, int totalDrivers);

/**
 * Gets the last in use index of the drivers array.
 *
 * @param totalDrivers the total number of drivers
 * @return the last in use index
 */
static int getLastUsedIndex(int totalDrivers);

/**
 * Gets the highest id possessed by all the drivers.
 *
 * @param totalDrivers the total number of drivers
 * @return the highest id possessed by all users
 */
static int getMaxId(int totalDrivers);

/**
 * Prints all the drivers.
 */
void printDrivers();

/**
 * Creates a driver.
 */
void createDriver();

/**
 * Reads drivers from a file.
 *
 * @return the number of lines in the file
 */
int readDrivers();

/**
 * Changes the information of an existing driver.
 */
void updateDriver();

/**
 * Deletes an existing driver.
 */
void deleteDriver();

#endif //FREIGHT_COMPANY_DRIVERS_H
