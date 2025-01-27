#include "fill_date_struct.h"

#include <stdio.h>
#include <time.h>

struct date FillDate(long second) {
  struct tm *date = gmtime(&second);
  struct date new_date = {.day = date->tm_mday,
                          .month = date->tm_mon,
                          .year = date->tm_year + 1900};
  return new_date;
}