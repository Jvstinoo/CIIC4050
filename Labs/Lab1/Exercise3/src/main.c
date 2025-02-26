#include <stdio.h>

#include "fill_date_struct.h"

/**
 * @brief Asks user to input three numbers of seconds corresponding to time
 * passed since January 1, 1970. These seconds are used as FillDate parameter
 * which calculates date and populate date struct. Fields of struct are finally
 * printed in {Month Day, Year} format.
 *
 * @return int
 */
int main() {
  const char *months[] = {"January",   "February", "March",     "April",
                          "May",       "June",     "July",      "August",
                          "September", "October",  "Noviembre", "December"};
  long seconds;
  for (int i = 0; i < 3; i++) {
    printf("Enter seconds: ");
    scanf("%ld", &seconds);
    struct date filled_date = FillDate(seconds);
    printf("%s %d, %d\n", months[filled_date.month], filled_date.day,
           filled_date.year);
  }
}