#include <cstdio>
#include <cstdlib>
#include <unistd.h> // fork
#include <sys/wait.h>

int main() {
    std::printf("Process id: %d\n", getpid());
    int rc = fork();
    if (rc == -1) {
        std::fprintf(stderr, "Process creation failed!\n");
        return EXIT_FAILURE;
    }

    if (!rc) { // Child process creation succeeded
        std::printf("Child process id: %d\n", getpid());
    } else { // Parent process path
        int rc_wait = wait(nullptr); // waiting the child process to complete
        std::printf("Parent process %d of child process %d\n", getpid(), rc_wait);
    }
}