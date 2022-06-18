#ifndef student_h
#define student_h

#include<string>
#include<iostream>

#include "degree.h"

using namespace std;

#define COURSES 3

//6D - Student class & variables
class Student {
public:
    //Accessor/Getter - 2A
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    int *GetDaysInCourse();
    DegreeProgram GetDegreeProgram();
    
    //Mutator/Setter - 2B
    void SetStudentID (string id);
    void SetFirstName (string FirstName);
    void SetLastName (string LastName);
    void SetEmailAddress (string EmailAddress);
    void SetAge (int Age);
    void SetDaysInCourse (int DaysInCourse[]);
    void SetDegreeProgram (DegreeProgram);
    
    //Constructor/Deconstructor - 2D
    Student (string id, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeProgram);
    ~Student();
    
    //Print - 2E
    void print();

private:
    string id;
    string FirstName;
    string LastName;
    string EmailAddress;
    int Age;
    int *DaysInCourse;
    DegreeProgram degreeProgram;
};

#endif /* student_h */
