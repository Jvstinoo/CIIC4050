#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Need two parameters to run\n");
    exit(EXIT_FAILURE);
  }
  char *word = argv[1];
  int times = atoi(argv[2]);
  for (int i = 0; i < times; i++) {
    puts(word);
  }
  printf("I'm alive!");
  return 0;
}
