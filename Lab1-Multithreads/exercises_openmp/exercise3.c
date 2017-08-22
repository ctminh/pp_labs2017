#include <stdio.h>
#include <omp.h>

/* Define some values */
#define NUM_THREADS 3

/* Global variables */

/* User-defined functions */

/* Main function */
int main(int argc, char **argv){
    omp_set_nested(1);  // point out that there is 1 nested parallel region
    omp_set_max_active_levels(8);   // the maximum number of nested active parallel region is 8
    omp_set_dynamic(0);
    omp_set_num_threads(2); // there are 2 threads to run
    #pragma omp parallel
    {
        omp_set_num_threads(3); // this inside region is performed by 3 threads
        #pragma omp parallel
        {
            omp_set_num_threads(4);
            #pragma omp single
            {
                /*
                 * The following should print:
                 * Inner: max_act_lev=8, num_thds=3, max_thds=4
                 * Inner: max_act_lev=8, num_thds=3, max_thds=4
                 * */
                printf ("Inner: max_act_lev=%d, num_thds=%d, max_thds=%d\n",
                        omp_get_max_active_levels(), omp_get_num_threads(),
                        omp_get_max_threads());
            }
        }
        #pragma omp barrier
        #pragma omp single
        {
            /*
             * The following should print:
             * Outer: max_act_lev=8, num_thds=2, max_thds=3
             * */
            printf ("Outer: max_act_lev=%d, num_thds=%d, max_thds=%d\n",
                    omp_get_max_active_levels(), omp_get_num_threads(),
                    omp_get_max_threads());
        }
    }

    return 0;
}
