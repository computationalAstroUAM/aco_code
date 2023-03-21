// gcc -o p -fopenmp hello_openmp_sch.c 
#include <stdio.h>
#include <omp.h>

void main(){
  omp_set_dynamic(0); // Disable dynamic adjustment of number of threads
  omp_set_num_threads(omp_get_num_procs()); // Request as many threads as processors
#pragma omp parallel 
  {
    int nthreads = omp_get_num_threads(); // returns number of threads
    int ID = omp_get_thread_num(); // returns the thread number
    printf("Hello world from thread %d out of %d \n", ID, nthreads); 
  }
}
  
