/*
 * alarm_fork.c
 *
 * This version of alarm.c uses fork to create a new process to
 * wait for each alarm to expire.
 */
#include <sys/types.h>
#include <sys/wait.h>
#include "errors.h"

int main (int argc, char *argv[])
{
    int status;
    char line[128];
    int seconds;
    pid_t pid;
    char message[64];

    while (1) {
        printf ("Alarm fork > ");
        if (fgets (line, sizeof (line), stdin) == NULL) exit (0);
        if (strlen (line) <= 1) continue;

        /*
         * Parse input line into seconds (%d) and a message
         * (%64[^\n]), consisting of up to 64 characters
         * separated from the seconds by whitespace.
         */
        if (sscanf (line, "%d %64[^\n]", 
            &seconds, message) < 2) {
            fprintf (stderr, "Bad command\n");
        } else {
            pid = fork ();
            if (pid == (pid_t)-1)
                errno_abort ("Fork");
            if (pid == (pid_t)0) {
                /*
                 * If we're in the child, wait and then print a message
                 */
                pid_t child_pid = getpid();
                printf("child process %d: sleeping for %d seconds\n", child_pid, seconds);
                sleep(seconds);
                printf("child process %d: elapsed (%d) seconds - message \"%s\". Exiting...\n", child_pid, seconds, message);
                exit(0);
            } else {
                /*
                 * In the parent, call waitpid() to collect any children that
                 * have already terminated.
                 */
                printf("main process: waiting to reap child %d...\n", pid);
                do {
                    pid = waitpid ((pid_t)-1, NULL, WNOHANG);
                    printf("waitpid(): pid %d\n", (int)pid);
                    if (pid == (pid_t)-1)
                        errno_abort ("Wait for child");
                } while (pid != (pid_t)0);
            }
        }
    }
}
