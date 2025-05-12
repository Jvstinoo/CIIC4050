#include "../include/DecodeBinaryToCSV.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CSV_FILENAME "data.csv"

/**
 * @brief Opens binary file file_name and reads it while decoding the
 * float32 values contained in it by applying the formula -(value / 5).
 * These decoded values are then written to a csv file.
 *
 * @param file_name binary file to decode
 * @param rows number of rows in binary file
 * @param columns number of columns in binary file
 */
void DecodeBinaryToCSV(char* file_name, int rows, int columns) {
  FILE* fptr;
  FILE* csvptr;

  float numbers[rows * columns];

  fptr = fopen(file_name, "rb");  // read binary

  if (fptr == NULL) {
    printf("Was unable to open the file. Exiting.\n");
    exit(0);
  }
  fread(&numbers, sizeof(float), rows * columns, fptr);

  csvptr = fopen(CSV_FILENAME, "w");
  if (csvptr == NULL) {
    printf("Error opening csv file. Exiting.\n");
    exit(0);
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      float new_value = -(numbers[i * columns + j] / 5);
      fprintf(csvptr, "%f", new_value);
      if (j < columns - 1) {
        fprintf(csvptr, ",");
      }
    }
    fprintf(csvptr, "\n");
  }
}
