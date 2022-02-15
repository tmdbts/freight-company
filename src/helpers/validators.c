//
// Created by James Whitever on 15/02/2022.
//

#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "validators.h"

int dateValidator(char date[], int nullable) {
    int length = strlen(date);

    if (nullable && !strcmp(date, "NULL")) return 1;

    if (length != 10) return 0;

    if (date[2] != '/' && date[5] != '/') return 0;

    for (int i = 0; i < length; ++i) {
        if (i == 2 || i == 5) continue;

        if (!isnumber(date[i])) return 0;
    }

//    TODO: Better validation according to month days and leap years
    if ((date[3] != '0' && date[3] != '1') ||
        (date[3] == '1' && date[4] > '2'))
        return 0;

    if (date[0] == '3' && date[1] > '1') return 0;

    return 1;
}

int getNumberOfDigits(int number) {
    return floor(log10(abs(number))) + 1;
}