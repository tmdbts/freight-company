//
// Created by James Whitever on 24/01/2022.
//

#include "Clients.h"

typedef struct client {
    int id;
    char name[46];
    int nif;
    char address[46];
    char city[46];
    int zipCode;
} CLIENT;