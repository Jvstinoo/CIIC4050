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
  shm_unlink(SHM_NAME);
  int shared_block = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
  ftruncate(shared_block, 1000);
  char *shm_ptr =
      mmap(0, 1000, PROT_READ | PROT_WRITE, MAP_SHARED, shared_block, 0);

  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    exit(1);
  }

  strcpy(shm_ptr, "HOLA MI NOMBRE ES PACO!");

  return 0;
}
