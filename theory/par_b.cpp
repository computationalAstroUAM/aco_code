// Compilation: g++ -o p -fopenmp par_b.cpp
#include <iostream>
#include <chrono>
#include <iomanip>
#include <omp.h> // Include the OpenMP library

using namespace std;
using namespace chrono;

int main(){
  float STARTVALUE = 2.;
  
  int N = 10;
  float a[N] = {0.};
  
  double walltime=0.;
  high_resolution_clock::time_point begin, end;
  begin = high_resolution_clock::now(); // Start the timer

  // Populate the vector a
  a[0] = STARTVALUE;
  #pragma omp parallel 
  {
    int ID = omp_get_thread_num();
    # pragma omp for
    for(int i=1; i<N; i++){
      float b = a[0];
      for(int j=0; j<i; j++){
	b = 2*b ;
      }
      a[i] = b;
      string outm = "Thread " + to_string(ID) + ": a[" + to_string(i) +
	"] = " + to_string(a[i]);
      cout << outm << endl; 
    }
  } // end of parallel section

  // Measure the wall time
  end = high_resolution_clock::now();   // End the timer
  walltime = duration_cast<nanoseconds>(end - begin).count();
  cout << scientific << setprecision(2);
  cout << endl << walltime  <<" ns running the code" << endl;  

  // Print the results
  cout << fixed << setprecision(0);
  cout << endl << "Vector a: " << endl;  
  for(int i=0; i<N; i++){
    cout << "a[" << i << "] = " << a[i] << endl;
  }
  
  return 0;
}
  
