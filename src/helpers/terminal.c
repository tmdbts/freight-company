//
// Created by James Whitever on 31/01/2022.
//

#include "terminal.h"
#include <stdlib.h>

void clear() {
#ifdef _WIN32
    system("cls");

    return;
#endif

    system("clear");
}