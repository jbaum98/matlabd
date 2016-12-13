#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
}

int main(int argc, char *argv[]) {
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");

    sigset_t mask;
    sigset_t orig_mask;
    int sig;
    pid_t pid;

    //pid = getpid();
    //printf("%d\n",pid);

    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);

    if (sigprocmask(SIG_BLOCK, &mask, &orig_mask) < 0) {
        perror("sigprocmask");
        return 1;
    }
    
    sigwait(&mask, &sig);
    
    return 0;
}
