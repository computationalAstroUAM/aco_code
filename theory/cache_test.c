#include <stdio.h>
#include <stdlib.h> //Includes the rand() library
#include <time.h>

void main(){
  int i=0, j=0;
  double time=0.;
  clock_t begin, end;
  
  int nrow=2, ncol=3;
  double DD[2][3] = {{0.}};
  
  // Populate the array with random numbers from 0 to 99 with rand()%100
  begin = clock();
  
  // Get DD with an reversed loop
  for (j=ncol-1; j>=0; j--){
    for(i=nrow-1; i>=0; i--){
      DD[i][j]= rand()%100;
    }
  }
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; 
  printf("Time reversed loop =%E ms \n",time);
  
  begin = clock();
  // Get DD in the 'bad' way
  for (j=0; j<ncol; j++){
    for(i=0 ; i<nrow ;i++){
      DD[i][j]= rand()%100;
    }
  }
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; 
  printf("Time 'bad' way=%E ms \n",time);
  
  begin = clock();
  // Get DD in the 'good' way
  for(i=0 ; i<nrow ;i++){
    for (j=0; j<ncol; j++){
      DD[i][j]= rand()%100;
    }
  }
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; 
  printf("Time 'good' way=%E ms \n",time);
}
