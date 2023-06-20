#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *myturn(void *arg)
{
    int *iptr = (int *)arg;
    int *j = (int *)malloc(sizeof(int));
    printf("thread: j %p\n", j);
    *j = 999; 
    for (int i=0; i < 8; i++) {
        sleep(1);
        printf("My Turn! %d,  iptr %d\n", i, *iptr);
        (*iptr)++;
    }

    return j;
}

void yourturn()
{
    for (int i=0; i < 3; i++) {
        sleep(2);
        printf("Your Turn! %d\n",i);
    }
}

int main()
{
    pthread_t newthread;
    int v = 5;
    int *result_ptr = NULL;
    
    pthread_create(&newthread, NULL, myturn, &v);
    //myturn();
    yourturn();
    pthread_join(newthread, (void *) &result_ptr);
    printf("thread's done: v = %d, *result = %d\n", v, *result_ptr);
    printf("main: result %p\n", result_ptr);
    free(result_ptr);
}
