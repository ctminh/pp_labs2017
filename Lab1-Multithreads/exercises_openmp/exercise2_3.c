#include <stdio.h>
#include <omp.h>

/* Define some values */
#define NUM_THREADS 3

/* Global variables */

/* User-defined functions */

/* Main function */
int main(int argc, char **argv){
    int i;
    int data;
    int flag = 0;
    int count[NUM_THREADS];
    
    // Some initializations
    for(i = 0; i < NUM_THREADS; i++)
        count[i] = 0;

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int tid = omp_get_thread_num();
        if(tid == 0){
            // Set flag to release thread1
            sleep(5);
            #pragma omp atomic update
            flag++;
        }else if(tid == 1){
            // Loop until the flag reaches 1
            #pragma omp flush(flag)
            while(flag < 1){
                #pragma omp flush(flag)
                count[1]++;
            }
            printf("Thread 1 awoken after %d loops.\n", count[1]);

            // Set flag to release thread 2
            #pragma omp atomic update
            flag++;
        }else if(tid == 2){
            // Loop until the flag reaches 2
            #pragma omp flush(flag)
            while(flag < 2){
                #pragma omp flush(flag)
                count[2]++;
            }
            printf("Thread 2 awoken after %d loops.\n", count[2]);
        }       
    }

    return 0;
}
