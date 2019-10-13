#ifndef SECURITY_H
#define SECURITY_H

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

class SecurityStudent : public Student {
public:
    SecurityStudent();

    SecurityStudent(string id, string firstName, string lastName, string emailAddress, int age, int *numberDays, Degree degree);

    Degree getDegree();

    void setDegree(Degree d);

    void print();

    ~SecurityStudent();
};

#endif