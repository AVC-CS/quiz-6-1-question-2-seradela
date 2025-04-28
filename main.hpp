#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writeFile(const string &filename);
int readFile(const string &filename);

int writeFile(const string &filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open file for writing" << endl;
        return 0;
    }

    int empCount = 3;
    file << empCount << endl;
    file << "10981011 John Computer 100000" << endl;
    file << "10981012 Johny Network 110000" << endl;
    file << "10981013 Johnn HR 90000" << endl;

    file.close();
    return empCount;
}

int readFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file for reading" << endl;
        return 0;
    }

    int empCount;
    file >> empCount;
    file.ignore(); // To skip newline after the count

    string line;
    for (int i = 0; i < empCount; ++i) {
        getline(file, line); // read employee lines but ignore contents
    }

    file.close();
    return empCount;
}