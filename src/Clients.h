//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_CLIENTS_H
#define FREIGHT_COMPANY_CLIENTS_H

typedef struct client {
    int id;
    char name[46];
    int nif;
    char address[46];
    char city[46];
    int zipCode;
} CLIENT;

CLIENT clients[100];

void createClient();

void readClients();

void updateClient();

void deleteClient();

#endif //FREIGHT_COMPANY_CLIENTS_H
