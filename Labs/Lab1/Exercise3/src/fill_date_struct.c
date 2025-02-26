#include "fill_date_struct.h"

#include <stdio.h>
#include <time.h>

/**
 * @brief Calculates the date based on how many seconds have passed since
 * January 1, 1900. It is used by passing in amount of seconds and return a date
 * type struct with the fields day, month and year populated.
 *
 * @param second        Used to calculate new date.
 * @return struct date  Struct with day, month and year fields.
 */
struct date FillDate(long second) {
  struct tm *date = gmtime(&second);
  struct date new_date = {.day = date->tm_mday,
                          .month = date->tm_mon,
                          .year = date->tm_year + 1900};
  return new_date;
}