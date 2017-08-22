#include <omp.h>

/* Define some values */

/* Global variables */

/* User-defined functions */
void simple(int n, float *a, float *b){
    int i;
    #pragma omp parallel for
    for(i = 0; i < n; i++){  // i is private or global?
        b[i] = (a[i] + a[i-1]) / 2.0;
        int tid = omp_get_thread_num();
        printf("Thread %d runs iter %d.\n", tid, i);
    }

    // Validation
    printf("Vector result:\n");
    for(i = 1; i < n; i++)
        printf("\t%f ", b[i]);
    printf("\n");
}

/* Main function */
int main(int argc, char **argv){
    int i, n;
    float *a;
    float *b;

    /* Some initializations */
    n = 10;
    a = (float *) malloc(n * sizeof(float));
    b = (float *) malloc(n * sizeof(float));
    for(i = 0; i < n; i++){
        a[i] = b[i] = i * 1.0;
    }
    
    /* call function */
    simple(n, a, b);

    return 0;
}
