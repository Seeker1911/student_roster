#include <iostream>
#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "roster.h"
#include "degree.h"


using namespace std;

/*
Michael Mead
Student ID: #000741802
C867 Scripting and Programming Applications
*/

Roster::Roster() {
    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student *[capacity];
}

void Roster::add(string row) {
    if (lastIndex < capacity) {
        lastIndex++;
        int numDaysArray[Student::num_days_size];

        if (row.substr(row.length() - 8, 8) == "SOFTWARE") {
            this->classRosterArray[lastIndex] = new SoftwareStudent();
            classRosterArray[lastIndex]->setDegree(SOFTWARE);
        } else if (row.substr(row.length() - 7, 7) == "NETWORK") {
            this->classRosterArray[lastIndex] = new NetworkStudent();
            classRosterArray[lastIndex]->setDegree(NETWORK);
        } else if (row.substr(row.length() - 8, 8) == "SECURITY") {
            this->classRosterArray[lastIndex] = new SecurityStudent();
            classRosterArray[lastIndex]->setDegree(SECURITY);
        }

        int rhs = studentData[lastIndex].find(",");
        classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

        int lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        numDaysArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        numDaysArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        numDaysArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

        classRosterArray[lastIndex]->setNumDays(numDaysArray);
    }
}


void Roster::remove(string id) {

    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] == nullptr) {
            cout << "error... student with ID: " << id << " not found" << endl;
            break;
        } else if (id == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            cout << "Student removed" << endl;
        }
    }

}

void Roster::printAll() {
    for (int i = 0; i <= this->lastIndex; i++) {
        (this->classRosterArray)[i]->print();
    }
}

void Roster::printAverageDays(string id) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (this->classRosterArray[i]->getStudentID() == id) {
            found = true;
            int *days = classRosterArray[i]->getNumDays();
            cout << "Average number of days per course for student id: " << id << ": "
                 << (days[0] + days[1] + days[2]) / 3 << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) ||
            (email.find(".") == string::npos)) {
            cout << "Email for student: " << classRosterArray[i]->getLastName() << ", "
                 << classRosterArray[i]->getFirstName() << " is invalid: " << email << endl;
        }
    }
}

void Roster::printDegree(Degree d) {
    cout << "Student roster by degree type: " << degreeTypeString[d] << "\n";
    for (int i = 0; i <= lastIndex; ++i) {
        if (this->classRosterArray[i]->getDegree() == d) this->classRosterArray[i]->print();
    }
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete this->classRosterArray[i];
    }
    delete this;
}


int main() {
    cout << "---------- Student Roster -------------" << endl;

    Roster *classRoster = new Roster(numStudents);
    for (int i = 0; i < numStudents; ++i) {
        classRoster->add(studentData[i]);
    }

    cout << "Roster:" << endl;
    classRoster->printAll();
    cout << endl;

    cout << "Invalid emails:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    cout << "Average days in course:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        classRoster->printAverageDays(classRoster->classRosterArray[i]->getStudentID());
    }
    cout << endl;

    classRoster->printDegree(SOFTWARE);
    classRoster->remove("A3");
    classRoster->remove("A3");
    cout << endl;


    //cin.get()
    system("pause");
    return 0;
}


