#include <iostream>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent() {
    setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string id, string firstName, string lastName, string emailAddress, int age, int *numberDays,
                                 Degree degree) {
    setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegree() {
    return SOFTWARE;
}


void SoftwareStudent::setDegree(Degree d) {
    this->degree = SOFTWARE;
}


void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
    delete this;
}