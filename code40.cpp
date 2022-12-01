#include<iostream>
using namespace std;

// class shape {
//     public:
//      void draw() {
//         cout<<"shape draw is called \n";
//      }
// };

class tri: public shape{
    public:
     void  draw() {
        cout<<"tri draw is called \n";
     }
};

class rec:public shape {
    public:
     void  draw() {
        cout<<"rect draw is called \n";
     }
};

int main () {
    shape s1;
    s1.draw();
//    shape * ptr[2];
//    tri t1;
//    rec r1;
//    ptr[0] = & t1;
//    ptr[1] = &r1;

//    for(int i = 0; i < 2; i++) {
//     ptr[i]->draw();
//    }


}