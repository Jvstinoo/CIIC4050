#include <stdio.h>

#include "fill_date.h"

/**
 * @brief Asks user to input three numbers of seconds corresponding to time
 * passed since January 1, 1970. These seconds are used as FillDate parameter as
 * well as references to day, month, year variables. The date is calculated and
 * set to the passed variables. Finally, the date is printed in {Month
 * Day, Year} format.
 *
 * @return int
 */
int main() {
  const char *months[] = {"January",   "February", "March",     "April",
                          "May",       "June",     "July",      "August",
                          "September", "October",  "Noviembre", "December"};
  long seconds;
  int day = 0;
  int month = 0;
  int year = 0;
  for (int i = 0; i < 3; i++) {
    printf("Enter seconds: ");
    scanf("%ld", &seconds);
    FillDate(seconds, &day, &month, &year);
    printf("%s %d, %d\n", months[month], day, year);
  }
}