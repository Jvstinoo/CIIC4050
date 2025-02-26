#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


int main() {
  pid_t pid = fork();
  if (pid == 0) { // child
    int status = execlp("../../../message_queues_advanced/mq_sender/build/mq_sender", "mq_sender", NULL);
    
    if (status == -1) {
      perror("Was not able to execute mq_sender\n");
      exit(1);
    }
  } else {
    pid_t pid_2 = fork();
    if (pid_2 == 0) { // second child
      int status = execlp("../../../message_queues_advanced/mq_receiver/build/mq_receiver", "mq_receiver", NULL);
      
      if (status == -1) {
        perror("Was not able to execute mq_receiver\n");
        exit(1);
      }
    }
  }
  return 0;
}
