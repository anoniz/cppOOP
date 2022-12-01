#include<iostream>
using namespace std;

int main () {

int *num = new int;
  num = num+4;
 *num = 1042;
for(int i = 0; i < 10; i++) {
    num = num + i;
    cout<< *num<<endl;
}

}