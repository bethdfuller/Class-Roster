#include <iostream>
#include <string>

#include "roster.h"

using namespace std;

int main()
{
    
    //F1 - Print the course title, programming language, WGU Student ID, Name
    cout << "Scripting and Programming Applications - C867" << endl;
    cout << "C++" << endl;
    cout << "WGU Student ID: #001409039" << endl;
    cout << "Beth Fuller" << endl;
    cout << endl;
    
    const string StudentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Beth,Fuller,bethdfuller@gmail.com,33,20,40,60,SOFTWARE"
    };
    
    //Create instance of Roster class - F2
    Roster* classRoster = new Roster(StudentData, 5, 20);
    
    //Print Class Roster
    cout << "Print Class Roster" << endl;
    classRoster->printAll();
    cout << endl;
    
    //Print Invalid Emails
    cout << "Invalid Email Addresses" << endl;
    classRoster->printInvalidEmails();
    cout << endl;
    
    //Print Average Days In Course
    cout << "Average Days in Course by Student" << endl;
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;
    
    //Print By Degree Program
    cout <<"SECURITY Student Roster" << endl;
    classRoster->printByDegreeProgram(SECURITY);
    cout << endl;
    cout <<"NETWORK Student Roster" << endl;
    classRoster->printByDegreeProgram(NETWORK);
    cout << endl;
    cout <<"SOFTWARE Student Roster" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    //Remove student A3
    classRoster->remove("A3");
    
    //Print with removed student
    cout << "Print Class Roster (after student removed)" << endl;
    classRoster->printAll();
    
    //Try to remove again
    classRoster->remove("A3");
    cout << endl;
}
