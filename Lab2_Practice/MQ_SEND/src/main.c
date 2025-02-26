#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  mqd_t queue;
  queue = mq_open("/my_queue_os", O_CREAT | O_WRONLY, 0644, NULL);

  mq_send(queue, "HOLA AMIGO", 8192, 0);

  return 0;
}