#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Record {
    int id;
    string data;
    bool operator<(const Record& other) const { return id < other.id; }
};

class User {
protected:
    string username;
public:
    User(string name) : username(name) {}
    virtual bool isAdmin() const { return false; }
};

class Admin : public User {
public:
    Admin(string name) : User(name) {}
    bool isAdmin() const override { return true; }
};

// Binary Search
int binarySearch(const vector<Record>& records, int target) {
    int left = 0, right = records.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (records[mid].id == target) return mid;
        if (records[mid].id < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

class Database {
    vector<Record> records;
public:
    void addRecord(User* user, int id, string data) {
        if (!user->isAdmin()) {
            cout << "Access Denied.\n";
            return;
        }
        Record r{id, data};
        auto it = lower_bound(records.begin(), records.end(), r);
        if (it != records.end() && it->id == id) return; // Duplicate check
        records.insert(it, r);
    }

    void deleteRecord(User* user, int id) {
        if (!user->isAdmin()) {
            cout << "Access Denied.\n";
            return;
        }
        int idx = binarySearch(records, id);
        if (idx != -1) records.erase(records.begin() + idx);
    }

    int search(int id) const {
        return binarySearch(records, id);
    }
};

int main() {
    Database db;
    Admin admin("Alice");
    User regular("Bob");

    // Admin action succeeds
    db.addRecord(&admin, 102, "Data B");
    db.addRecord(&admin, 101, "Data A"); // Automatically sorted

    // Regular user action is blocked
    db.addRecord(&regular, 103, "Data C"); 

    // Search (O(log N))
    int foundIdx = db.search(101);
    cout << "Search result index: " << foundIdx << endl;

    return 0;
}
