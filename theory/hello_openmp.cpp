// g++ -o p -fopenmp hello_openmp.cpp 
#include <iostream>
#include <omp.h> // Include the OpenMP library

using namespace std;

int main(){
  #pragma omp parallel
  {
    int ID = omp_get_thread_num(); // returns the thread number
    
    string outm = "Hello world from thread " + to_string(ID); 
    cout << outm << endl;
  }

  return 0;
}
