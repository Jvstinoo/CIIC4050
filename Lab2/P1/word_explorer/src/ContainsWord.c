#include "../include/ContainsWord.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

/**
 * @brief Opens file at filepath in read only mode and puts it into buffer.
 * Function strstr is used to check if there is an occurence of word in the
 * buffer. Returns 1 is the word is found, 0 if not.
 *
 * @param filepath Path to file
 * @param word  Word to search in file
 * @return int
 */
int ContainsWord(const char *filepath, const char *word) {
  int fd = open(filepath, O_RDONLY);  // open file in read-only mode
  if (fd < 0) {
    perror("Error opening file");
    return 0;
  }

  char buffer[BUFFER_SIZE];  // store file contents
  ssize_t bytes_read;  // Same as size_t but signed. Can return -1 (system calls
                       // and/or functions might return -1 to mean error).
  while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
    printf("Bytes read = %d\n", bytes_read);
    buffer[bytes_read] = '\0';
    if (strstr(buffer, word) !=
        NULL) {  // searches for word occurence in buffer
      close(fd);
      return 1;
    }
  }

  close(fd);
  return 0;
}