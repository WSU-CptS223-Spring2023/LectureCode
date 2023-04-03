/* File:     omp_pi_ver1.cpp
 * Purpose:  Estimate pi using OpenMP and the formula - parallel solution
         
 *
 *              pi = 4*[1 - 1/3 + 1/5 - 1/7 + 1/9 - . . . ]
 *
 * Compile:  	g++ -g -Wall -fopenmp -o omp_pi omp_pi_ver1.cpp

 *
 * Notes:
 *    1.  The radius of convergence is only 1.  So the series converges
 *        *very* slowly.
 *    2. Alternative solution using critical section pragma. 
 */       

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <omp.h> 

#define NUM_THREADS 2 // change this number to test
#define STEPS 100000000

int main(int argc, char* argv[]) {
   long long n;
   double factor;
   double pi = 0.0;

   n = STEPS;

    omp_set_num_threads (NUM_THREADS);
    double start_time = omp_get_wtime (); // get current wall clock time

#  pragma omp parallel private(factor)
{
   int i = 0;
   int id = omp_get_thread_num(); // which thread is running
   int nthrds = omp_get_num_threads (); // may not match,

   double my_sum = 0;
   for (i = id;  i < n;  i = i + nthrds) {
      factor = (i % 2 == 0) ? 1.0 : -1.0; 
      my_sum += factor/(2*i+1);
   }
   // pi is  shared between all threads - we need to protect it from being read and updated  asynchronously. 
   // we do this by adding a critical section, which enforces mutual exclusion.
   // this means only one thread can execute the critical section at a time. 
   // note: we also don't want to place this sum update in the above loop with the critical around it; slows down performance 
   #pragma omp critical
   pi += my_sum;
}   
   double end_time = omp_get_wtime (); 

   pi = 4.0*pi;
   std::cout << "   With n = " << n << " terms and " << NUM_THREADS << " threads" << std::endl;
   std::cout.precision(14);
   std::cout << "   Our estimate of pi = " << pi << std::endl;
   std::cout.precision(14);
   std::cout << "                   pi = " << 4.0*atan(1.0) << std::endl;
   std::cout << "   Time: " << end_time - start_time << " seconds to run parallel region." << std::endl;
   return 0;
}  /* main */

