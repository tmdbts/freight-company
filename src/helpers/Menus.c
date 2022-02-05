//
// Created by James Whitever on 24/01/2022.
//

#include "Menus.h"
#include <stdio.h>
#include "../Vehicles.h"
#include "../constants/terminalColors.h"
#include "terminal.h"
#include "../Clients.h"
#include "../Drivers.h"
#include "../Trips.h"

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
//    clear();

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
//    clear();

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
//    clear();

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
    clear();

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
//    clear();

    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+-------------------------------+ \n");
    printf("|             Trips             | \n");
    printf("+-------------------------------+ \n");
    printf("| 1 |              Create trip | \n");
    printf("+-------------------------------+ \n");
    printf("| 2 |  Change trip information | \n");
    printf("+-------------------------------+ \n");
    printf("| 3 |              Delete trip | \n");
    printf("+-------------------------------+ \n");
    printf("| 4 |                List trips | \n");
    printf("+-------------------------------+ \n");
    printf("| 5 |                Save trips | \n");
    printf("+-------------------------------+ \n");
    printf("| 0 |                      Exit | \n");
    printf("+-------------------------------+ \n");
}

void printDriversMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+---------------------------------+ \n");
    printf("|             Drivers             | \n");
    printf("+---------------------------------+ \n");
    printf("| 1 |               Create driver | \n");
    printf("+---------------------------------+ \n");
    printf("| 2 |   Change driver information | \n");
    printf("+---------------------------------+ \n");
    printf("| 3 |               Delete driver | \n");
    printf("+---------------------------------+ \n");
    printf("| 4 |                List drivers | \n");
    printf("+---------------------------------+ \n");
    printf("| 5 |                Save changes | \n");
    printf("+---------------------------------+ \n");
    printf("| 0 |                        Exit | \n");
    printf("+---------------------------------+ \n");
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

void ClientsMenu() {
    int menuChoice;

    do {
        printClientsMenu();

        menuChoice = readMenuOption(5);

        switch (menuChoice) {
            case 1:
                createClient();

                break;

            case 2:
                updateClient();

                break;

            case 3:
                deleteClient();

                break;

            case 4:
                printClients();

                break;

            case 5:
                writeClientsToFile();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}

void FreightsMenu();

void TripsMenu() {
    int menuChoice;

    do {
        printTripsMenu();

        menuChoice = readMenuOption(5);

        switch (menuChoice) {
            case 1:
                createTrip();

                break;

            case 2:
                updateTrip();

                break;

            case 3:
                deleteTrip();

                break;

            case 4:
                printTrips();

                break;

            case 5:
                writeTripsToFile();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}

void DriversMenu() {
    int menuChoice;

    do {
        printDriversMenu();

        menuChoice = readMenuOption(5);

        switch (menuChoice) {
            case 1:
                createDriver();

                break;

            case 2:
                updateDriver();

                break;

            case 3:
                deleteDriver();

                break;

            case 4:
                printDrivers();

                break;

            case 5:
                writeDriversToFile();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}