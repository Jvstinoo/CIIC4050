#include <stdio.h>

#include "fill_date_struct.h"

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