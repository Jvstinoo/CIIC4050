
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fptr;

  /**
   *  wb: write operation only
   *  wb+: write and read operations
   *  w+b: write and read permission (creates if doesn't exist)
   *  a+b: read and write without truncating, create if doesn't exist
   * 
   */

  fptr = fopen("binary.dat", "w+b");

  // checking if the file is opened successfully
  if (fptr == NULL) {
    printf(
        "The file is not opened. The program will "
        "now exit.");
    exit(0);
  }

  // Writing int
  int number = 3248679;
  fwrite(&number, sizeof(int), 1, fptr);

  // Writing double
  double my_double = 8.3542345677889;
  fwrite(&my_double, sizeof(double), 1, fptr);

  // Writing string
  char* text = "hello bin";
  fwrite(text, sizeof(char), 10, fptr);

  // Resetting file pointer to beginning of file
  rewind(fptr);

  // Reading int
  int x_read;
  fread(&x_read, sizeof(int), 1, fptr);
  printf("The first int is %d\n", x_read);

  // Reading double
  double d_read;
  fread(&d_read, sizeof(double), 1, fptr);
  printf("The first double is %f\n", d_read);

  // Reading string
  char text_read[10];
  fread(&text_read, sizeof(char), 10, fptr);
  printf("The first string is %s\n", text_read);

  fclose(fptr);

  return 0;
}
