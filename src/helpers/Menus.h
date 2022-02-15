//
// Created by James Whitever on 24/01/2022.
//

#ifndef FREIGHT_COMPANY_MENUS_H
#define FREIGHT_COMPANY_MENUS_H

/**
 * Reads the menu option from the user.
 *
 * @param max The max number of options
 * @return the chosen option
 */
int readMenuOption(int max);

/**
 * Prints the main menu.
 */
void printMainMenu();

/**
 * Prints the vehicles menu.
 */
void printVehiclesMenu();

/**
 * Prints the clients menu.
 */
void printClientsMenu();

/**
 * Prints the freights menu.
 */
void printFreightsMenu();

/**
 * Prints the trips menu.
 */
void printTripsMenu();

/**
 * Prints the drivers menu.
 */
void printDriversMenu();

/**
 * Writes all files.
 */
void writeAllFiles();

/**
 * Handles the vehicles menu.
 */
void VehiclesMenu();

/**
 * Handles the clients menu.
 */
void ClientsMenu();

/**
 * Handles the freights menu.
 */
void FreightsMenu();

/**
 * Handles the trips menu.
 */
void TripsMenu();

/**
 * Handles the drivers menu.
 */
void DriversMenu();

#endif //FREIGHT_COMPANY_MENUS_H
