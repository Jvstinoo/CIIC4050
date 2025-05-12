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

  FILE* fptr = fopen(path_file, "rb");
  if (fptr == NULL) {
    printf("Was unable to open the file.\n");
    exit(0);
  }

  FILE* output_file = fopen("data.csv", "w");

  float row_numbers[columns];

  for (int i = 0; i < rows; i++) {
    fread(row_numbers, sizeof(float), columns, fptr);
    for (int j = 0; j < columns; j++) {
      float new_value = -(row_numbers[j] / 5);
      printf("%f, ", new_value);
      fprintf(output_file, "%f", new_value);
      if (j < columns - 1) {
        fprintf(output_file, ",");
      }
    }
    fprintf(output_file, "\n");
  }
  return 0;
}
