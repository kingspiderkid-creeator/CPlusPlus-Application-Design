#include <iostream>
#include <iomanip>
#include "record_tools.h"
using namespace std;

void show_message() {
    cout << "record system ready!" << endl;
}

// adds a new record to the end of the list
void add_record(vector<record>& records, const string& name, double score) {
    records.push_back({name, score});
}

// prints every record in a numbered list
void display_records(const vector<record>& records) {
    if (records.empty()) {
        cout << "no records to display." << endl;
        return;
    }
    cout << "\n--- records ---" << endl;
    for (size_t i = 0; i < records.size(); ++i) {
        cout << i + 1 << ". " << left << setw(10) << records[i].name
             << fixed << setprecision(1) << records[i].score << endl;
    }
}

// returns the average score (0 if there are no records)
double calculate_average(const vector<record>& records) {
    if (records.empty()) return 0.0;
    double total = 0;
    for (const record& r : records) total += r.score;
    return total / records.size();
}