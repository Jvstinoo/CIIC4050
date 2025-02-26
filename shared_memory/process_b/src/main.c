#include <fcntl.h>
#include <mqueue.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define SHM_NAME "/shared_mem"

int main() {
  int shared_block = shm_open(SHM_NAME, O_RDWR, 0666);
  char* shm_ptr =
      mmap(0, 1000, PROT_READ | PROT_WRITE, MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed!");
    close(shared_block);
    exit(1);
  }

  for (int i = 0; i < 1000; i++) {
    putchar(shm_ptr[i]);
  }

  shm_unlink(SHM_NAME);

  return 0;
}
