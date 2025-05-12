#include <stdio.h>
#include <stdlib.h>

#include "../include/DecodeBinaryToCSV.h"

/**
 * @brief Takes in three arguments from the command line, and ensures all
 * arguments have been passed. These are decoded and passed into
 * DecodeBinaryToCSV to decode the binary file and write to csv the decoded
 * values.
 *
 * @param argc must be 4
 * @param argv binary executable, file_name, rows, columns
 * @return int
 */
int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf(
        "Must provide three arguments: binary file name, number of rows, "
        "number of columns in image.\n");
    return 0;
  }
  char* file_name = argv[1];
  int rows = atoi(argv[2]);
  int columns = atoi(argv[3]);

  DecodeBinaryToCSV(file_name, rows, columns);

  return 0;
}
