#include <assert.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signo, siginfo_t *info, void *context) {
  printf("signo %d si_signo %d si_code %d\n", signo, info->si_signo, info->si_code);
}

int main(int argc, char *argv[]) {
  struct sigaction sigact, old_sigact;

  sigemptyset(&sigact.sa_mask);
  sigact.sa_flags = SA_SIGINFO | SA_RESETHAND;
  sigact.sa_sigaction = handler;
  sigaction(SIGUSR1, &sigact, NULL);

  printf("raise SIGUSR1 signal\n");
  kill(getpid(), SIGUSR1);

  sigaction(SIGUSR1, NULL, &old_sigact);
  if (old_sigact.sa_handler != SIG_DFL)
    printf("signal handler was not reset\n");

  return(0);
}
