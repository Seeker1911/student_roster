#include <iostream>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent() {
    setDegree(NETWORKING);
}

NetworkStudent::NetworkStudent(string id, string firstName, string lastName, string emailAddress, int age, int *numberDays,
                               Degree degree) {
    setDegree(NETWORKING);
}

Degree NetworkStudent::getDegree() {
    return NETWORKING;
}


void NetworkStudent::setDegree(Degree d) {
    this->degree = NETWORKING;
}


void NetworkStudent::print() {
    this->Student::print();
    cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent() {
    Student::~Student();
    delete this;
}