#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

class SoftwareStudent : public Student {
public:
    SoftwareStudent();

    SoftwareStudent(string id, string firstName, string lastName, string emailAddress, int age, int *numberDays, Degree degree);

    Degree getDegree();

    void setDegree(Degree d);

    void print();

    ~SoftwareStudent();
};


#endif