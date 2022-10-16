#include<iostream>
using namespace std;

class metro {
    public:
    char a;
    int b;
};


int main () {
  
   metro faiz;
   cout<<sizeof(faiz.a)<<endl;
   cout<<sizeof(faiz.b)<<endl;
   cout<<sizeof(faiz)<<endl;
}