//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_FREIGHT_H
#define FREIGHT_COMPANY_FREIGHT_H

typedef struct freight {
    int id;
    int clientId;
    char designation[25];
    char priority[36];
    char preferablePickUpDate[10];
    char pickUpDate[10];
    char preferableDeliveryDate[10];
    char deliveryDate[10];
    char pickupAddress[46];
    char pickupCity[46];
    int pickupZipCode;
    char deliveryAddress[46];
    char deliveryCity[46];
    int deliveryZipCode;
    float weight;
    float volume;
} FREIGHT;

FREIGHT freights[100];

void createFreight();

void readFreights();

void updateFreight();

void deleteFreight();

FREIGHT getFreight(int id);

#endif //FREIGHT_COMPANY_FREIGHT_H
