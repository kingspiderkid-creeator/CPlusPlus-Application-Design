#include <iostream>
using namespace std;

int main() {
    // declaring arrays
    string names[3] = { "alvin", "john", "ken" }; // name examples
    string lang[3] = { "Cpp","Go","Python" }; // coding language
    int diff[3] = { 5, 3, 1 }; // 1-5 easiest to hardest

    // pointer for each array
    string* namesPtr = &names[0];
    string* langPtr = &lang[0];
    int* diffPtr = &diff[0];

    for (int i = 0; i < 3;i++) {
        cout << names[i] << " uses " << lang[i] << " to code which has a " << diff[i] << "/5 difficulty rating" << endl;
    }

    cout << *namesPtr << " uses " << *langPtr << " it has a " << *diffPtr << "/5 difficulty rating" << endl;

    return 0;
}
