//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_FREIGHT_H
#define FREIGHT_COMPANY_FREIGHT_H

/**
 * The max number of freights.
 */
static const int MAX_FREIGHTS = 100;

/**
 * The freight's properties.
 */
typedef struct freight {
    int id;
    int clientId;
    char designation[27];
    char priority[11];
    char preferablePickUpDate[11];
    char pickUpDate[11];
    char preferableDeliveryDate[11];
    char deliveryDate[11];
    char pickupAddress[37];
    char pickupCity[27];
    int pickupZipCode;
    char deliveryAddress[37];
    char deliveryCity[27];
    int deliveryZipCode;
    float weight;
    float volume;
} FREIGHT;

/**
 * The freights.
 */
FREIGHT freights[MAX_FREIGHTS];

/**
 * Writes the freights to a file.
 */
void writeFreightsToFile();

/**
 * Reads the properties of a freight for a specific index.
 *
 * @param index index where the properties will be stored
 */
void readFreightsInputProperties(int index);

/**
 * Gets the index of a freight with a specific id.
 *
 * @param id the client's id
 * @param totalFreights the total number of freights
 * @return the index where the freight is stored
 */
static int getIndex(int id, int totalFreights);

/**
 * Gets the last in use index of the freights array.
 *
 * @param totalFreights the total number of freights
 * @return the last in use index
 */
static int getLastUsedIndex(int totalFreights);

/**
 * Gets the highest id possessed by all the freights.
 *
 * @param totalFreights the total number of freights
 * @return the highest id possessed by all freights
 */
static int getMaxId(int totalFreights);

/**
 * Prints all the freights.
 */
void printFreights();

/**
 * Creates a freight.
 */
void createFreight();

/**
 * Reads freights from a file.
 *
 * @return the number of lines in the file.
 */
int readFreights();

/**
 * Changes the information of an existing freight.
 */
void updateFreight();

/**
 * Deletes an existing freight.
 */
void deleteFreight();

#endif //FREIGHT_COMPANY_FREIGHT_H
