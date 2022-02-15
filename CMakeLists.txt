cmake_minimum_required(VERSION 3.21)
project(freight_company C)

set(CMAKE_C_STANDARD 99)

add_executable(freight_company src/Main.c src/Main.h src/Vehicles.c src/Vehicles.h src/Clients.c src/Clients.h src/Freight.c src/Freight.h src/constants/terminalColors.c src/constants/terminalColors.h src/helpers/Menus.c src/helpers/Menus.h src/Trips.c src/Trips.h src/Drivers.c src/Drivers.h src/helpers/terminal.c src/helpers/terminal.h src/helpers/validators.c src/helpers/validators.h)
