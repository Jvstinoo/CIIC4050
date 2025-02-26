#include <signal.h>
#include <stdio.h>
#include <unistd.h>
//#include <wait.h>

int main() {
  pid_t pid;

  printf("Enter pid of process to kill: ");
  scanf("%d", &pid);

  kill(pid, SIGTERM);
  return 0;
}


