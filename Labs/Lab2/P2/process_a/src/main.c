#include <fcntl.h> /* For O_* constants */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h> /* For mode constants */
#include <unistd.h>

#define SHM_NAME "/float_block"

/**
 * @brief Creates memory block of 1000 floats and creates a child process that
 * executes a process b that has shared access to the memory block created in
 * this process. This program outputs instructions to user and depending on the
 * instruction the user chooses, it sends signal to process b to modify the
 * memory block of floats.
 *
 * @return int
 */
int main() {
  shm_unlink(SHM_NAME);
  int shared_block = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
  ftruncate(shared_block, 1000 * sizeof(float));
  float *shm_ptr = mmap(0, 1000 * sizeof(float), PROT_READ | PROT_WRITE,
                        MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed!");
    exit(1);
  }

  pid_t pid = fork();
  if (pid == 0) {  //  child
    int status_code =
        execlp("../../process_b/build/process_b", "process_b", NULL);
    if (status_code == -1) {
      perror("Error executing process_b\n");
      exit(1);
    }
  }
  while (1) {
    int option_number;
    printf("Choose one of the following options (1,2,3,4):\n");
    printf("1. Include new number [SIGUSR1]\n");
    printf("2. Delete the last number [SIGUSR2]\n");
    printf("3. Divide number values by two [SIGALRM]\n");
    printf("4. Print current numbers\n");
    printf("5. I'm done, destroy memory block and exit program\n");
    scanf("%d", &option_number);

    if (option_number == 1) {
      kill(pid, SIGUSR1);
      sleep(1);
    } else if (option_number == 2) {
      kill(pid, SIGUSR2);
      sleep(1);
    } else if (option_number == 3) {
      kill(pid, SIGALRM);
      sleep(1);
    } else if (option_number == 4) {
      printf("Numbers in memory block: \n");
      for (int i = 0; i < 5; i++) {
        printf("%.2f\n", shm_ptr[i]);
      }
      sleep(1);
    } else if (option_number == 5) {
      break;
    } else {
      printf("Please choose valid option.\n");
    }
  }
  munmap(shm_ptr, 1000 * sizeof(float));
  shm_unlink(SHM_NAME);
  printf("SHM block deleted!\n");
  return 0;
}
