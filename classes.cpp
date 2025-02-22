#include <iostream>

using namespace std;

class date {
    private:
        int day;
        int month;
        int year;
    
    public:
        void setdate(int d, int m, int y) {
            day = d;
            month = m;
            year = y;
        }
        /*
        date(int d, int m, int y) {
            day = d;
            month = m;
            year = y;
        }
        */
        void printDate() {
            cout << day << "/" << month << "/" << year << endl;
        }
};

/*
void date::printDate() {
    cout << day << "/" << month << "/" << year << endl;
}

void date::setdate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

date::date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
    :: - scope resolution operator
*/

int main () {

    date today;
    today.setdate(10, 12, 2020);
    today.printDate();


}