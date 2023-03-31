/* File:     omp_pi_ver2.cpp
 *
 * Purpose:  A parallel solution that calculates pi; uses OpenMP
 *
 * Compile:  g++ -g -Wall -fopenmp -o omp_pi omp_pi_ver2.cpp
 * Run:      ./omp_pi
 * 
 * Input:    none
 * Output:   Time to calculate the partial sums, and the calculated pi value
 *
 */

// CptS 223 - What happens to the time required to
// run these programs when NUM_THREADS is set to 1, then 2,
// then up to the max cores on your system? The time should
// decrease as you increase your NUM_THREADS. Does this happen?

// Remember OpenMP is a multi-threading, shared address model

#include <iostream>
#include <stdlib.h>
#include <omp.h>

static long num_steps = 100000000; // change this number to test
double step;

#define NUM_THREADS 2 // change this number to test
#define MAX 10000


// shows how to work with a critical region
int main (int argc, char *argv[])
{
    int i = 0, nthreads = 0;
    double pi = 0.0; // sum[NUM_THREADS] = {0.0};

    step = 1.0/(double)num_steps;

    omp_set_num_threads (NUM_THREADS);
    double time = omp_get_wtime (); // get current wall clock time

    // going into this parallel region
    #pragma omp parallel
    {
        int i = 0, id = 0, nthrds = 0;
        double x = 0.0, sum = 0.0; // sum is no longer shared
                                 // it's on stack, each thread has own copy

        id = omp_get_thread_num(); // which thread is running
        nthrds = omp_get_num_threads (); // may not match,
                                         // the number requested

        if(id == 0) 
        {
            nthreads = nthrds;
        }

        // the code 
        for ( i = id, sum = 0.0; 
              i < num_steps; 
              i = i + nthrds)
        {
            x = (i + 0.5) * step;
            // false sharing does not happen here
            sum += 4.0 / (1.0 + x * x);
        }

        // let's move pi into parallel regions; remember since it's declared outside parallel region
        // it's shared between all threads - we need to protect it from being read and updated  asynchronously. 
        // we do this by adding a critical section, which enforces mutual exclusion.
        // this means only one thread can execute the critical section at a time. 
        // note: we also don't want to place this pi update in the above loop with the critical around it; slows down performance
        #pragma omp critical
        {
            pi += sum * step;
        }
    }
    std::cout << "time: " << omp_get_wtime () - time << \
    " seconds to run parallel region." << std::endl;
    // add the partial sums outside the parallel region
    //for (i = 0, pi = 0.0; i < nthreads; i++) 
    //{
      //  pi += sum[i] * step;
    //}

    std::cout << "pi: " << pi << std::endl;

    return 0;
}

