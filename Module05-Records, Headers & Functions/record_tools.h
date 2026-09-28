    // record_tools.h
#ifndef record_tools_h
#define record_tools_h

#include <string>
#include <vector>

struct record {
    std::string name;
    double score;
};

void show_message();
void add_record(std::vector<record>& records, const std::string& name, double score);
void display_records(const std::vector<record>& records);
double calculate_average(const std::vector<record>& records);

#endif