#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  mqd_t queue;
  //  queue = mq_open("/my_queue_os", O_RDONLY, 0644, NULL);
  mq_unlink("/my_queue_os");
  char message[8192];
  int bytes_read = mq_receive(queue, message, 8192, NULL);

  printf("Message read: %s\n", message);
  printf("Size message: %d\n", bytes_read);

  return 0;
}