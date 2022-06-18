#ifndef roster_h
#define roster_h

#include <stdio.h>
#include <iostream>

#include "student.h"
#include "degree.h"

class Roster {
public:
    //Constructor
    Roster(const string StudentData[], int sizeData, int maxSize);
    //Deconstructor
    ~Roster();
    
    //Parse - E 2A
    void ParseData(string data);
    
    //Add - 2B
    void add(string id, string FirstName, string LastName, string EmailAddress, int Age, int daysinCourse1, int daysinCourse2, int daysinCourse3, DegreeProgram degreeProgram);
    
    //Define functions - E 3A-F
    void remove(string id);
    void printAll();
    void printAverageDaysInCourse(string id);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    int totalStudent;
    int maxSize;
    Student* *classRosterArray;
    
};

#endif /* roster_h */
