#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define PAGE_SIZE 4096

int main() {
  FILE* file = fopen("lorem_ipsum.txt", "r+");
  // int fd = open("./crawls.txt", O_RDWR, 0600);

  int count = 0;

  char ch = fgetc(file);

  // fgetc moves pointer one forward, so to modify each character, we must
  // backwards once each time.
  while (ch != EOF) {
    fseek(file, -1, SEEK_CUR);
    fputc(tolower(ch), file);
    fseek(file, 0, SEEK_CUR);
    ch = fgetc(file);
  }

  fseek(file, 0, SEEK_SET);

  ch = fgetc(file);
  while (ch != EOF) {
    if (ch >= 'a' && ch < 'z' && (count % 2 == 0)) {
      fseek(file, -1, SEEK_CUR);
      fputc(toupper(ch), file);
      fseek(file, 0, SEEK_CUR);
    }
    count++;
    ch = fgetc(file);
  }

  fclose(file);
  return 0;
}
