#include <stdio.h>
#include <omp.h>

/* Define some values */

/* Global variables */

/* User-defined functions */

/* Main function */
int main(int argc, char **argv){
    int data;
    int flag = 0;
    #pragma omp parallel num_threads(2)
    {
        int tid = omp_get_thread_num();
        if(tid == 0){
            // Write to data
            data = 42;
            //sleep(5);
            // Flush data to thread 1 and order the write to data related to
            // the write to flag
            #pragma omp flush(flag, data)
            sleep(5);
            // Set flag to release thread 1
            flag = 1;
            //sleep(5);
            // Flush flag to ensure that therad 1 can see the changes
            #pragma omp flush(flag)
        }else{
            // Loop until we see the update to the flag
            #pragma omp flush(flag, data)
            while(flag < 1){
                #pragma omp flush(flag, data)
            }
            // Values of flag and data are undefined
            printf("flag = %d, data = %d\n", flag, data);
            #pragma omp flush(flag, data)
            // Values of data will be 42, value of flag still undefined
            printf("flag = %d, data = %d\n", flag, data);
        }       
    }

    return 0;
}
