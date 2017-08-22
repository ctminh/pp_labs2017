#include <stdio.h>
#include <omp.h>

/* Define some values */

/* Global variables */

/* User-defined functions */

/* Main function */
int main(int argc, char **argv){
    int x;
    x = 2;
    #pragma omp parallel num_threads(2) shared(x)
    {
        int tid = omp_get_thread_num();
        if(tid == 0){
            x = 5;
        }else{
            /* What is the value of x? */
            printf("1. Thread %d: x = %d\n", tid, x);
        }

        #pragma omp barrier
        if(tid == 0){
            printf("2. Thread %d: x = %d\n", tid, x);
        }else{
            printf("3. Thread %d: x = %d\n", tid, x);
        }
    }

    return 0;
}
