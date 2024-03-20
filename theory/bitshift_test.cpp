// Compilation: g++ -o p bitshift_test.cpp 
#include <iostream>
using namespace std;

int main() {
   int a=9;
   cout << "a     = " << a << endl;
   cout << "a<<1  = " << (a<<1) << endl;
   cout << "a<<2  = " << (a<<2) << endl;
   cout << "a>>1  = " << (a>>1) << endl;
   cout << "a>>10 = " << (a>>10) << endl;
   
   return 0;
}
