//
// Created by James Whitever on 24/01/2022.
//

#include "Main.h"
#include <stdio.h>
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
                FreightsMenu();

                break;

            case 2:
                TripsMenu();

                break;

            case 3:
                ClientsMenu();

                break;

            case 4:
                VehiclesMenu();

                break;

            case 5:
                DriversMenu();

                break;

            case 6:
//                writeAllFiles()

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}