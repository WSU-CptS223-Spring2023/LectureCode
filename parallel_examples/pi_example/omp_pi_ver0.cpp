/* File:     omp_pi_ver0.cpp
 * Purpose:  Estimate pi using OpenMP and the formula - serial solution
 *
 *              pi = 4*[1 - 1/3 + 1/5 - 1/7 + 1/9 - . . . ]
 *
 * Compile:  	g++ -g -Wall -fopenmp -o omp_pi omp_pi_ver0.cpp

 *
 * Notes:
 *    1.  The radius of convergence is only 1.  So the series converges
 *        *very* slowly.
 *

 */        

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <omp.h> 

#define STEPS 100000000

int main(int argc, char* argv[]) {
   long long n, i;
   double factor;
   double sum = 0.0;

   n = STEPS;
   factor = 1.0;
   double start_time = omp_get_wtime (); // get current wall clock time

   for (i = 0; i < n; i++) {
      sum += factor/(2*i+1);
      factor = -factor;  

   }
   
   double end_time = omp_get_wtime (); 

   sum = 4.0*sum;
   std::cout.precision(14);
   std::cout << "   Our estimate of pi = " << sum << std::endl;
   std::cout.precision(14);
   std::cout << "                   pi = " << 4.0*atan(1.0) << std::endl;
   std::cout << "   Time: " << end_time - start_time << " seconds to run parallel region." << std::endl;
   return 0;
}  /* main */

