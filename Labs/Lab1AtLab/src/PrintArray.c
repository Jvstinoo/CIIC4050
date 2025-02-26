#include "../include/PrintArray.h"

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief        Takes a void pointer array containing char, int or float.
 * Depending on the type inputted by the user, elements in this array will be
 * casted to their respective type (int, float or char) and printed in their
 * corresponding style.
 *
 * @param array  Array containing elements inputted by the user. Can be char,
 * int or float.
 * @param type   Indicates what type of elements are in array.
 */
void PrintArray(void* array, int type) {
  switch (type) {
    case 1:
      char* char_array = (char*)array;
      puts(char_array);
      printf("\n");
      break;
    case 2:
      bool flag = false;
      while (*(int*)array > 0 && array != NULL) {
        if (flag)
          printf(", %d", *(int*)array);
        else {
          printf("%d", *(int*)array);
        }
        flag = true;
        array = array + sizeof(int);
      }
      printf("\n");
      break;
    case 3:
      bool float_flag = false;
      while (*(float*)array > 0 && array != NULL) {
        if (float_flag)
          printf("; %.3f", *(float*)array);
        else {
          printf("%.3f", *(float*)array);
        }
        float_flag = true;
        array = array + sizeof(float);
      }
      printf("\n");
      break;
    default:
      break;
  }
}