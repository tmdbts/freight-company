//
// Created by James Whitever on 24/01/2022.
//

#include "Main.h"
#include <stdio.h>
#include "Vehicles.h"
#include "./helpers/Menus.h"

int main() {
    int menuChoice;

    printf("*** Welcome to the freight company software *** \n\n");

    do {
        printMainMenu();

        printf("Select an option from the menu: ");
        scanf("%i", &menuChoice);

        switch (menuChoice) {
            case 1:
                printFreightsMenu();

                break;

            case 2:
                printTripsMenu();

                break;

            case 3:
                printClientsMenu();

                break;

            case 4:
                VehiclesMenu();

                break;

            case 5:
                printClientsMenu();

                break;

            case 6:
//                writeAllFiles()

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}


//int main() {
//    bootstrapVehicles();
//    printVehicles();
//}