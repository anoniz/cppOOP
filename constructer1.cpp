#include<iostream>
using namespace std;


class Distance {
   unsigned int feet;
   double inches;
  
public:
    void setFeet(int f);
    void setInches(double i);
    void getFeet();
    void getInches();
    void addDistances(Distance,Distance);
};

void Distance::setFeet(int f) {
        feet = f;
}

void Distance::setInches(double i) {
       inches = i;
}

void Distance::getFeet() {
    cout<<endl<<endl;
    cout<<"given feet are = "<<feet<<endl;
}

void Distance::getInches() {
    cout<<"given inches = " << inches<<endl;
}
   
void Distance::addDistances(Distance d1, Distance d2) {
    inches = d1.inches + d2.inches;
    feet = 0;
    if(inches >= 12.0) {
        inches-= inches;
        feet++;
    }
      feet+= d1.feet + d2.feet;

      cout<<endl<<endl;
      cout<<"the result is \n";
      cout<< "total feet = " << feet<<endl;
      cout<< "total inches = " << inches<<endl;
}


int main () {
  
 Distance d1,d2,d3;
 int f;
 double i;
 cout<<"give me feet "<<endl;
 cin>>f;
 cout<<"give me inches "<<endl;
 cin>>i;
 d1.setFeet(f);
 d1.setInches(i);
 d2.setFeet(f);
 d2.setInches(i);

 d1.getFeet();
 d1.getInches();
 d3.addDistances(d1,d2);



}