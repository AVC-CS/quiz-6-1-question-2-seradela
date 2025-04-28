#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int writeFile(string filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cout << "File Open Error\n";
        exit(1);
    }

    int numEmployees = 3;
    ofs << numEmployees << endl;

    // Hardcoded employee data for testing
    ofs << "10981011 John Computer 100000" << endl;
    ofs << "10981012 Johny Network 110000" << endl;
    ofs << "10981013 Johnn HR 90000" << endl;

    ofs.close();
    return numEmployees;
}

int readFile(string filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "File Open Error\n";
        exit(1);
    }

    int numEmployees;
    ifs >> numEmployees;

    int id;
    string name, department;
    double salary, totalSalary = 0;

    cout << left << setw(15) << "ID"
         << setw(15) << "Name"
         << setw(15) << "Department"
         << "Salary" << endl;

    for (int i = 0; i < numEmployees; i++) {
        ifs >> id >> name >> department >> salary;
        cout << left << setw(15) << id
             << setw(15) << name
             << setw(15) << department
             << fixed << setprecision(0) << salary << endl;

        totalSalary += salary;
    }

    double avg = totalSalary / numEmployees;
    cout << "\nTotal Salary: " << totalSalary << " | Average Salary: " << avg << endl;

    ifs.close();
    return numEmployees;
}

#endif