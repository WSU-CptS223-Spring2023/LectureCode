
/* File:     sum.cpp
 *
 * Purpose:  Sums all values in an array
 *
 * Compile:  g++ -g -Wall -o sum sum.cpp
 * Run:      ./sum
 * 
 * Input:    none
 * Output:   Time to create the array and perform the sum
 *
 */

// We are looking at this example for purposes of understanding how to parallelize programs
// using openMP

// History:  - Implemented create_array ()
//                and sum_array (). Discussed
//                strategies and places in
//                the code where parallelization
//                would be helpful.

#include <iostream>
#include <stdlib.h>
#include <omp.h>
#define MAX 1000000

int main (int argc, char *argv[])
{
    // computational intensive loops
    // find the compute intensive loops
    int j = 0, numbers[MAX];
    
    for (int i = 0; i < MAX; ++i) {
            j += 1; 
            numbers[i] = j;
        }
    
    long int sum = 0;
    
    double start_time = omp_get_wtime ();
    for (int i = 0; i < MAX; ++i) {
           sum = sum + numbers[i];
    } 

    double end_time = omp_get_wtime();

    std::cout << "time: " << end_time - start_time  << std::endl;
    std::cout << "sum: " << sum << std::endl;

    return 0;
}