#include "upper_rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void UpperRand(char* base, char* mod) {
   srand(time(NULL));
   int value = rand() % 2 == 0;
   int index = 0;
   for (char* i = base; *i != '\0'; i++) {
    if (value)
        mod[index] = toupper(*i);
    value = rand() % 2 == 0;
    index++;
   }
}

