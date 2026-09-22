#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ProgrammingLanguage {
    string language;
    string difficulty;
    int popularity;
    string use_cases;
    int year_created;
};

int main() {
    ifstream file("programming_languages.csv");
    if (!file.is_open()) {
        cout << "cant open" << endl;
        return 1;
    }

    vector<string> languages;
    vector<string> difficulties;
    vector<int> popularities;
    vector<string> use_cases_list;
    vector<int> years_created;

    vector<ProgrammingLanguage> tempRecords;
    string line;

    // skip header 
    getline(file, line);

    // read file
    while (getline(file, line)) {
        stringstream ss(line);
        string language, difficulty, popularity_str, use_cases, year_created_str;

        if (getline(ss, language, ',') &&
            getline(ss, difficulty, ',') &&
            getline(ss, popularity_str, ',') &&
            getline(ss, use_cases, ',') &&
            getline(ss, year_created_str, ',')) {

            ProgrammingLanguage pl;
            pl.language = language;
            pl.difficulty = difficulty;
            pl.popularity = stoi(popularity_str);
            pl.use_cases = use_cases;
            pl.year_created = stoi(year_created_str);

            tempRecords.push_back(pl);
        }
    }
    file.close();

    // sort by popularity
    sort(tempRecords.begin(), tempRecords.end(), [](const ProgrammingLanguage& a, const ProgrammingLanguage& b) {
        return a.popularity > b.popularity;
        });

    // move data into individual arrays
    for (const auto& rec : tempRecords) {
        languages.push_back(rec.language);
        difficulties.push_back(rec.difficulty);
        popularities.push_back(rec.popularity);
        use_cases_list.push_back(rec.use_cases);
        years_created.push_back(rec.year_created);
    }

    // display records
    cout << "records" << endl;
    for (size_t i = 0; i < languages.size(); ++i) {
        cout << languages[i] << ", "
            << difficulties[i] << ", "
            << popularities[i] << ", "
            << use_cases_list[i] << ", "
            << years_created[i] << endl;
    }

    // Pointer demonstration
    string* ptr = &languages[0]; // Point to first element
    cout << "First language is: " << *ptr << endl;

    return 0;
}
