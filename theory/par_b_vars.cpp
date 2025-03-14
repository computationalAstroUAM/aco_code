// Compilation: g++ -o p -fopenmp par_b_vars.cpp
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

  // Wall time
  double walltime=0.;
  high_resolution_clock::time_point begin, end;
  begin = high_resolution_clock::now(); // Start the timer
  double start_omp = omp_get_wtime(); // OpenMP time
  
  // Populate the vector a
  a[0] = STARTVALUE;
  int i,j;
  float b;
#pragma omp parallel private(a,N) shared(i,j,b) 
  {
    int ID = omp_get_thread_num();
    # pragma omp for 
    for(int i=1; i<N; i++){
      b = a[0];
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
  double end_omp = omp_get_wtime(); // OpenMP time
  end = high_resolution_clock::now();   // End the timer

  double timeomp = end_omp - start_omp; //seconds OpenMP
  walltime = duration_cast<nanoseconds>(end - begin).count();
  cout << endl << "Chrono wall time = " << walltime  <<" ns" << endl;
  cout << "OpenMP wall time = " << timeomp*1e9   <<" ns" << endl;

  // Print the results
  cout << fixed << setprecision(0);
  cout << endl << "Vector a: " << endl;  
  for(int i=0; i<N; i++){
    cout << "a[" << i << "] = " << a[i] << endl;
  }

  return 0;
}
  
