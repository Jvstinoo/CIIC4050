#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Opens message queue called 'time_queue' and sends three messages per
 * each second. First message sends "h" plus hour, second message sends "m" plus
 * minutes and last message sends "s" plus seconds. Uses sleep(1) to ensure it
 * is getting a new second each time.
 *
 * @return int
 */
int main() {
  mq_unlink("/time_queue");
  mqd_t queue;
  queue = mq_open("/time_queue", O_CREAT | O_WRONLY, 0644, NULL);

  while (1) {
    // Get current time
    time_t now;
    struct tm *timeinfo;
    time(&now);                  // Get system time
    timeinfo = localtime(&now);  // Convert to local time

    char buffer[8192];
    snprintf(buffer, 8192, "h%02d", timeinfo->tm_hour);
    printf("%s\n", buffer);
    mq_send(queue, buffer, 8192, 0);

    snprintf(buffer, 8192, "m%02d", timeinfo->tm_min);
    printf("%s\n", buffer);
    mq_send(queue, buffer, 8192, 0);

    snprintf(buffer, 8192, "s%02d", timeinfo->tm_sec);
    printf("%s\n", buffer);
    mq_send(queue, buffer, 8192, 0);

    sleep(1);
  }

  return 0;
}
