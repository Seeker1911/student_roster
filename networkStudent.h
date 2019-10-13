#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

class NetworkStudent : public Student {
public:
    NetworkStudent();

    NetworkStudent(string id, string firstName, string lastName, string emailAddress, int age, int *numberDays, Degree degree);

    Degree getDegree();

    void setDegree(Degree d);

    void print();

    ~NetworkStudent();
};

#endif