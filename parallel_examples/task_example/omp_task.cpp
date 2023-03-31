// CptS 223 - What happens to the time required to
// run these programs when NUM_THREADS is set to 1, then 2,
// then up to the max cores on your system? The time should
// decrease as you increase your NUM_THREADS. Does this happen?

// Remember OpenMP is a multi-threading, shared address model

#include <iostream>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 2 // change this number to test

int task1 ();
int task2 (int num);

int main (int argc, char *argv[])
{
    int num = 0;

    omp_set_num_threads(NUM_THREADS);

    double time = omp_get_wtime ();


    #pragma omp parallel shared (num) // can use private so each thread gets a copy
    {
        // for emphazing critical - 
        // only 1 task can execute that region at a time
        #pragma omp critical 
        {       
             std::cout << omp_get_num_threads () << " threads are running."\
            << std::endl;
        }
        // if NUM_THREADS is 2, 
        // only 1 thread will run this region
        #pragma omp single // what happens if we replace single with multiple 
        {
            // tasks can execute in any order. they are scheduled.
            // the depend below says other tasks may be dependent on what this task produces specifically num;
            // be careful because tasks become serialized here
            #pragma omp task depend (out: num) // what happens if depend is removed?
            {
                num = task1 ();
                std::cout << "thread id: " << omp_get_thread_num () << \
                 " executing task 1" << std::endl;
            }
            // the depend below says this task is dependent on or a consumer of num
            #pragma omp task depend (in: num) // what happens if depend is removed?
            {
                num = task2 (num);
                 std::cout << "thread id: " << omp_get_thread_num () << \
                 " executing task 2" << std::endl;
            }
            #pragma omp taskwait // what happens if this is removed?
            // if taskwait is removed then the output of num
            // could happen in some arbitrary order
            std::cout << "num: " << num << std::endl;
        }

        // what happens if this cout stay outside of omp single
        // std::cout << "num: " << num << std::endl;
    }

    std::cout << "time parallel region: " << \
     omp_get_wtime () - time << " seconds." << std::endl;

    return 0;
}

int task1 ()
{
    return 1;
}

int task2 (int num)
{
    return num + 1;
}