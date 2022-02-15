//
// Created by James Whitever on 15/02/2022.
//

#ifndef FREIGHT_COMPANY_VALIDATORS_H
#define FREIGHT_COMPANY_VALIDATORS_H

/**
 * Validates a date input for the format (DD/MM/YYYY).
 *
 * @param date the date given by the user
 * @return 0 for an invalid date or 1 for a valid date
 */
int dateValidator(char date[], int nullable);

/**
 * Gets the number of digits that a number has.
 *
 * @param number the number to count the digits
 * @return the number of digits of the number
 */
int getNumberOfDigits(int number);

#endif //FREIGHT_COMPANY_VALIDATORS_H
