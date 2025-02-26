#include <stdio.h>

#include "../include/ExploreDirectory.h"

/**
 * @brief Main function for finding word in all files by providing directory.
 * Verifies that the correct amount of arguments have been provided before
 * executing the search.
 *
 * @param argc Argument count, should be three: executable name, directory path
 * and word to search for
 * @param argv List of arguments
 * @return int
 */
int main(int argc, char *argv[]) {
  printf("GOT HERE!\n");
  if (argc != 3) {
    fprintf(stderr,
            "Please provide two arguments: directory path and word to search "
            "for.\n");
    fprintf(stderr, "Usage: %s <folder_path> <word>\n", argv[0]);
    return 1;
  }
  ExploreDirectory(argv[1], argv[2]);

  return 0;
}
