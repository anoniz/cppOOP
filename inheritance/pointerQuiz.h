#include<iostream>
using namespace std;

void magic(int *ptr) {                                                          
    int isPrime = 0;

 for(int j = 2; j <= 20; j++ ) {  
   for(int i = 2; i <= j/2; i++) {
    if(j % i == 0) {
      isPrime++;
    }
 }
  if(isPrime == 0) {
     *(ptr+j) = j+3;
      cout<<j+10<<endl;
  }
      isPrime = 0;
  }
}


          