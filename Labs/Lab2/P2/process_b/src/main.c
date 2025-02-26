#include <fcntl.h> /* For O_* constants */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <unistd.h>

#define SHM_NAME "/float_block"

volatile int position = 0;

/**
 * @brief Opens shared memory block 'float_block' and adds new element double
 * the previous one while checking if memory block is not at full capacity.
 *
 * @param sig Signal sent by process a. In this case for SIGUSR1: 10.
 */
void handle_SIGUSR1_signal(int sig) {
  int shared_block = shm_open(SHM_NAME, O_RDWR, 0666);
  float *shm_ptr = mmap(0, 1000 * sizeof(float), PROT_READ | PROT_WRITE,
                        MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    close(shared_block);
    exit(1);
  }
  if (position < 1000) {
    shm_ptr[position] = position == 0 ? 1 : shm_ptr[position - 1] * 2;
    position++;
    printf("Added new number %.2f\n", shm_ptr[position - 1]);
  } else {
    printf(
        "Memory block of 1000 floats has been filled, choose another "
        "option!\n");
  }

  munmap(shm_ptr, 1000 * sizeof(float));
  close(shared_block);
}

/**
 * @brief Opens shared memory block 'float_block' and deletes last added element
 * while checking if memory block is not empty.
 *
 * @param sig Signal sent by process a. In this case for SIGUSR2: 12.
 */
void handle_SIGUSR2_signal(int sig) {
  int shared_block = shm_open(SHM_NAME, O_RDWR, 0666);
  float *shm_ptr = mmap(0, 1000 * sizeof(float), PROT_READ | PROT_WRITE,
                        MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    close(shared_block);
    exit(1);
  }
  if (position > 0) {
    float deleted_number = shm_ptr[position - 1];
    shm_ptr[position - 1] = 0;
    position--;
    printf("Deleted last number %.2f\n", deleted_number);
  } else {
    printf("No more numbers are left in array, choose another option!\n");
  }

  munmap(shm_ptr, 1000 * sizeof(float));
  close(shared_block);
}

/**
 * @brief Opens shared memory block 'float_block' and divides all elements in
 * memory block by two while checking the element is not 0.
 *
 * @param sig Signal sent by process a. In this case for SIGALRM: 14.
 */
void handle_SIGALRM_signal(int sig) {
  int shared_block = shm_open(SHM_NAME, O_RDWR, 0666);
  float *shm_ptr = mmap(0, 1000 * sizeof(float), PROT_READ | PROT_WRITE,
                        MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    close(shared_block);
    exit(1);
  }

  for (int i = 0; i < position; i++) {
    if (shm_ptr[i] != 0) {
      shm_ptr[i] /= 2;
    }
  }

  if (position == 0) {
    printf(
        "No numbers were added to memory block, did not divide any. Choose "
        "another option.\n");
  } else {
    printf("Divided %d elements in memory block\n", position + 1);
  }

  munmap(shm_ptr, 1000 * sizeof(float));
  close(shared_block);
}

int main() {
  int shared_block = shm_open(SHM_NAME, O_RDWR, 0666);
  float *shm_ptr = mmap(0, 1000 * sizeof(float), PROT_READ | PROT_WRITE,
                        MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    close(shared_block);
    exit(1);
  }

  for (int i = 0; i < 1000; i++) {
    shm_ptr[i] = 0;
  }

  struct sigaction sa;
  sa.sa_handler = handle_SIGUSR1_signal;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGUSR1, &sa, NULL);

  struct sigaction sa_2;
  sa_2.sa_handler = handle_SIGUSR2_signal;
  sigemptyset(&sa_2.sa_mask);
  sa_2.sa_flags = 0;
  sigaction(SIGUSR2, &sa_2, NULL);

  struct sigaction sa_3;
  sa_3.sa_handler = handle_SIGALRM_signal;
  sigemptyset(&sa_3.sa_mask);
  sa_3.sa_flags = 0;
  sigaction(SIGALRM, &sa_3, NULL);

  while (1) {
    pause();
  }

  return 0;
}
