/* File:     omp_sum_ver1.cpp
 *
 * Purpose:  A parallel solution that sums all values in an array; uses OpenMP; doesn't use parallel for directive
 *
 * Compile:  g++ -g -Wall -fopenmp -o omp_sum omp_sum_ver1.cpp
 * Run:      ./omp_sum
 * 
 * Input:    none
 * Output:   Time to create the array and perform the sum
 *
 */

// CptS 223 - What happens to the time required to run these programs when NUM_THREADS is set to 1, then 2,
// then up to the max cores on your system? 
// The time should decrease as you increase your NUM_THREADS. Does this happen?

// Remember OpenMP is a multi-threading, shared address model

#include <iostream>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 2 // change this number to test
#define MAX 10000


// shows how to parallelize a for and eliminate loop depencies
int main (int argc, char *argv[])
{
    // computational intensive loops
    // find the compute intensive loops
    int j = 0, numbers[MAX];
    int workload = MAX / NUM_THREADS;

    for (int i = 0; i < MAX; ++i) {
            j += 1; 
            numbers[i] = j;
        }
    
    long int sum = 0;
    omp_set_num_threads (NUM_THREADS);
    double start_time = omp_get_wtime ();
    
 #pragma omp parallel 
 {
    int tid = omp_get_thread_num();
    long int local_sum = 0;
    for (int i = tid*workload; i < (tid+1)*workload; ++i) {
           local_sum = local_sum + numbers[i];
    } 
    sum =  sum + local_sum;
 }
    double end_time = omp_get_wtime();
    std::cout << "time: " << end_time - start_time << " seconds to run parallel region ." << std::endl;
    std::cout << "sum: " << sum << std::endl;
    // outside parallel region

    return 0;
}
