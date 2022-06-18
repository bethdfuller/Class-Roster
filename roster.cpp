#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "student.h"
#include "roster.h"

using namespace std;

Roster::Roster(const string StudentData[], int sizeData, int maxSize) {
    this->totalStudent = sizeData;
    this->classRosterArray = new Student*[maxSize];
    this->maxSize = maxSize;

    //Parse
    int entry = 0;
    while (entry < sizeData) {
        vector <string> tokens;
        stringstream streamEntry(StudentData[entry]);
        string nextToken;
        while(getline(streamEntry, nextToken, ',')) {
            tokens.push_back(nextToken);
        }

    //Days in Course String to Int
        int DaysInCourse[3] = {stoi(tokens[5]), stoi(tokens[6]), stoi(tokens[7])};
        
    //Age String to Int
        int Age = stoi(tokens[4]);
        
    //Degree Program string to Enum Data Type
        DegreeProgram degreeProgram = UNDECLARED;
        if (tokens[8].compare("SECURITY") == 0) {
            degreeProgram = SECURITY;
        }
        else if (tokens[8].compare("NETWORK") == 0) {
            degreeProgram = NETWORK;
        }
        else if (tokens[8].compare("SOFTWARE") == 0) {
            degreeProgram = SOFTWARE;
        }
        else {
            degreeProgram = UNDECLARED;
        }
    //Add students to classRosterArray
        classRosterArray[entry] = new Student (tokens[0], tokens[1], tokens[2], tokens[3], Age, DaysInCourse, degreeProgram);
        entry++;
    }
}


//Memory release - F5
Roster::~Roster(){
    for (int i = 0; i <totalStudent; i++) {
        delete this->classRosterArray[i];
    }
    delete classRosterArray;
}
    
//Add
void Roster::add(string id, string FirstName, string LastName, string EmailAddress, int Age, int daysinCourse1, int daysinCourse2, int daysinCourse3, DegreeProgram degreeProgram) {
    int DaysInCourse[3] = {daysinCourse1, daysinCourse2, daysinCourse3};
    classRosterArray[totalStudent] = new Student(id, FirstName, LastName, EmailAddress, Age, DaysInCourse, degreeProgram);
    totalStudent++;
}

//Remove
void Roster::remove(string id) {
    bool StudentIDFind = false;
    for (int i = 0; (i < totalStudent) && !StudentIDFind; ++i) {
        if(classRosterArray[i]->GetStudentID() == id) {
           classRosterArray[i] = classRosterArray[totalStudent - 1];
            --totalStudent;
            StudentIDFind = true;
        }
    }
    if (StudentIDFind) {
        cout << "StudentID: " << id << " has been removed." << endl;
    }
    else {
        cout << "Student with that ID was not found in roster." << endl;
    }
}


//Print
void Roster::printAll() {
    for (int i = 0; i < totalStudent; ++i) {
        classRosterArray[i]->print();
    }
}

//Print Invalid Emails
void Roster::printInvalidEmails() {
    for (int i = 0; i < totalStudent; ++i) {
        string Email = classRosterArray[i]->GetEmailAddress();
        if (Email.find("@") == string::npos) {
            cout << "Invalid: Email missing @ Check: "<< '\t' << Email << endl;
        }
        else if (Email.find(".") == string::npos) {
            cout << "Invalid: Email missing . Check: " << '\t' << Email << endl;
        }
        else if (Email.find(' ') != string::npos) {
            cout << "Invalid: Email contains space Check: " << '\t' <<  Email << endl;
        }
    }
    cout << "\n";
}

//Print Average Days In Course
void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < totalStudent; ++i) {
        if(classRosterArray[i]->GetStudentID() == id) {
            cout << "StudentID: " << classRosterArray[i]->GetStudentID() << " - ";
            int *days = classRosterArray[i]->GetDaysInCourse();
            cout << "Average Days in Course: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}

//Print by Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < totalStudent; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
