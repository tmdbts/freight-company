//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_FREIGHT_H
#define FREIGHT_COMPANY_FREIGHT_H

static const int MAX_FREIGHTS = 100;

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

FREIGHT freights[MAX_FREIGHTS];

void writeFreightsToFile();

void readFreightsInputProperties(int index);

static int getIndex(int id, int totalFreights);

static int getLastUsedIndex(int totalFreights);

static int getMaxId(int totalFreights);

void printFreights();

void createFreight();

int readFreights();

void updateFreight();

void deleteFreight();

#endif //FREIGHT_COMPANY_FREIGHT_H
