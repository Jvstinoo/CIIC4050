#include <math.h>
#include <stdio.h>

#include "cosine_series.h"

/**
 * @brief       Asks user for lower and upper limit int for a cosine series.
 * Calls function CosineSeries with these inputs.
 *
 * @return int  
 */
int main() {
  int low, high;
  printf("Enter lower limit: ");
  scanf("%d", &low);
  printf("Enter upper limit: ");
  scanf("%d", &high);
  printf("%d", CosineSeries(low, high));
  return 0;
}