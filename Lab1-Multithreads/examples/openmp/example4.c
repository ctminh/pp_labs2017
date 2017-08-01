#include <omp.h>

/* Define some values */
#define N   1000
#define CHUNKSIZE 10
#define MAX_THREADS 48
#define NUM_THREADS 24

/* Global variables */
int count[MAX_THREADS];

int main(int argc, char **argv){
    int i, chunk;
    float a[N], b[N], c[N];

    /* Some initializations */
    for(i = 0; i < N; i++){
        a[i] = b[i] = i * 1.0;
    }

    chunk = CHUNKSIZE;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for \
        shared(a,b,c,chunk) private(i) \
        schedule(static,chunk)
    //omp_set_thread_num(NUM_THREADS);
    for(i = 0; i < N; i++){
        int tid = omp_get_thread_num();
        c[i] = a[i] + b[i];
        count[tid]++;
    }

    /* Validation */
    printf("Vector c:\n");
    for(i = 0; i < 10; i++)
        printf("\t%f ", c[i]);
    printf("...\n");

    /* Statistic */
    printf("Num of iter with thread:\n");
    for(i = 0; i < MAX_THREADS; i++){
        if(count[i] != 0)
            printf("\tThread %d running %d iters\n", i, count[i]);
    }

    return 0;
 }
