#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {

protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int *numberDays;
    Degree degree;


public:
    const static int num_days_size = 3;

    //constructors
    Student();

    Student(string id, string firstName, string lastName, string emailAddress, int age, int numberDays[], Degree degree);

    //accessors
    string getStudentID();

    string getFirstName();

    string getLastName();

    string getEmailAddress();

    int getAge();

    int *getNumDays();

    virtual Degree getDegree() = 0;

    //mutators
    void setStudentID(string id);

    void setFirstName(string firstName);

    void setLastName(string lastName);

    void setEmailAddress(string emailAddress);

    void setAge(int age);

    void setNumDays(int numberDays[]);

    virtual void setDegree(Degree degree) = 0;

    virtual void print() = 0;

    //destructor
    ~Student();


};


#endif