#include<iostream>
using namespace std;

void leckage() {
    long double *ptr = new long double[100000000];
     long double *ptr1 = new long double[100000000];
      long double *ptr2 = new long double[100000000];
    cout<<" I just forgot the address of array size 10000000 Sorry \n";
}

int main () {
    for(long int i = 0; i < 10000000000; i++) {
        if(i > 100000) {
            leckage();
        }
    }

//    while(1) leckage();
  return 0;
}