//
// Created by James Whitever on 24/01/2022.
//

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "Freight.h"
#include "helpers/terminal.h"
#include "constants/terminalColors.h"
#include "Clients.h"
#include "helpers/validators.h"

void writeFreightsToFile() {
    FILE *file;

    file = fopen("../persistence/freights.txt", "w");

    for (int i = 0; i < MAX_FREIGHTS; ++i) {
        if (freights[i].id == 0) continue;

        fprintf(file, "%i %i %10s %10s %10s %10s %10s %i %i %f %f %-26s %-36s %-26s %-36s %-26s\n",
                freights[i].id,
                freights[i].clientId,
                freights[i].priority,
                freights[i].preferablePickUpDate,
                freights[i].pickUpDate,
                freights[i].preferableDeliveryDate,
                freights[i].deliveryDate,
                freights[i].pickupZipCode,
                freights[i].deliveryZipCode,
                freights[i].weight,
                freights[i].volume,
                freights[i].designation,
                freights[i].pickupAddress,
                freights[i].pickupCity,
                freights[i].deliveryAddress,
                freights[i].deliveryCity
        );
    }

    fclose(file);
}

void readFreightsInputProperties(int index) {
    int canProceed = 0;

    clear();
    printf("%s", TERMINAL_COLOR_DEFAULT);

    int numberOfClients = readClients();

    do {
        int hasClient = 0;

        getchar();
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's client ID: \n");
        scanf("%i", &freights[index].clientId);

        for (int i = 0; i < numberOfClients; ++i) {
            if (clients[i].id == freights[index].clientId) hasClient = 1;
        }

        if (hasClient) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("There is no client with the specified id. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's priority (low/medium/urgent): \n");
        scanf("%s", freights[index].priority);

        int length = strlen(freights[index].priority);

        for (int i = 0; i < length; ++i) {
            freights[index].priority[i] = tolower(freights[index].priority[i]);
        }

        if (!strcmp(freights[index].priority, "low") ||
            !strcmp(freights[index].priority, "medium") ||
            !strcmp(freights[index].priority, "urgent"))
            break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given does not correspond to the available options. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's preferable pick up date (DD/MM/YYYY or NULL): \n");
        scanf("%s", freights[index].preferablePickUpDate);

        if (dateValidator(freights[index].preferablePickUpDate)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given has a wrong format. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's pick up date (DD/MM/YYYY or NULL): \n");
        scanf("%s", freights[index].pickUpDate);

//        TODO: Validation according to the creation date. It cannot be smaller
        if (dateValidator(freights[index].pickUpDate)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given has a wrong format. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's preferable delivery date (DD/MM/YYYY or NULL): \n");
        scanf("%s", freights[index].preferableDeliveryDate);

        if (dateValidator(freights[index].preferableDeliveryDate)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given has a wrong format. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's delivery date (DD/MM/YYYY or NULL): \n");
        scanf("%s", freights[index].deliveryDate);

        if (dateValidator(freights[index].deliveryDate)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given has a wrong format. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's pickup zip code (1234): \n");
        scanf("%i", &freights[index].pickupZipCode);

        if (!isnumber(freights[index].pickupZipCode) &&
            getNumberOfDigits(freights[index].pickupZipCode) == 4 &&
            freights[index].pickupZipCode > 0)
            break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is not a number or it has more or less than 4 digits. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's delivery zip code (1234): \n");
        scanf("%i", &freights[index].deliveryZipCode);

        if (!isnumber(freights[index].deliveryZipCode) &&
            getNumberOfDigits(freights[index].deliveryZipCode) == 4 &&
            freights[index].deliveryZipCode > 0)
            break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is not a number or it has more or less than 4 digits. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's weight: \n");
        scanf("%f", &freights[index].weight);

        if (!isnumber(freights[index].weight)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is not a number. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's volume: \n");
        scanf("%f", &freights[index].volume);

        if (!isnumber(freights[index].volume)) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is not a number. \n");
    } while (canProceed == 0);

    getchar();

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's designation: \n");
        gets(freights[index].designation);

        if (strlen(freights[index].designation) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's pickup address: \n");
        gets(freights[index].pickupAddress);

        if (strlen(freights[index].pickupAddress) <= 36) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 36 characters. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's pickup city: \n");
        gets(freights[index].pickupCity);

        if (strlen(freights[index].pickupCity) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's delivery address: \n");
        gets(freights[index].deliveryAddress);

        if (strlen(freights[index].deliveryAddress) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed == 0);

    do {
        printf("\n%s", TERMINAL_COLOR_DEFAULT);
        printf("Insert the freight's delivery city: \n");
        gets(freights[index].deliveryCity);

        if (strlen(freights[index].deliveryCity) <= 26) break;

        printf("%s", TERMINAL_COLOR_RED);
        printf("The input given is bigger than 26 characters. \n");
    } while (canProceed == 0);
}

static int getIndex(int id, int totalFreights) {
    for (int i = 0; i < totalFreights; ++i) {
        if (freights[i].id == id) return i;
    }

    return -1;
}

static int getLastUsedIndex(int totalFreights) {
    int lastIndex;

    if (totalFreights == 0) return -1;

    for (int i = 0; i < totalFreights; ++i) {
        if (freights[i].id != 0) lastIndex = i;
    }

    return lastIndex;
}

static int getMaxId(int totalFreights) {
    int maxId = INT_MIN;

    if (totalFreights == 0) return 0;

    for (int i = 0; i < totalFreights; ++i) {
        if (freights[i].id > maxId && freights[i].id != 0) maxId = freights[i].id;
    }

    return maxId;
}

void printFreights() {
    int numberOfClients = readFreights();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+ \n");
    printf("|                                                                                                                                                                    List of Freights                                                                                                                                                                    | \n");
    printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+ \n");
    printf("| ID | Client ID |         Designation        |  Priority  | Preferable pick up date | Pick up date | Preferable delivery date | Delivery date |            Pick up address           |        Pick up city        | Pick up zip code |            Deliver address           |        Delivery city        | Delivery zip code |   Weight   |   Volume   | \n");

    if (numberOfClients == 0) {
        printf("|NONE|    NONE   |             NONE           |    NONE    |           NONE          |     NONE     |           NONE           |      NONE     |                 NONE                 |            NONE            |       NONE       |                 NONE                 |             NONE            |        NONE       |    NONE    |    NONE    | \n");
        printf("+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+ \n");

        return;
    }

    for (int i = 0; i < numberOfClients; ++i) {
        printf("| %2i |     %2i    | %26s | %10s |        %10s       |  %10s  |           %10s           |   %10s  | %36s | %26s |       %4i       | %36s | %26s |       %4i       | %f10.2 | %f10.2 | \n",
               freights[i].id,
               freights[i].clientId,
               freights[i].designation,
               freights[i].priority,
               freights[i].preferablePickUpDate,
               freights[i].pickUpDate,
               freights[i].preferableDeliveryDate,
               freights[i].deliveryDate,
               freights[i].pickupAddress,
               freights[i].pickupCity,
               freights[i].pickupZipCode,
               freights[i].deliveryAddress,
               freights[i].deliveryCity,
               freights[i].deliveryZipCode,
               freights[i].weight,
               freights[i].volume
        );
    }

    printf("+-----------------------------------------------------------------------------------------------------------------------------+ \n");
}

void createFreight() {
    int nextId, nextIndex;

    clear();

    int numberOfFreights = readFreights();

    nextId = getMaxId(numberOfFreights) + 1;
    nextIndex = getLastUsedIndex(numberOfFreights) + 1;

    freights[nextIndex].id = nextId;

    readFreightsInputProperties(nextIndex);
//    writeFreightsToFile();
}

int readFreights() {
    FILE *file;
    int fileLine = 0;

    clear();

    file = fopen("../persistence/freights.txt", "r");

    if (file == NULL) {
        printf("\n%sError opening file clients.txt. File does not exist. \n", TERMINAL_COLOR_RED);

        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%i %i %10s %10s %10s %10s %10s %i %i %f %f ",
               &freights[fileLine].id,
               &freights[fileLine].clientId,
               freights[fileLine].priority,
               freights[fileLine].preferablePickUpDate,
               freights[fileLine].pickUpDate,
               freights[fileLine].preferableDeliveryDate,
               freights[fileLine].deliveryDate,
               &freights[fileLine].pickupZipCode,
               &freights[fileLine].deliveryZipCode,
               &freights[fileLine].weight,
               &freights[fileLine].volume
        );

        fgets(freights[fileLine].designation, 26, file);
        fgets(freights[fileLine].pickupAddress, 36, file);
        fgets(freights[fileLine].pickupCity, 26, file);
        fgets(freights[fileLine].deliveryAddress, 36, file);
        fgets(freights[fileLine].deliveryCity, 26, file);

        freights[fileLine].designation[strlen(freights[fileLine].designation)] = '\0';
        freights[fileLine].pickupAddress[strlen(freights[fileLine].pickupAddress)] = '\0';
        freights[fileLine].pickupCity[strlen(freights[fileLine].pickupCity)] = '\0';
        freights[fileLine].deliveryAddress[strlen(freights[fileLine].deliveryAddress)] = '\0';
        freights[fileLine].deliveryCity[strlen(freights[fileLine].deliveryCity)] = '\0';

        fileLine++;
    }

    fclose(file);

    return fileLine;
}

void updateFreight() {
    int index, id;

    clear();

    printFreights();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the freight you want to change: ");
    scanf("%i", &id);

    int numberOfFreights = readFreights();
    index = getIndex(id, numberOfFreights);

    if (index == -1) {
        printf("%sThere are no freights with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    readFreightsInputProperties(index);

    writeFreightsToFile();
}

void deleteFreight() {
    int index, id;

    clear();

    printFreights();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("Insert the id of the freight you want to delete: ");
    scanf("%i", &id);

    int numberOfFreights = readFreights();
    index = getIndex(id, numberOfFreights);

    if (index == -1) {
        printf("%sThere are no freights with the selected id.\n", TERMINAL_COLOR_RED);

        return;
    }

    freights[index].id = 0;

    writeFreightsToFile();
}