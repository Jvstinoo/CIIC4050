#include "cosine_series.h"

#include <math.h>
#include <stdio.h>

int CosineSeries(int init_number, int end_number) {
  float sum_cosines = 0;
  for (int i = init_number; i <= end_number; i++) {
    sum_cosines += cos(i);
  }
  return sum_cosines >= 0 ? 1 : -1;
}
