//
// Created by James Whitever on 24/01/2022.
//

#include <stdio.h>
#include <limits.h>
#include "Clients.h"
#include "helpers/terminal.h"
#include "constants/terminalColors.h"
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

void writeClientsToFile() {
    FILE *file;

    file = fopen("../persistence/clients.txt", "w");

    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i].id == 0) continue;

        fprintf(file, "%i %-26s %i %-36s %-26s %i\n",
                clients[i].id,
                clients[i].name,
                clients[i].nif,
                clients[i].address,
                clients[i].city,
                clients[i].zipCode
        );
    }

    fclose(file);
}

void readClientInputProperties(int index) {
    int canProceed = 0;

    clear();
    getchar();

    do {
        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the client's name: \n");
        gets(clients[index].name);

        if (strlen(clients[index].name) <= 26)break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed == 0);

    do {
        int inputLength = 0;
        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the client's nif: \n");
        scanf("%i", &clients[index].nif);

        inputLength = floor(log10(abs(clients[index].nif))) + 1;

        if (!isnumber(clients[index].nif) && inputLength == 9 && clients[index].nif > 0) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is not a number or it has more or less than 9 digits. \n");
    } while (canProceed == 0);

    do {
        getchar();

        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the client's address: \n");
        gets(clients[index].address);

        if (strlen(clients[index].address) <= 36) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 36 characters. \n");
    } while (canProceed == 0);

    do {
        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the client's city: \n");
        gets(clients[index].city);

        if (strlen(clients[index].city) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed == 0);

    do {
        int inputLength = 0;

        printf("%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the client's zip code: \n");
        scanf("%i", &clients[index].zipCode);

        inputLength = floor(log10(abs(clients[index].zipCode))) + 1;

        if (!isnumber(clients[index].zipCode) && inputLength == 4 && clients[index].zipCode > 0) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is not a number or it has more or less than 4 digits. \n");
    } while (canProceed == 0);
}

int getIndex(int id, int totalClients) {
    for (int i = 0; i < totalClients; ++i) {
        if (clients[i].id == id) return i;
    }

    return -1;
}

int getLastUsedIndex(int totalClients) {
    int lastIndex;

    if (totalClients == 0) return -1;

    for (int i = 0; i < totalClients; ++i) {
        if (clients[i].id != 0) lastIndex = i;
    }

    return lastIndex;
}

int getMaxId(int totalClients) {
    int maxId = INT_MIN;

    if (totalClients == 0) return 0;

    for (int i = 0; i < totalClients; ++i) {
        if (clients[i].id > maxId && clients[i].id != 0) maxId = clients[i].id;
    }

    return maxId;
}

void printClients() {
    int numberOfClients = readClients();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+-----------------------------------------------------------------------------------------------------------------------------+ \n");
    printf("|                                                        List of Clients                                                      | \n");
    printf("+-----------------------------------------------------------------------------------------------------------------------------+ \n");
    printf("| ID |            Name            |    Nif    |               Address                |            City            | Zip Code | \n");

    if (numberOfClients == 0) {
        printf("|NONE|            NONE            |    NONE   |                NONE                  |            NONE            |   NONE   |\n");
        printf("+-----------------------------------------------------------------------------------------------------------------------------+ \n");

        return;
    }

    for (int i = 0; i < numberOfClients; ++i) {
        printf("| %2i | %26s | %9i | %36s | %26s |   %4i   | \n",
               clients[i].id,
               clients[i].name,
               clients[i].nif,
               clients[i].address,
               clients[i].city,
               clients[i].zipCode
        );
    }

    printf("+-----------------------------------------------------------------------------------------------------------------------------+ \n");
}

void createClient() {
    int nextId, nextIndex;

    clear();

    int numberOfClients = readClients();

    nextId = getMaxId(numberOfClients) + 1;
    nextIndex = getLastUsedIndex(numberOfClients) + 1;

    clients[nextIndex].id = nextId;

    readClientInputProperties(nextIndex);
    writeClientsToFile();
}

int readClients() {
    FILE *file;
    int fileLine = 0;

    clear();

    file = fopen("../persistence/clients.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file clients.txt. File does not exist. \n", TERMINAL_COLOR_RED);

        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%i ", &clients[fileLine].id);
        fgets(clients[fileLine].name, 26, file);
        fscanf(file, "%i ", &clients[fileLine].nif);
        fgets(clients[fileLine].address, 36, file);
        fgets(clients[fileLine].city, 26, file);
        fscanf(file, "%i ", &clients[fileLine].zipCode);

        clients[fileLine].name[strlen(clients[fileLine].name)] = '\0';
        clients[fileLine].address[strlen(clients[fileLine].address)] = '\0';
        clients[fileLine].city[strlen(clients[fileLine].city)] = '\0';

        fileLine++;
    }

    fclose(file);

    return fileLine;
}

void updateClient() {
    int index, id;

    clear();

    printClients();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the client you want to change: ");
    scanf("%i", &id);

    int numberOfClients = readClients();
    index = getIndex(id, numberOfClients);

    if (index == -1) {
        printf("%sThere are no clients with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    readClientInputProperties(index);

    writeClientsToFile();
}

void deleteClient() {
    int index, id;

    clear();

    printClients();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the client you want to delete: ");
    scanf("%i", &id);

    int numberOfClients = readClients();
    index = getIndex(id, numberOfClients);

    if (index == -1) {
        printf("%sThere are no clients with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    clients[index].id = 0;

    writeClientsToFile();
}