#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <signal.h>
#include <string.h>

// Global variable to store the daemon's PID
pid_t daemon_pid = -1;

void startDaemon() {
    // Task i: Create a child process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // Task ii: Run child process as a daemon
    if (pid > 0) {
        // Parent process (the original process) exits
        exit(EXIT_SUCCESS);
    }

    // Task iii: Call umask function
    umask(0);

    // Task iv: Call setsid
    if (setsid() < 0) {
        perror("setsid() failed");
        exit(EXIT_FAILURE);
    }

    // Task v: Change working directory to root directory using chdir
    if (chdir("/") < 0) {
        perror("chdir() failed");
        exit(EXIT_FAILURE);
    }

    // Task vi: Close all file descriptors
    for (int fd = sysconf(_SC_OPEN_MAX); fd >= 0; fd--) {
        close(fd);
    }

    // Task vii: Initialize the log file using openlog and syslog
    openlog("MyDaemon", LOG_PID, LOG_DAEMON);

    // Task viii: Create daemon only once
    if (pid == 0) {
        daemon_pid = getpid(); // Store the daemon's PID for later use
        syslog(LOG_INFO, "Daemon created successfully.");
    }

    // Task ix: Generate and append the sequence to the syslog file
    while (1) {
        int n = daemon_pid;
        char sequence[1024] = "";

        while (n != 1) {
            snprintf(sequence, sizeof(sequence), "%s%d ", sequence, n);

            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
        }

        snprintf(sequence, sizeof(sequence), "%s1", sequence);
        syslog(LOG_INFO, "Sequence: %s", sequence);
        
        sleep(20); // Sleep for 20 seconds before generating the next sequence
    }
}

void stopDaemon() {
    if (daemon_pid > 0) {
        // Task i: Send SIGTERM signal to the daemon process
        kill(daemon_pid, SIGTERM);

        // Task ii: Write a message to syslog about stopping the daemon
        syslog(LOG_INFO, "Daemon stopped.");
    } else {
        syslog(LOG_WARNING, "Daemon not found.");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <start|stop>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "start") == 0) {
        startDaemon();
    } else if (strcmp(argv[1], "stop") == 0) {
        stopDaemon();
    } else {
        fprintf(stderr, "Invalid argument. Use 'start' to start the daemon or 'stop' to stop it.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
