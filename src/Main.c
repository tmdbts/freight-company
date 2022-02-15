//
// Created by James Whitever on 24/01/2022.
//

#include "Main.h"
#include <stdio.h>
#include "./helpers/Menus.h"
#include "helpers/terminal.h"

int main() {
    int menuChoice;

    printf("*** Welcome to the freight company software *** \n\n");

    do {
        printMainMenu();

        printf("Select an option from the menu: ");
        scanf("%i", &menuChoice);

        switch (menuChoice) {
            case 1:
                clear();
                FreightsMenu();

                break;

            case 2:
                clear();
                TripsMenu();

                break;

            case 3:
                clear();
                ClientsMenu();

                break;

            case 4:
                clear();
                VehiclesMenu();

                break;

            case 5:
                clear();
                DriversMenu();

                break;

            case 6:
                clear();
                writeAllFiles();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}