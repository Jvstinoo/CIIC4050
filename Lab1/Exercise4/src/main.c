#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_arrays.h"
#include "upper_rand.h"

int main() {
  char* baseString = NULL;
  size_t baseStringSize = 0;
  printf("Enter base array: ");
  getline(&baseString, &baseStringSize, stdin);

  char modifiedString[baseStringSize];
  strcpy(modifiedString, baseString);
  char* m = modifiedString;

  UpperRand(baseString, m);
  PrintArrays(baseString, m);
  return 0;
}