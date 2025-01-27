#include "cosine_series.h"

#include <math.h>
#include <stdio.h>

/**
 * @brief Calculates the sum of the cosines from init_number to end_number,
 * inclusive.
 *
 * @param init_number Start range for cosine series.
 * @param end_number  End range for cosine series.
 * @return int        Returns 1 if the sum of cosines is greater or equal to 0.
 * In the case it is not, returns -1.
 */
int CosineSeries(int init_number, int end_number) {
  float sum_cosines = 0;
  for (int i = init_number; i <= end_number; i++) {
    sum_cosines += cos(i);
  }
  return sum_cosines >= 0 ? 1 : -1;
}
