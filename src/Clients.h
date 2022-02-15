//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_CLIENTS_H
#define FREIGHT_COMPANY_CLIENTS_H

/**
 * The max number of clients.
 */
static const int MAX_CLIENTS = 100;

/**
 * The client's properties.
 */
typedef struct client {
    int id;
    char name[27];
    int nif;
    char address[37];
    char city[27];
    int zipCode;
} CLIENT;

/**
 * The clients.
 */
CLIENT clients[MAX_CLIENTS];

/**
 * Writes the clients to a file.
 */
void writeClientsToFile();

/**
 * Reads the properties of a client for a specific index.
 *
 * @param index index where the properties will be stored
 */
void readClientInputProperties(int index);

/**
 * Gets the index of a client with a specific id.
 *
 * @param id the client's id
 * @param totalClients the total number of clients
 * @return the index where the client is stored
 */
static int getIndex(int id, int totalClients);

/**
 * Gets the last in use index of the clients array.
 *
 * @param totalClients the total number of clients
 * @return the last in use index
 */
static int getLastUsedIndex(int totalClients);

/**
 * Gets the highest id possessed by all the clients.
 *
 * @param totalClients the total number of clients
 * @return the highest id possessed by all clients
 */
static int getMaxId(int totalClients);

/**
 * Prints all the clients.
 */
void printClients();

/**
 * Creates a client.
 */
void createClient();

/**
 * Reads clients from a file.
 *
 * @return the number of lines in the read file
 */
int readClients();

/**
 * Changes the information of an existing client.
 */
void updateClient();

/**
 * Deletes an existing client.
 */
void deleteClient();

#endif //FREIGHT_COMPANY_CLIENTS_H
