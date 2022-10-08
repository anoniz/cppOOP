#include<iostream>
#include<string>
using namespace std;

class Movie {
    string title;
    string director;
    unsigned int year;

public:
       	void setTitle(string);
        void setDirector(string);
	    void setYear(unsigned int);
        void displayMovie(string,string,unsigned int);
	    void compareMovies(Movie);

};

void Movie::setTitle(string t) {
        title = t;
}
void Movie::setYear(unsigned int y) {
        year = y;

}
void Movie::setDirector(string d) {
      director = d;
}

void Movie::displayMovie(string,string,unsigned int) {

        cout<<"Title == "<<title<<endl;
        cout<<"Director == "<<director<<endl;
        cout<<"Released in year == "<<year<<endl;
        cout<<endl<<endl;
}

void Movie::compareMovies(Movie m1) {
         if(year == m1.year) {
            cout<<"both movies were released in same year "<<year<<endl;
            if(director == m1.director) {
                cout<<"both movies were also directed by "<<director<<endl;
            }
         }
            else if( director == m1.director) {
                 cout<<"the director of both movies is same "<<director<<endl;
                 cout<<"but wasn't released in same year "<<endl;
            }
}

int main () {
     
    string title;
    string director;
    unsigned int year;
    Movie m1 , m2;

    cout<<"enter movie 1 details "<<endl;
    cout<<"enter the title of movie "<<endl;
    cin.ignore();
    getline(cin,title);
    cout<<"enter the diretor name of moive "<<endl;
    cin.ignore();
    getline(cin,director);
    cout<<"enter the releasing year of movie "<<endl;
    cin>>year;
    m1.setTitle(title);
    m1.setDirector(director);
    m1.setYear(year);

    cout<<endl<<endl;
    cout<<"enter movie 2 details "<<endl;
    cout<<"enter the title of movie "<<endl;
    cin.ignore();
    getline(cin,title);
    cout<<"enter the diretor name of moive "<<endl;
    cin.ignore();
    getline(cin,director);
    cout<<"enter the releasing year of movie "<<endl;
    cin>>year;
    m2.setTitle(title);
    m2.setDirector(director);
    m2.setYear(year);

    m1.displayMovie(title,director,year);
    m2.displayMovie(title,director,year);

    m2.compareMovies(m1);





}