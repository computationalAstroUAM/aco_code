// Compilation: g++ -o p -fopenmp hello_openmp_sch.cpp 
#include <iostream>
#include <omp.h> // Include the OpenMP library

using namespace std;

int main(){
  omp_set_dynamic(0); // Disable dynamic adjustment of number of threads
  omp_set_num_threads(omp_get_num_procs()); // Request as many threads as processors
  #pragma omp parallel 
  {
    int nthreads = omp_get_num_threads(); // returns number of threads
    int ID = omp_get_thread_num(); // returns the thread number

    string outm = "Hello world from thread " + to_string(ID) +
      " out of " + to_string(nthreads); 
    cout << outm << endl;    
  }

  return 0;
}
  
