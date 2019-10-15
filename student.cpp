#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"

using namespace std;

//default constructor
Student::Student() {
    this->studentID = "student_id";
    this->firstName = "first_name";
    this->lastName = "last_name";
    this->emailAddress = "email_address";
    this->age = 0;
    this->numberDays = new int[num_days_size];
    for (int i = 0; i < num_days_size; ++i) this->numberDays[i] = 0;
}

//construct
Student::Student(string id, string firstName, string lastName, string emailAddress, int age, int numberDays[], Degree degree) {
    this->studentID = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->numberDays = new int[num_days_size];
    for (int i = 0; i < 3; ++i) this->numberDays[i] = numberDays[i];
}

//access
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int *Student::getNumDays() {
    return numberDays;
}

//mutate
void Student::setStudentID(string id) {
    this->studentID = id;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setNumDays(int numberDays[]) {
    if (this->numberDays != nullptr) {
        delete[] this->numberDays;
        this->numberDays = nullptr;
    }
    this->numberDays = new int[num_days_size];
    for (int i = 0; i < 3; ++i) {
        this->numberDays[i] = numberDays[i];
    }
}

void Student::print() {
    int *courseday = getNumDays();

    cout << getStudentID() << "\t";
    cout << "First name: " << getFirstName() << "\t";
    cout << "Last name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t" << "\t";
    cout << "Days in course: {" << *courseday << " " << *(courseday + 1) << " " << *(courseday + 2) << "}" << "\t";
}

//destructor
Student::~Student() {
    if (numberDays != nullptr) {
        delete[] numberDays;
        numberDays = nullptr;
    }
}
