#include <iostream>
#include <string>

#include "student.h"
#include "degree.h"

using namespace std;

Student::Student(string id, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeProgram) {
    this->id = id;
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->EmailAddress = EmailAddress;
    this->Age = Age;
    this->DaysInCourse = new int [COURSES];
    for (int i = 0; i < COURSES; i++) {
        this->DaysInCourse[i] = DaysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {
    delete [] DaysInCourse;
}

//Getters
string Student::GetStudentID() {
        return id;
}
string Student::GetFirstName() {
        return FirstName;
}
string Student::GetLastName() {
        return LastName;
}
string Student::GetEmailAddress() {
        return EmailAddress;
}
int Student::GetAge() {
        return Age;
}
int *Student::GetDaysInCourse() {
        return DaysInCourse;
}
DegreeProgram Student::GetDegreeProgram() {
        return degreeProgram;
}
    
//Setters
    
void Student::SetStudentID(string id) {
    this->id = id;
}
void Student::SetFirstName(string FirstName) {
    this->FirstName = FirstName;
}
void Student::SetLastName(string LastName) {
    this->LastName = LastName;
}
void Student::SetEmailAddress(string EmailAddress) {
    this->EmailAddress = EmailAddress;
}
void Student::SetAge(int Age) {
    this->Age = Age;
}
void Student::SetDaysInCourse(int DaysInCourse[]) {
    for (int i = 0; i < COURSES; i++) {
        this->DaysInCourse[i] = DaysInCourse[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
    return;
}

//Print
void Student::print() {
    cout << "Student ID: " << id << '\t' << "First Name: " << FirstName << '\t' << "Last Name: " << LastName  << '\t' << "Age: " << Age << '\t';
    cout << "Days In Course: ";
    cout << "{";
    for (int i=0; i < COURSES; i++) {
        cout << DaysInCourse[i];
        if (i != COURSES - 1) {
            cout<<",";
        }
    }
    cout << "}";
    cout << '\t';
    cout << "Degree Program: ";
    switch(degreeProgram) {
    case SECURITY :
        cout << "SECURITY";
        break;
    case NETWORK :
        cout << "NETWORK";
        break;
    case SOFTWARE :
        cout << "SOFTWARE";
        break;
    case UNDECLARED :
        cout << "UNDECLARED";
        break;
    }
    cout << endl;
    return;
}
