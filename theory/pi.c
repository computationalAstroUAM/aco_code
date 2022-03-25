// gcc -o p -fopenmp serial_2a.c
#include <stdio.h>

void main(){
  int N = 10;
  float STARTVALUE = 0.7;
  float a[N];

  a[0] = STARTVALUE;
  
  for(int i=1; i<N; i++){
    a[i] = 2*a[i-1];
  }

  printf("\n Results:\n");  
  for(int i=0; i<N; i++){
    printf("a[%d]=%.1f \n",i,a[i]);
  }
}
  
