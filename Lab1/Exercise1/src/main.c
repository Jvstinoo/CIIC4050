#include <math.h>
#include <stdio.h>

#include "cosine_series.h"

int main() {
  int low, high;
  printf("Enter lower limit: ");
  scanf("%d", &low);
  printf("Enter upper limit: ");
  scanf("%d", &high);
  printf("%d", CosineSeries(low, high));
}