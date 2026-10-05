#include <iostream>
#include <string>
using namespace std;

class Cats {
private:
    string Name;
    string Breed;
    int Age;
    string Gender;

public:
    // constructor
    Cats(string catname, string catBreed, int catAge, string catGender) {
        Name = catname;
        Breed = catBreed;
        Age = catAge;
        Gender = catGender;
    };
    //member function to display information
    void addYear() {
        Age++;
    }
    void getKittyInfo() {
        cout << "Name: " << Name << endl;
        cout << "Breed: " << Breed << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
    }

    string getName() {
        return Name;
    }

};

int main() {

    Cats cat1("Momo", "American Shorthair", 3, "Female");
    Cats cat2("Lloyd", "American Shorthair", 1, "Male");

    cat1.getKittyInfo();
    cout << endl;
    cat2.getKittyInfo();
    cout << endl;
    cat1.addYear();
    cat1.getKittyInfo();
    cout << endl;
    cat2.addYear();
    cat2.getKittyInfo();

    return 0;
}