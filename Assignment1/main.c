#include <iostream>
#include <cstdlib>

int main(int argc, char **argv){
    // Format for print number on screen
    std::cout.precision(7);

    // Check arguments passed into the program
    if(argc < 5){
        printf("ERROR: not enough arguments\n");
        exit(0);
    }

    // Get arguments
    int k_clusters = atoi(argv[1]);  // k of cluters
    int num_points = atoi(argv[2]);  // num of points
    int d = atoi(argv[3]);
    int t = atoi(argv[4]);

    // Create variables
    double **data = (double **)malloc(sizeof(double) *num_points);
    double **means = (double **)malloc(sizeof(double) *k_clusters);

    // Get points from text file or random
    
    
}
