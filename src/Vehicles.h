//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_VEHICLES_H
#define FREIGHT_COMPANY_VEHICLES_H

/**
 * The max number of vehicles.
 */
static const int MAX_VEHICLES = 100;

/**
 * The properties of the vehicles.
 */
typedef struct vehicle {
    int id;
    char manufacturer[27];
    char model[27];
    char licensePlate[9];
    float mileage;
    int maxCargoWeight;
    int maxCargoVolume;
    float consumption;
} VEHICLE;

/**
 * The vehicles.
 */
VEHICLE vehicles[MAX_VEHICLES];

/**
 * Writes the vehicles to a file.
 */
void writeVehiclesToFile();

/**
 * Bootstraps the vehicles. Mainly for debug purposes.
 */
void bootstrapVehicles();

/**
 * Reads the properties of a trip for a specific index.
 *
 * @param index index where the properties will be stored
 */
void readVehicleInputProperties(int index);

/**
 * Gets the index of a trip with a specific id.
 *
 * @param id the trip's id
 * @param totalVehicles the total number of trips
 * @return the index where the trip is stored
 */
static int getIndex(int id, int totalVehicles);

/**
 * Gets the last in use index of the vehicles array.
 *
 * @param totalVehicles the total number of vehicles
 * @return the last in use index
 */
static int getLastUsedIndex(int totalVehicles);

/**
 * Gets the highest id possessed by all the vehicles.
 *
 * @param totalVehicles the total number of trips
 * @return the highest id possessed by all vehicles
 */
static int getMaxId(int totalVehicles);

/**
 * Prints all the trips.
 */
void printVehicles();

/**
 * Creates a trip.
 */
void createVehicle();

/**
 * Reads vehicles from a file.
 */
int readVehicles();

/**
 * Changes the information of an existing vehicle.
 */
void updateVehicle();

void deleteVehicle();

//VEHICLE getVehicles(int id);

#endif //FREIGHT_COMPANY_VEHICLES_H
