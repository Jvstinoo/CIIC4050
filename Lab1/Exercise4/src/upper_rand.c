#include "upper_rand.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief       Takes in two char arrays and sets the second one to be a
 * modified version of the first, where its characters are randomly uppercase
 * and lowercase.
 *
 * @param base  Base array given by user.
 * @param mod   Array to be filled with modified version of base array.
 */
void UpperRand(char* base, char* mod) {
  srand(time(
      NULL));  // ensures different sequence of random number upon execution.
  int value = rand() % 2 == 0;
  int index = 0;
  for (char* i = base; *i != '\0'; i++) {
    if (value)
      mod[index] = toupper(*i);
    else
      mod[index] = *i;
    value = rand() % 2 == 0;
    index++;
  }
}
