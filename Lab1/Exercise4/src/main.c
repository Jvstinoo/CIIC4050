#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_arrays.h"
#include "upper_rand.h"

/**
 * @brief Asks user to input base char array and then calls UpperRand so that a
 * modified version of this array is created. Both of these arrays are then
 * printed.
 *
 * @return int  
 */
int main() {
  char* baseString;
  size_t baseStringSize = 0;
  printf("Enter base array: ");
  getline(&baseString, &baseStringSize,
          stdin);  // used so that size of input is known

  char* modifiedString = malloc(baseStringSize);

  if (modifiedString == NULL) {
    printf("Was not able to allocate memory\n");
    free(baseString);
    return 0;
  }

  UpperRand(baseString, modifiedString);
  PrintArrays(baseString, modifiedString);

  free(baseString);
  free(modifiedString);

  return 0;
}