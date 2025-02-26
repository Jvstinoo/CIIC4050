#include <stdio.h>

#include "../include/PrintArray.h"

/**
 * @brief       Asks user what type of inputs they would like to enter (int,
 * float or char) and depending on response, the input is received and stored in
 * an array whose type corresponds to the one entered previously. For float and
 * int, the user can give inputs until they enter a negative number. Then, these
 * arrays are printed by function PrintArray.
 *
 * @return int
 */
int main() {
  printf("Enter array type (1 for char, 2 for integer, 3 for float): ");
  int type;
  scanf("%d", &type);

  switch (type) {
    case 1:
      char chars[99999];
      printf("Enter string: ");
      getchar();
      scanf("%[^\n]%*c", chars);
      void *a = chars;
      PrintArray(a, 1);
      break;
    case 2:
      int nums[99999];
      int curr_size = 0;
      int last_num = 0;
      while (last_num >= 0) {
        printf("Enter integer: ");
        scanf("%d", &last_num);
        if (last_num >= 0) {
          nums[curr_size] = last_num;
          curr_size++;
        }
      }
      void *b = nums;
      PrintArray(b, 2);
      break;
    case 3:
      float floats[99999];
      int curr_size_ = 0;
      float last_num_ = 0;
      while (last_num_ >= 0) {
        printf("Enter float: ");
        scanf("%f", &last_num_);
        if (last_num_ >= 0) {
          floats[curr_size_] = last_num_;
          curr_size_++;
        }
      }
      void *bb = floats;
      PrintArray(bb, 3);
      break;
    default:
      break;
  }
  return 0;
}