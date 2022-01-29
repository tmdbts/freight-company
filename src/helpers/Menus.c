//
// Created by James Whitever on 24/01/2022.
//

#include "Menus.h"
#include <stdio.h>
#include "../Vehicles.h"
#include "../constants/terminalColors.h"

void printMainMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+--------------------------+ \n");
    printf("|         Main Menu        | \n");
    printf("+--------------------------+ \n");
    printf("| 1 |             Vehicles | \n");
    printf("+--------------------------+ \n");
    printf("| 2 |              Clients | \n");
    printf("+--------------------------+ \n");
    printf("| 3 |             Vehicles | \n");
    printf("+--------------------------+ \n");
    printf("| 4 |                Trips | \n");
    printf("+--------------------------+ \n");
    printf("| 5 |     Save all changes | \n");
    printf("+--------------------------+ \n");
    printf("| 0 |                 Exit | \n");
    printf("+--------------------------+ \n");
}

void printVehiclesMenu() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+----------------------------------+ \n");
    printf("|             Vehicles             | \n");
    printf("+----------------------------------+ \n");
    printf("| 1 |               Create vehicle | \n");
    printf("+----------------------------------+ \n");
    printf("| 2 |   Change vehicle information | \n");
    printf("+----------------------------------+ \n");
    printf("| 3 |               Delete vehicle | \n");
    printf("+----------------------------------+ \n");
    printf("| 4 |                List vehicles | \n");
    printf("+----------------------------------+ \n");
    printf("| 5 |                 Save changes | \n");
    printf("+----------------------------------+ \n");
    printf("| 0 |                         Exit | \n");
    printf("+----------------------------------+ \n");
};

void printListOfVehicles() {
    printf("%s", TERMINAL_COLOR_DEFAULT);
    printf("+-----------------------------------------------------------------------------------------------------+ \n");
    printf("|                                           List of Vehicles                                          | \n");
    printf("+-----------------------------------------------------------------------------------------------------+ \n");
    printf("| ID | Manufacturer |    Model    | License Plate |  Mileage  | Max Weight | Max Volume | Consumption | \n");

    for (int i = 0; i < 100; ++i) {
        VEHICLE selectedVehicle = getVehicles(i);

        if (selectedVehicle.id == 0) return;

        printf("| %2i | %12s | %11s | %13s | %9i |    %4i    |     %3i    |     %2.2f    | \n",
               selectedVehicle.id,
               selectedVehicle.manufacturer,
               selectedVehicle.model,
               selectedVehicle.licensePlate,
               selectedVehicle.mileage,
               selectedVehicle.maxCargoWeight,
               selectedVehicle.maxCargoVolume,
               selectedVehicle.consumption
        );
    }
}

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