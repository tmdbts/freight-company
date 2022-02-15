//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_TRIPS_H
#define FREIGHT_COMPANY_TRIPS_H

/**
 * The max number of trips.
 */
static const int MAX_TRIPS = 100;

/**
 * The trip's properties.
 */
typedef struct trip {
    int id;
    int vehicleId;
    int driverId;
    char date[11];
    int freightId;
} TRIP;

/**
 * The trips.
 */
TRIP trips[MAX_TRIPS];

/**
 * Writes all the trips to a file.
 */
void writeTripsToFile();

/**
 * Reads the properties of a trip for a specific index.
 *
 * @param index index where the properties will be stored
 */
void readTripInputProperties(int index);

/**
 * Gets the index of a trip with a specific id.
 *
 * @param id the trip's id
 * @param totalTrips the total number of clients
 * @return the index where the client is stored
 */
static int getIndex(int id, int totalTrips);

/**
 * Gets the last in use index of the trips array.
 *
 * @param totalTrips the total number of trips
 * @return the last in use index
 */
static int getLastUsedIndex(int totalTrips);

/**
 * Gets the highest id possessed by all the trips.
 *
 * @param totalTrips the total number of trips
 * @return the highest id possessed by all trips
 */
static int getMaxId(int totalTrips);

/**
 * Prints all the trips.
 */
void printTrips();

/**
 * Creates a trip.
 */
void createTrip();

/**
 * Reads trips from a file.
 *
 * @return the number of lines in the file
 */
int readTrips();

/**
 * Changes the information of an existing trip.
 */
void updateTrip();

/**
 * Deletes an existing trip.
 */
void deleteTrip();

#endif //FREIGHT_COMPANY_TRIPS_H
