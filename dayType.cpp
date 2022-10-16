#include <iostream>
#include<string>
#include<cmath>
using namespace std;

class dayType
{
   char day[9];

public:
   string setDay(char[]);
   void getDay();
   string nextDay(char[], string allDays[]);
   string prevDay(char[], string allDays[]);
   string futureDay(char[], string allDays[], int);
};

string dayType::setDay(char d[])
{
   for (int i = 0; i < 9; i++)
   {
      day[i] = d[i];
   }
   return day;
}

void dayType::getDay()
{
   cout << day << endl;
}

string dayType::nextDay(char d[], string allDays[])
{
   for (int i = 0; i < 7; i++)
   {
      if (d == allDays[6])
         return allDays[0];
      if (d == allDays[i])
         return allDays[i + 1];
   }
      return "INVALID";
}

string dayType::prevDay(char d[], string allDays[])
{
   for (int i = 0; i < 7; i++)
   {
      if (d == allDays[0])
         return allDays[6];
      if (d == allDays[i])
         return allDays[i - 1];
   }
     return "INVALID";
}

string dayType::futureDay(char d[], string allDays[],int next) {
       for(int i = 0; i < 7; i++) {
         if(d == allDays[i]) {
            next = i + next;
         }
       } 
          next = sqrt((next * next));
          next = next % 7;
          return allDays[next];
}


int main()
{
   string allDays[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
   cout << "give me day " << endl;
   char d[9];
   cin >> d;
   dayType d1{};
   d1.setDay(d);
   d1.getDay();
   cout << "the next day is " << d1.nextDay(d, allDays) << endl;
   cout << "the previous day was  " << d1.prevDay(d, allDays) << endl;
   cout<<endl<<endl;
   cout<<" how many days in future or in past? type number "<<endl;
   int next = 0;
   cin>>next;
   cout<<"that day is "<<d1.futureDay(d,allDays,next) <<endl;

   return 0;
}