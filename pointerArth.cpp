#include<iostream>
using namespace std;

class test {
    int a , b ,c;
    int *A = &c;
    public:
    void setABC(int a, int b, int c) {
       this -> a = a;
       this -> b = b;
       this -> c = c;
       A = A - 1;
    }
      void getABC() {
         cout<<&a<<"  "<<&b<<"  " << &c <<endl;
         cout<<"this is a with value "<<A<<endl;
      }
};

int main () {

  int a = 2, b = 4, c =11;
  
  test t1;
  t1.setABC(a,b,c);
  t1.getABC();


}