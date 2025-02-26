#include "fill_date.h"

#include <stdio.h>
#include <time.h>

/**
 * @brief Calculates the date based on how many seconds have passed since
 * January 1, 1900. It is used by passing in amount of seconds, pointers of day,
 * month and year so that FillDate assigns them.
 *
 * @param second  Used to calculate date.
 * @param day     Filled with new day.
 * @param month   Filled with new month.
 * @param year    Filled with new year.
 */
void FillDate(long second, int *day, int *month, int *year) {
  struct tm *date = gmtime(&second);
  *day = date->tm_mday;
  *month = date->tm_mon;
  *year = date->tm_year + 1900;
}
