// Compilation: g++ -o p -fopenmp hello_openmp.cpp 
#include <iostream>
#include <omp.h> // Include the OpenMP library

using namespace std;

int main(){
  #pragma omp parallel //Parallel region with default number of threads.
  {
    int nthreads = omp_get_num_threads(); // returns number of threads    
    int ID = omp_get_thread_num(); // returns the thread number
    
    string outm = "Hello world from thread " + to_string(ID) +
      " out of " + to_string(nthreads);       
    cout << outm << endl;
  }

  return 0;
}
