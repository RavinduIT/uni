#include <iostream>
#include <string> //for string class
#include <cmath> //for math functions

using namespace std;

int main () {
    int x;

    cout << "first line\n";
    cout << 3 + 3 << endl ;
    cout << "Hutta" << endl;
    cout << "I'm \"Ravindu\"";
    cout << "I'm \'Ravindu\'";
    
    //comment
    /*comment*/
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    string name = "Ravindu";
    cout << name << endl;

    // string concatenation
    string firstName = "Ravindu";
    string lastName = "Lakshan";
    string fullName = firstName + " " + lastName;
    //string fullName = firstName.append(lastName);
    cout << fullName << endl;

    //string length
    cout << fullName.length() << endl;
    //cout << fullName.size() << endl;

    //accessing string elements
    cout << fullName[0] << endl;

    //changing string elements
    fullName[0] = 'K';
    cout << fullName << endl;

    //user input string 
    string name1;
    cout << "Enter your name: ";
    cin >> name1; //only get the first word
    getline(cin, name1); //get the whole line
    cout << "Your name is: " << name1 << endl;

    //Math
    cout << max(5,10) << endl;   // max out of two numbers
    cout << min(5,10) << endl;   // min out of two numbers
    cout << sqrt(64) << endl;    // square root
    cout << round(2.6) << endl;  // round off
    cout << log(2) << endl;      // logarithm

    int time = 20;
    string result = (time < 18) ? "Good day." : "Good evening.";
    cout << result;

    


    return 0;
    
}