#include<iostream>
using namespace std;

int main () {

int* num = new int;
*num = 5;
int num1 = *num;

num1++;

cout<<" i am num "<<*num<<endl;
cout<<&num<<endl;
cout<<"i am num1 "<<num1<<endl;

delete num;
num = NULL;
cout<<" i  am after delete "<<*num;

}