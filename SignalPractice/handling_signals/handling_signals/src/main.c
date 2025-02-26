#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
	printf("Received signal %d\n", sig);
}

int main() {
	struct sigaction sa;
	sa.sa_handler = handle_signal;
  sigaction(SIGUSR1, &sa, NULL);

  while (1) {
    pause();
  }
}
