/*
 * alarm_fork.c
 *
 * This version of alarm.c uses pthread_create to create a
 * separate thread to wait for each alarm to expire.
 */
#include <pthread.h>
#include "errors.h"

typedef struct alarm_tag {
    pthread_t thread_id;
    int         seconds;
    char        message[64];
} alarm_t;

void *alarm_thread (void *arg)
{
    int status;

    alarm_t *alarm = (alarm_t*)arg;
    if (!alarm) {
        fprintf(stderr, "alarm %p! return\n", arg);
        return NULL;
    }

    status = pthread_detach(pthread_self ());
    if (status != 0) {
        free(alarm);
        err_abort(status, "Detach thread");
    }
    
    printf("Thread ID: %d, sleeping for %d seconds\n", (int) alarm->thread_id, alarm->seconds);
    sleep(alarm->seconds);
    printf("thread(%d) %s\n", alarm->seconds, alarm->message);
    free(alarm);
    return NULL;
}

int main (int argc, char *argv[])
{
    int status;
    char line[128];
    alarm_t *alarm;
    pthread_t thread;

    while (1) {
        printf ("Alarm> ");
        if (fgets (line, sizeof (line), stdin) == NULL)
            exit(0);
        if (strlen (line) <= 1)
           continue;

        alarm = (alarm_t*)malloc(sizeof (alarm_t));
        if (alarm == NULL)
            errno_abort ("Allocate alarm");

        /*
         * Parse input line into seconds (%d) and a message
         * (%64[^\n]), consisting of up to 64 characters
         * separated from the seconds by whitespace.
         */
        if (sscanf (line, "%d %64[^\n]", &alarm->seconds, alarm->message) < 2) {
            fprintf (stderr, "Bad command\n");
            free (alarm);
        } else {
            status = pthread_create(&alarm->thread_id, NULL, alarm_thread, alarm);
            if (status != 0) {
                free(alarm);
                err_abort (status, "Create alarm thread");
            } else {
                printf("successfully created new thread %d\n", alarm->thread_id);
            }
        }
    }
}
