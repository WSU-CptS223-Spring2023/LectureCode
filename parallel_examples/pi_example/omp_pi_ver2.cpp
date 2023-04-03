/* File:     omp_pi_ver2.cpp
 * Purpose:  Estimate pi using OpenMP and the formula - parallel solution
         
 *
 *              pi = 4*[1 - 1/3 + 1/5 - 1/7 + 1/9 - . . . ]
 *
 * Compile:  	g++ -g -Wall -fopenmp -o omp_pi omp_pi_ver2.cpp

 *
 * Notes:
 *    1.  The radius of convergence is only 1.  So the series converges
 *        *very* slowly.
 *    2. factor is now a private variable and pi calculation is now robust. 
 */        

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <omp.h> 

#define NUM_THREADS 2 // change this number to test
#define STEPS 100000000

int main(int argc, char* argv[]) {
   long long n, i;
   double factor;
   double sum = 0.0;

   n = STEPS;

    omp_set_num_threads (NUM_THREADS);
    double start_time = omp_get_wtime (); // get current wall clock time

// The private clause specifies that for each variable listed inside the parantheses, 
// a private copy is to be created for each thread
#  pragma omp parallel for reduction(+: sum) private(factor)
   for (i = 0; i < n; i++) {
      factor = (i % 2 == 0) ? 1.0 : -1.0;   // factor is now a private variable and it's value doesn't depend on previous value
      sum += factor/(2*i+1);
   }
   
   double end_time = omp_get_wtime (); 

   sum = 4.0*sum;
   std::cout << "   With n = " << n << " terms and " << NUM_THREADS << " threads" << std::endl;
   std::cout.precision(14);
   std::cout << "   Our estimate of pi = " << sum << std::endl;
   std::cout.precision(14);
   std::cout << "                   pi = " << 4.0*atan(1.0) << std::endl;
   std::cout << "   Time: " << end_time - start_time << " seconds to run parallel region." << std::endl;
   return 0;
}  /* main */

