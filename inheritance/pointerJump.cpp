#include<iostream>
using namespace std;


void makeObj(int * nums, int &numCount) {
    for(int i = 0; i < 4; i++) {
    cout<<" Give Number You Wanna Add \n";
    cin>> *(nums+(numCount+1));
    numCount++;
    }
}

void loopNums(int *nums, int numCount) {
    cout<<" From Loop Nums \n";
    for(int i = 0; i <= numCount; i++) {
        cout<<" Num -> " << i+1<<" is "<< *(nums+i)<<endl;
    }
}

int main () {

 int *nums = new int;
 int *chk = new int;

 *(nums+2) = 2222;

 *chk = 5;
 int *chk1 = new int;
  *chk1 = 10;

 int numCount = -1;

 makeObj(nums, numCount);
 loopNums(nums, numCount);

 cout<<endl<<endl;
 cout<<*chk<<endl;
 cout<<*chk1<<endl;
 cout<<*(nums+2)<<endl;
 

}