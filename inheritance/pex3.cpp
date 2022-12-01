#include<iostream>
using namespace std;

class pointType {
    int x,y;
    public:
    pointType();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void DisplayXY();

};

pointType::pointType() {
    x = y = 0;
}

void pointType::setX(int x) {
    this->x = x;
}

void pointType::setY(int y) {
    this->y = y;
}

void pointType::DisplayXY() {
    cout<<" Here Are The Coordinates \n";
    cout<< " x,y => "<<x<<","<<y<<endl;
}

int pointType::getX() {
    return x;
}

int pointType::getY() {
    return y;
}


int main () {

pointType coordinates;
coordinates.DisplayXY();
cout<<" Do You Wanna Set The Coordinates? \n";
cout<<" n or y \n"<<endl;
char choise = 'n';
cin>>choise;
if(choise == 'y') {
    int x,y;
    cout<<"Type value of X \n";
    cin>> x;
    cout<<"Type value of Y \n";
    cin>>y;
    coordinates.setX(x);
    coordinates.setY(y);
    coordinates.DisplayXY();
}
   else {
      cout<<" As You Wish.. BYE \n";
   }
}