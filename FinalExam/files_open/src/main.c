// C Program to illustrate file opening
#include <stdio.h>
#include <stdlib.h>

int main() {
  // file pointer variable to store the value returned by
  // fopen
  FILE* fptr;

  // opening the file in read mode
  fptr = fopen("crawls.txt", "w+");

  // checking if the file is opened successfully
  if (fptr == NULL) {
    printf(
        "The file is not opened. The program will "
        "now exit.");
    exit(0);
  }

  printf("fptr: %ld\n", ftell(fptr));

  if (ftell(fptr) > 0) {
    rewind(fptr);
    printf("fptr: %ld\n", ftell(fptr));
  }

  fseek(fptr, 0, SEEK_END);
  printf("fptr: %ld\n", ftell(fptr));

  return 0;
}
