#include <iostream>
#include "securityStudent.h"

using namespace std;

SecurityStudent::SecurityStudent() {
    setDegree(SECURITY);
}

SecurityStudent::SecurityStudent(string id, string firstName, string lastName, string emailAddress, int age, int *numberDays,
                                 Degree degree) {
    setDegree(SECURITY);
}

Degree SecurityStudent::getDegree() {
    return SECURITY;
}


void SecurityStudent::setDegree(Degree d) {
    this->degree = SECURITY;
}


void SecurityStudent::print() {
    this->Student::print();
    cout << "SECURITY" << "\n";
}


SecurityStudent::~SecurityStudent() {
    Student::~Student();
    delete this;
}