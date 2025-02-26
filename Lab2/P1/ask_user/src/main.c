#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT 256

/**
 * @brief Asks user for a directory path and word that will be used to run a
 * process that will search for the word in the files inside the directory path.
 * Uses fork to create a child and execlp to call another binary that takes
 * dir_path and word as inputs.
 *
 * @return int
 */
int main() {
  char dir_path[MAX_INPUT];
  char word[MAX_INPUT];
  printf("Enter file path: ");
  scanf("%s", dir_path);
  printf("Enter word: ");
  scanf("%s", word);

  pid_t pid = fork();
  printf("AFTER PID\n");

  if (pid < 0) {
    perror("Failed\n");
    exit(1);
  }

  if (pid == 0) {  // child
    int status_code = execlp("../../word_explorer/build/word_explorer",
                             "word_explorer", dir_path, word, NULL);
    if (status_code == -1) {
      perror("Error executing process\n");
      exit(1);
    }
  } else {
    wait(NULL);
  }

  return 0;
}
