#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int source, dest;
  char ch;

  // Open the source file in read-only mode
  source = open("crawls.txt", O_RDONLY);
  if (source == -1) {
    perror("Error opening source file");
    return 1;
  }

  // Open the destination file in write-only mode, create if it doesn't exist
  dest = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (dest == -1) {
    perror("Error opening destination file");
    close(source);
    return 1;
  }

  // Copy each character from source to destination
  while (read(source, &ch, 1) == 1) {
    if (write(dest, &ch, 1) != 1) {
      perror("Error writing to destination file");
      close(source);
      close(dest);
      return 1;
    }
  }

  // Close both files
  close(source);
  close(dest);

  printf("File copied successfully.\n");
  return 0;
}

// int i = 0;
// // Copy each character from source to destination
// while (read(source, &ch, 1) == 1) {
//   data[i++] = ch;
//   if (i == 1000) {
//     printf(" one write \n");
//     if (write(dest, data, i - 1) != i - 1) {
//       perror("Error writing to destination file");
//       close(source);
//       close(dest);
//       return 1;
//     }
//     i = 0;
//   }
// }

// if (write(dest, data, i) != i) {
//   perror("Error writing to destination file 2");
//   close(source);
//   close(dest);
//   return 1;
// }