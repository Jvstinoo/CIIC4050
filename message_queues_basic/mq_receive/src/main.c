#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  mqd_t queue;

  struct mq_attr attr;

  // Initialize the queue attributes
  attr.mq_flags = 0;
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = 8192;
  attr.mq_curmsgs = 0;

  queue = mq_open("/my_queue_os", O_RDONLY, 0644, &attr);

  char message[8192];
  int bytes_read = mq_receive(queue, message, 8192, NULL);

  while (bytes_read != -1) {
    printf("message read: %s\n", message);
    printf("size message: %d\n", bytes_read);

    bytes_read = mq_receive(queue, message, 8192, NULL);
  }
  mq_unlink("/my_queue_os");
  mq_close(queue);

  return 0;
}
