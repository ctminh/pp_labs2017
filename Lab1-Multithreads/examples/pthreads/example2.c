#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

/* Thread Argument Passing */
// case-study 1
long taskids[NUM_THREADS];

// case-study 2

// user-defined function
void *user_def_func(void *threadID){
    long TID;
    TID = (long) threadID;
    printf("Hello World! from thread #%ld!\n", TID);
    pthread_exit(NULL);
}

int main (int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int creation_flag;
    long i;
    for(i = 0; i < NUM_THREADS; i++){
        // pass arguments
        taskids[i] = i;
        printf("In main: creating thread %ld\n", i);
        creation_flag = pthread_create(&threads[i], NULL, user_def_func, (void *)taskids[i]);
        if (creation_flag){
            printf("ERROR: return code from pthread_create() is %d\n", creation_flag);
            exit(-1);
        }
    }
    
    /* Last thing that main() should do */
    pthread_exit(NULL);
    return 0;
}
