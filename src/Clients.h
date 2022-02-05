//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_CLIENTS_H
#define FREIGHT_COMPANY_CLIENTS_H

static const int MAX_CLIENTS = 100;

typedef struct client {
    int id;
    char name[27];
    int nif;
    char address[37];
    char city[27];
    int zipCode;
} CLIENT;

CLIENT clients[MAX_CLIENTS];

void writeClientsToFile();

void readClientInputProperties(int index);

static int getIndex(int id, int totalDrivers);

static int getLastUsedIndex(int totalDrivers);

static int getMaxId(int totalDrivers);

void printClients();

void createClient();

int readClients();

void updateClient();

void deleteClient();

#endif //FREIGHT_COMPANY_CLIENTS_H
