/* File:     omp_sum_ver3.cpp
 *
 * Purpose:  A parallel solution that sums all values in an array; uses OpenMP
 *
 * Compile:  g++ -g -Wall -fopenmp -o omp_sum omp_sum_ver3.cpp
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

//static long num_steps = 100000000; // change this number to test
//double step;

#define NUM_THREADS 2 // change this number to test
#define MAX 1000000


// shows how to parallelize a for and eliminate loop depencies
int main (int argc, char *argv[])
{
    // computational intensive loops
    // find the compute intensive loops
    int i = 0, j = 0, numbers[MAX];

    omp_set_num_threads (NUM_THREADS);

    // OpenMP supports parallelizing a for () loop,/ which means that each iteration can be handled
    // by a separate thread. However, the loop iterations need to be independent so they can safely execute
    // in any order without loop-carried dependencies

    double start_time = omp_get_wtime ();
    // for this parallel region, for is specified; can't place {} around region
    // j = 0;
    // below loop is identified as loop version 1
    // uncomment when not running other loop version 2
    /*#pragma omp parallel for 
        for (i = 0; i < MAX; ++i)
        {
            j += 1; // this is a loop carry dependency.
                    // this means can't parallellize
                    // loop iterations. value for j is
                    // dependent on which iteration is running.
            numbers[i] = j;
        }*/

    // below loop is identified as loop version 2
    // uncomment when not running other loop version 1
    //    *this a better option than above loop because identified how to make concurrency work

    #pragma omp parallel for 
        for (i = 0; i < MAX; ++i)
        {
           int j = (i + 1); // removes the loop carry dependency
           numbers[i] = j;
        } 
    double end_time = omp_get_wtime();
    std::cout << "time: " << end_time - start_time << " seconds to run parallel region." << std::endl;
    // outside parallel region

    // Please note that the sum obtained from loop version 2 gives a consistent sum, but the one obtained from loop
    // version 1 does not. This is a result of the fact loop version 1 should not be run in parallel because
    // of loop carry dependencies
    
    //-----------------------------------------------------------
    int sum = 0;
    // let's run the below for using a parallel region
    // and reduction. reduction allows for each 
    // thread to get a local copy of sum and do a local
    // addition on sum. when the thread is done
    // it combines result into the sum that exists
    // outside the parallel region
    
    start_time = omp_get_wtime ();
    // as a exercise comment out the pragma line below;
    // how much slower does the loop run?
    
    #pragma omp parallel for reduction (+:sum)
     for (i = 0; i < MAX; ++i)
     {
        sum += numbers[i];
     }
    end_time = omp_get_wtime();
     std::cout << "time: " << end_time - start_time << " seconds to run parallel region with reduction." << std::endl;

    std::cout << "sum: " << sum << std::endl;

    return 0;
}
