// Compilation: g++ -o p pow_test.cpp
#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

#define pow3(x) ((x)*(x)*(x))

int main(){
  double x = 2.;
  double a=0.,time=0.;
  high_resolution_clock::time_point begin, end;

  cout << scientific << setprecision(2);
  
  begin = high_resolution_clock::now(); // Start the timer
  a = x*x*x;
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count(); 
  cout << "Time for x*x*x = " << time  <<" ns" << endl;

  begin = high_resolution_clock::now(); // Start the timer
  a = pow(x,3);
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count(); 
  cout << "Time for pow(x,3) = " << time  <<" ns" << endl;
  
  begin = high_resolution_clock::now(); // Start the timer
  a = pow3(x);
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count(); 
  cout << "Time for pow3(x) = " << time  <<" ns" << endl;
  
  return 0;
}
