#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t tid1, tid2;

void *second_thread_routine(void *arg)
{
    int i = 0;

    if (arg) {
        printf("Inside %s: \"%s\"\n", __FUNCTION__, (char *)arg);
    }

    for (i = 0; i < 50; i++) {
        printf("Inside %s: i = %d\n", __FUNCTION__, i);
        sleep(1);
    }

    printf("second thread done\n");
    return NULL;
}

void *first_thread_routine(void *arg)
{
    int i = 0;

    if (arg) {
        printf("Inside %s: \"%s\"\n", __FUNCTION__, (char *)arg);
    }
    for (i = 91; i < 100; i++) {
        printf("Inside %s: i = %d\n", __FUNCTION__, i);
        sleep(1);
    }

    printf("waiting for second thread done\n");
    pthread_join(tid2, NULL);
    printf("first thread done\n");

    return NULL;
}

int main()
{
    int i;
    int rc;
    char *t1_msg = "T1: first thread";
    char *t2_msg = "T2: second thread";

    rc = pthread_create(&tid1, NULL, first_thread_routine, t1_msg);
    rc |= pthread_create(&tid2, NULL, second_thread_routine, t2_msg);
    if (rc != 0) {
        fprintf(stderr, "Error: pthread_create()");
        exit(EXIT_FAILURE);
    }

    pthread_join(tid1, NULL);
    printf("all threads done\n");

    return 0; 
}
