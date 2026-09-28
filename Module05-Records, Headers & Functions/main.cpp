#include <iostream>
#include <vector>
#include "record_tools.h"
using namespace std;

int main() {
    vector<record> records;

    show_message();

    add_record(records, "alvin", 3.5);
    add_record(records, "john", 2.75);
    add_record(records, "ken", 1.25);

    display_records(records);

    cout << "\naverage score: " << calculate_average(records) << endl;
    return 0;
}