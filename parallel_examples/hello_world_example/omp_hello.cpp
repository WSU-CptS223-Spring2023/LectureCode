/* File:     omp_hello.cpp
 *
 * Purpose:  A parallel hello, world program that uses OpenMP
 *
 * Compile:  g++ -g -Wall -fopenmp -o omp_hello omp_hello.cpp
 * Run:      ./omp_hello <number of threads>
 * 
 * Input:    none
 * Output:   A message from each thread
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>   
#include <thread>

void Hello(void);  /* Thread function */

/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   int thread_count = 0;
   //Get the total number of cores in the system
   const auto processor_count = std::thread::hardware_concurrency();

   printf("The CPU has %d cores! \n" , processor_count);

   // If the number of threads is not provided as a command line argument, use the "number of cores" by default. 
   if (argc != 2) // the number of threads is not provided 
      thread_count = processor_count;
   else 
      thread_count = strtol(argv[1], NULL, 10);
   
   omp_set_num_threads(thread_count);
   // or add num_threads(thread_count) to the following pragma directive 

   // Begin of parallel region 
   # pragma omp parallel 
   Hello();

   return 0; 
}  /* main */

/*-------------------------------------------------------------------
 * Function:    Hello
 * Purpose:     Thread function that prints message
 */
void Hello(void) {
   int my_rank = omp_get_thread_num();  // getting the current thread's number
   int thread_count = omp_get_num_threads(); // total number of threads

   printf("Hello from thread %d of %d\n", my_rank, thread_count);

}  /* Hello */
