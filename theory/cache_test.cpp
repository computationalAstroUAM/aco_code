// Compilation diabling optimisations: g++ -O0 -o p cache_test.cpp
#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
#include <random>  // Library to produce random numbers
#include <vector>  // For avoiding stack overflow issues with large arrays

using namespace std;
using namespace chrono;

int main(){
  int i=0, j=0;
  double time=0.;
  high_resolution_clock::time_point begin, end;
  
  int nrow=10000, ncol=10000; // Large enough array to see cache misses properly
  vector<vector<int>> DD(nrow, vector<int>(ncol, 0));

  cout << scientific << setprecision(2);

  // Pre-generate random numbers following a uniform dis. between 0 and 99
  random_device rd;  // Seed generator
  mt19937 gen(rd()); // Mersenne Twister engine
  uniform_int_distribution<int> distribution(0, 99);
  vector<vector<int>> randomNumbers(nrow, vector<int>(ncol, 0));
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      randomNumbers[i][j] = randomNumbers[i][j];
    }
  }
    
  // Populate array in reverse order and bad data alligment, with random numbers
  begin = high_resolution_clock::now(); // Start the timer
  for (j=ncol-1; j>=0; j--){
    for(i=nrow-1; i>=0; i--){
      DD[i][j]= randomNumbers[i][j];
    }
  }
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count();   
  cout << time  <<" ns for reversed and bad data alligment loop" << endl;

  // Populate array in reverse order and good data alligment
  begin = high_resolution_clock::now(); // Start the timer
  for (i=nrow-1; i>=0; i--){
    for(j=ncol-1; j>=0; j--){
      DD[i][j]= randomNumbers[i][j];
    }
  }
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count();   
  cout << time  <<" ns for reversed and good data alligment loop" << endl;

  // Populate array with bad data alligment, with random numbers
  begin = high_resolution_clock::now(); // Start the timer
  for (j=0; j<ncol; j++){
    for(i=0 ; i<nrow ;i++){
      DD[i][j]= randomNumbers[i][j];
    }
  }
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count();
  cout << time  <<" ns for bad data alligment loop" << endl;  

  // Populate array with good data alligment, with random numbers
  begin = high_resolution_clock::now(); // Start the timer
  for (i=0; i<nrow; i++){
    for(j=0 ; j<ncol; j++){
      DD[i][j]= randomNumbers[i][j];
    }
  }
  end = high_resolution_clock::now();   // End the timer
  time = duration_cast<nanoseconds>(end - begin).count();
  cout << time  <<" ns for good data alligment loop" << endl;  
  
  return 0;
}
