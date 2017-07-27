#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define CONSTANTS
#define NUM_THREADS 4
#define N 1000
#define MEGEXTRA 1000000

// Global variables
pthread_attr_t attr;

// user-defined function
void *user_def_func(void *threadID){
    long TID;
    TID = (long) threadID;
    int i, j;
    double A[N][N];
    size_t mystacksize;

    pthread_attr_getstacksize(&attr, &mystacksize);
    printf("Thread %ld: stack size = %li bytes\n", TID, mystacksize);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            A[i][j] = ((i * j) / 3.452) + (N - i);
    }
    pthread_exit(NULL);
}

int main (int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int creation_flag, join_flag;
    long i;
    size_t stacksize;

    /* Initialize and set thread detached atribute */
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);

    // Default stack size
    printf("Default stack size = %li\n", stacksize);
    
    // Stack size by user defined
    stacksize = sizeof(double) * N * N + MEGEXTRA;

    // Set stack size
    pthread_attr_setstacksize(&attr, stacksize);

    printf("Creating threads with stack size = %li bytes\n", stacksize);
    for(i = 0; i < NUM_THREADS; i++){
        creation_flag = pthread_create(&threads[i], &attr, user_def_func, (void *)i);
        if (creation_flag){
            printf("ERROR: return code from pthread_create() is %d\n", creation_flag);
            exit(-1);
        }
    }
   
    pthread_exit(NULL);
    return 0;
}
