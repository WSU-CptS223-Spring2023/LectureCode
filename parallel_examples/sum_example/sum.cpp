
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

int *create_array (int num);
int sum_array (int *pIntegers, int num_elements);

int main (int argc, char *argv[])
{


    return 0;
}


int *create_array (int num)
{
    return new int[num];
}

int sum_array (int *pIntegers, int num_elements)
{
    int sum = 0;
    // how could parallelization help here?
    // we could have separate threads run
    // the for () loop on differents chunks
    // of the same array. If we have 4 threads,
    // we could have each thread run the loop
    // on 1/4 of the elements in the array.
    for (int index; index < num_elements; ++index)
    {
        sum += pIntegers[index];
    }

    return sum;
}