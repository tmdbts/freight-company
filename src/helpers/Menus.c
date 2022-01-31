//
// Created by James Whitever on 24/01/2022.
//

#include "Menus.h"
#include <stdio.h>
#include "../Vehicles.h"
#include "../constants/terminalColors.h"

int readMenuOption(int max) {
    int menuChoice;

    printf("%sSelect an option from the menu: ", TERMINAL_COLOR_DEFAULT);
    scanf("%i", &menuChoice);

    if (menuChoice < 0 || menuChoice > max) {
        printf("%sInvalid option. Select an option from 0 to %i.\n", TERMINAL_COLOR_RED, max);

        menuChoice = readMenuOption(max);
    }

    return menuChoice;
}

void printMainMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+--------------------------+ \n");
    printf("|         Main Menu        | \n");
    printf("+--------------------------+ \n");
    printf("| 1 |             Freights | \n");
    printf("+--------------------------+ \n");
    printf("| 2 |                Trips | \n");
    printf("+--------------------------+ \n");
    printf("| 3 |              Clients | \n");
    printf("+--------------------------+ \n");
    printf("| 4 |             Vehicles | \n");
    printf("+--------------------------+ \n");
    printf("| 5 |              Drivers | \n");
    printf("+--------------------------+ \n");
    printf("| 6 |     Save all changes | \n");
    printf("+--------------------------+ \n");
    printf("| 0 |                 Exit | \n");
    printf("+--------------------------+ \n");
}

void printVehiclesMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+----------------------------------+ \n");
    printf("|             Vehicles             | \n");
    printf("+----------------------------------+ \n");
    printf("| 1 |              Create vehicles | \n");
    printf("+----------------------------------+ \n");
    printf("| 2 |  Change vehicles information | \n");
    printf("+----------------------------------+ \n");
    printf("| 3 |              Delete vehicles | \n");
    printf("+----------------------------------+ \n");
    printf("| 4 |                List vehicles | \n");
    printf("+----------------------------------+ \n");
    printf("| 5 |                 Save changes | \n");
    printf("+----------------------------------+ \n");
    printf("| 0 |                         Exit | \n");
    printf("+----------------------------------+ \n");
};

void printClientsMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+---------------------------------+ \n");
    printf("|             Clients             | \n");
    printf("+---------------------------------+ \n");
    printf("| 1 |               Create client | \n");
    printf("+---------------------------------+ \n");
    printf("| 2 |   Change client information | \n");
    printf("+---------------------------------+ \n");
    printf("| 3 |               Delete client | \n");
    printf("+---------------------------------+ \n");
    printf("| 4 |                List clients | \n");
    printf("+---------------------------------+ \n");
    printf("| 5 |                Save changes | \n");
    printf("+---------------------------------+ \n");
    printf("| 0 |                        Exit | \n");
    printf("+---------------------------------+ \n");
}

void printFreightsMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+--------------------------------+ \n");
    printf("|            Freights            | \n");
    printf("+--------------------------------+ \n");
    printf("| 1 |              Create client | \n");
    printf("+--------------------------------+ \n");
    printf("| 2 |  Change client information | \n");
    printf("+--------------------------------+ \n");
    printf("| 3 |              Delete client | \n");
    printf("+--------------------------------+ \n");
    printf("| 4 |               List clients | \n");
    printf("+--------------------------------+ \n");
    printf("| 5 |               Save changes | \n");
    printf("+--------------------------------+ \n");
    printf("| 0 |                       Exit | \n");
    printf("+--------------------------------+ \n");
}

void printTripsMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+-------------------------------+ \n");
    printf("|             Trips             | \n");
    printf("+-------------------------------+ \n");
    printf("| 1 |             Create client | \n");
    printf("+-------------------------------+ \n");
    printf("| 2 | Change client information | \n");
    printf("+-------------------------------+ \n");
    printf("| 3 |             Delete client | \n");
    printf("+-------------------------------+ \n");
    printf("| 4 |              List clients | \n");
    printf("+-------------------------------+ \n");
    printf("| 5 |              Save changes | \n");
    printf("+-------------------------------+ \n");
    printf("| 0 |                      Exit | \n");
    printf("+-------------------------------+ \n");
}

void VehiclesMenu() {
    int menuChoice;

    do {
        printVehiclesMenu();

        menuChoice = readMenuOption(5);

        switch (menuChoice) {
            case 1:
                createVehicle();

                break;

            case 2:
                updateVehicle();

                break;

            case 3:
                deleteVehicle();

                break;

            case 4:
                printVehicles();

                break;

            case 5:
                writeVehiclesToFile();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}

void ClientsMenu();

void FreightsMenu();

void TripsMenu();