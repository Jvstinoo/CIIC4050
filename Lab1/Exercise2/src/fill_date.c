#include "fill_date.h"

#include <stdio.h>
#include <time.h>

void FillDate(long second, int *day, int *month, int *year) {
  struct tm *date = gmtime(&second);
  *day = date->tm_mday;
  *month = date->tm_mon;
  *year = date->tm_year + 1900;
}
