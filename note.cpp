#include <iostream>
#include <string> // For string class
#include <cmath>  // For math functions
#include <vector> // For vector (dynamic array)

using namespace std;

int main() {
    int x;

    cout << "First line\n";
    cout << 3 + 3 << endl;
    cout << "Hutta" << endl;
    cout << "I'm \"Ravindu\"" << endl;
    cout << "I'm \'Ravindu\'" << endl;

    // Comment examples
    // Single-line comment
    /* Multi-line comment */

    // Input integer
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    // String usage
    string name = "Ravindu";
    cout << name << endl;

    // String concatenation
    string firstName = "Ravindu";
    string lastName = "Lakshan";
    string fullName = firstName + " " + lastName;
    cout << fullName << endl;

    // String length
    cout << fullName.length() << endl;

    // Accessing string elements
    cout << fullName[0] << endl;

    // Changing string elements
    fullName[0] = 'K';
    cout << fullName << endl;

    // User input string
    string name1;
    cout << "Enter your name: ";
    cin >> name1;          // Only gets the first word
    cin.ignore();          // Clear the newline character
    getline(cin, name1);   // Get the whole line
    cout << "Your name is: " << name1 << endl;

    // Math functions
    cout << max(5, 10) << endl;   // Max of two numbers
    cout << min(5, 10) << endl;   // Min of two numbers
    cout << sqrt(64) << endl;    // Square root
    cout << round(2.6) << endl;  // Round off
    cout << log(2) << endl;      // Logarithm

    // Ternary operator
    int time = 20;
    string result = (time < 18) ? "Good day." : "Good evening.";
    cout << result << endl;

    // For-each loop
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for (int i : myNumbers) {
        cout << i << "\n";
    }

    // Vector (dynamic array)
    vector<int> myVector = {10, 20, 30, 40, 50};
    myVector.push_back(60);
    for (int i : myVector) {
        cout << i << "\n";
    }
    // read more abt vector here: https://www.geeksforgeeks.org/vector-in-cpp-stl/

    // Functions
    int sum(int a, int b) {
        return a + b;
    }
    cout << sum(5, 10) << endl;

    // structs  
    struct Person {
        string name;
        int age;
        double salary;
    };
    Person p1;
    p1.name = "Ravindu";
    p1.age = 20;
    p1.salary = 100000.00;
    cout << p1.name << " " << p1.age << " " << p1.salary << endl;

    // Pointers
    int myAge = 20;
    int* myPointer = &myAge;
    cout << myAge << endl;
    cout << myPointer << endl;
    cout << *myPointer << endl;

    // structures with functions
    struct Person1 {
        string name;
        int age;
        double salary;
        void print() {
            cout << name << " " << age << " " << salary << endl;
        }
    };
    Person1 p2;
    p2.name = "Ravindu";
    p2.age = 20;
    p2.salary = 100000.00;
    p2.print();

    

    return 0;
}
