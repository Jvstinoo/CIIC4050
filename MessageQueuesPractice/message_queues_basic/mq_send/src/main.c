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

  queue = mq_open("/my_queue_os", O_CREAT | O_WRONLY, 0644, &attr);

  mq_send(queue, "hola queue world 1", 8192, 0);
  mq_send(queue, "hola queue world 2", 8192, 0);
  mq_send(queue, "hola queue world 3", 8192, 0);
  mq_send(queue, "hola queue world 4", 8192, 0);
  mq_send(queue, "hola queue world 5", 8192, 0);

  return 0;
}
