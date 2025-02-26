#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * @brief Opens message queue called 'time_queue' and reads message. The format
 * of the message received begins with 'h', 'm' or 's'. This is used to identify
 * if the message received is the hour, minute or second and depending on this,
 * the print is formatted differently to display the time in hour:minute:second
 * format.
 *
 * @return int
 */
int main() {
  mqd_t queue;
  queue = mq_open("/time_queue", O_RDONLY, 0644, NULL);
  char *hour;
  char *min;
  char *sec;

  while (1) {
    char message[8192];
    int bytes_read = mq_receive(queue, message, 8192, NULL);
    if (message[0] == 'h') {
      hour = message + 1;
      printf("%s", hour);
    } else if (message[0] == 'm') {
      min = message + 1;
      printf(":%s", min);
    } else if (message[0] == 's') {
      sec = message + 1;
      printf(":%s\n", sec);
    }
  }
  return 0;
}
