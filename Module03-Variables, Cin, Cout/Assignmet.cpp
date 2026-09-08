#include <iostream>
#include <string>
using namespace std;

int main() {
    // Main C++ variable types

    int age = 0;                    // whole number
    double numGrade = 0.0;            // decimal number
    float salary = 0.0;       // decimal number
    char grade = 'F';                // single character
    bool employed = false;            // true or false
    string name = "idk";            // text

    // record uer date
    cout << "tell me about yourself" << endl;
    cout << "Name: " << endl;
    getline(cin, name);
    cout << "Age: " << endl;
    cin >> age;
    cout << "Grade%: " << endl;
    cin >> numGrade;
    cout << "Weekly Salary: " << endl;
    cin >> salary;
    cout << "Grade: " << endl;
    cin >> grade;
    cout << "Employed?: (true/false)" << endl;
    cin >> boolalpha >> employed;

    // print user data
    cout << boolalpha;
    cout << "heres what i know about you so far!" << endl;
    cout << "Your name is " << name << " and you're " << age << " years old! " << "Your weekly salary is " << salary << ".";
    cout << " Your grade is " << numGrade << "%." << " Your grade letter is " << grade << ". " << "Employed: " << employed << endl;

    return 0;
}
