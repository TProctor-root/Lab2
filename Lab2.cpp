#include <iostream>
#include <string>
using namespace std;

class Director {
    private:
        string directorFirst;
        string directorLast;
        int directorBirth;
        int directorFilms;
    public:
        void setDirector(string a, string b, int c, int d) {
            directorFirst = a;
            directorLast = b;
            directorBirth = c;
            directorFilms = d;
        }
        int getBirth() {
            return directorBirth;
        }
        int getFilms() {
            return directorFilms;
        }
        string getFirst() {
            return directorFirst;
        }
        string getLast() {
            return directorLast;
        }
        void incrementFilm() {
            directorFilms = directorFilms + 1;
        }
};

class Movie {
    private:
        int movieMintutes;
        int movieReleased;
        double moviePrice;
        string movieTitle;
        Director two;
    public:
        void setTwo(Director nTwo) {
            two = nTwo;
        }
        Director getTwo() const {
            return two;
        }

        void setValues(int a, int b, double c, string d, string e, string f, int g, int h) {
            movieMintutes = a;
            movieReleased = b;
            moviePrice = c;
            movieTitle = d;
            two.setDirector(e, f, g, h);
        }
        int getMinute() {
            return movieMintutes;
        }
        int getReleased() {
            return movieReleased;
        }
        double getPrice() {
            return moviePrice;
        }
        string getTitle() {
            return movieTitle;
        }
        void print(Movie one) {
            cout << "Title: " << one.getTitle() << " Published in: " << one.getReleased()  << endl;
            cout << "Duration of Movie: " << one.getMinute() << " minutes" << endl;
            cout << "Price: $" << one.getPrice() << endl;
            one.printDirectorInfo();
        }
        void printDirectorInfo() {
            cout << "Directed by " << two.getFirst() << " " << two.getLast();
            cout << ", who was born in " << two.getBirth() << " and has " << two.getFilms() << " releases.";
            cout << endl << endl;
        }
        void incrementFilm() {
            two.incrementFilm();
        }
};

int main () {
    Movie one;
    one.setValues(330, 2000, 19.99, "Harry Potter and the Goblet of Fire", "J.K", "Rowling", 1965, 7);
    
    cout << "Default Movie" << endl;
    one.print(one);
    
    cout << "-----------------------------------------------------------" << endl << endl;
    
    Movie copy = one;
    cout << "Copied Movie" << endl;
    copy.print(copy);
    
    cout << "Default Movie" << endl;
    one.print(one);
    
    cout << "-----------------------------------------------------------" << endl << endl;
    
    copy.incrementFilm();
    cout << "Incremented Movie" << endl;
    copy.print(copy);
    
    cout << "Default Movie" << endl;
    one.print(one);
    
    return 0;
}