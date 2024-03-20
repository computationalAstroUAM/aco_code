// Compilation: g++ -o p serial_b.cpp
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int main(){
  float STARTVALUE = 2.;
  
  int N = 10;
  float a[N]={0.};

  double walltime=0.;
  high_resolution_clock::time_point begin, end;
  begin = high_resolution_clock::now(); // Start the walltimer

  // Populate the vector a
  a[0] = STARTVALUE;  
  for(int i=1; i<N; i++){
    double b = a[0];
    for(int j=0; j<i; j++){
      b = 2*b ;
    }
    a[i] = b;
  }

  // Measure the walltime
  end = high_resolution_clock::now();   // End the walltimer
  walltime = duration_cast<nanoseconds>(end - begin).count();
  cout << scientific << setprecision(2);
  cout << endl << walltime*1e-6  <<" ms running the code" << endl;  

  
  // Print the results
  cout << fixed << setprecision(0);
  cout << endl << "Vector a: " << endl;  
  for(int i=0; i<N; i++){
    cout << "a[" << i << "] = " << a[i] << endl;
  }

  return 0;
}
  
