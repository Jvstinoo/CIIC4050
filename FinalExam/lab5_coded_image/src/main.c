#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("You must provide path file.\n");
    exit(0);
  }
  char* path_file = argv[1];
  int rows = atoi(argv[2]);
  int columns = atoi(argv[3]);

  FILE* fptr = fopen(path_file, "wb+");
  FILE* output_file = fopen("data.csv", "wb+");

  float row_numbers[columns];

  for (int i = 0; i < rows; i++) {
    fread(&row_numbers, columns * sizeof(float), columns, fptr);
    for (int j = 0; j < columns; j++) {
      printf("NUM = %f", row_numbers[j]);
      fprintf(output_file, "%f", -(row_numbers[j] / 5));
      if (j < columns - 1) {
        fprintf(output_file, ",");
      }
    }
    fprintf(output_file, "\n");
  }
  return 0;
}
