#include<iostream>
using namespace std;

class Building {
   public:
   int rooms,floors;
   public:
   Building() {
       rooms = floors = 0;
   } 
   void setRooms(unsigned int r){
         rooms = r;
   } 
   void setFloors(unsigned int f) {
        floors = f;
   } 
   unsigned int getRooms() {
        return rooms;
   }
   unsigned int getFloors() {
         return floors;
   } 
 
};

// House is Inheritade from Building....

class House:private Building {
    unsigned int bedrooms,bathrooms;
    public:
    House() {
         bedrooms = bathrooms = 0;
    }
    void setBedRooms(unsigned int br) {
        bedrooms = br;
    } 
    void setBathRooms(unsigned int bt) {
         bathrooms = bt;
    } 
    unsigned int getBedRooms() {
        return bedrooms;
    } 
    unsigned int getBathRooms() {
        return bathrooms;
    } 
};

void showBuilding(Building b1) {
    cout<<"Rooms : "<< b1.rooms<<endl;
    cout<<"Floors : "<< b1.floors<<endl;
}

int main() {
    Building Cblock;
    House myHouse;
    showBuilding(myHouse);
}

// when publically inherited , OutPut is Rooms : 0 , Floors : 0 as expected,
// when protected or privately inheritad, OutPut is Error As Seen In ScreenShot. 

