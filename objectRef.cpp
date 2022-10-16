#include<iostream>
using namespace std;

class X {
    int x;
    int y;
    public:
    void set(int y) {
      this-> y = y;
    }

    void get() {
        cout<<" i am y " <<y<<endl;
    }
};


void setObj(X &num1) {
         num1.set(2);
}


int main () {
 
 X num1;
 setObj(num1);
 num1.get();


}