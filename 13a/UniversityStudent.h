#pragma once
#include <iostream>
#include "UniversityPerson.h"
#include "StudentGrade.h"
#include <vector>
class UniversityStudent : public UniversityPerson {
private:
    string academicGroup;
    string facultyName;
    vector<StudentGrade> gradesList;

public:
    UniversityStudent(const string& name, int age, int height, string group, string faculty);

  
    string getGroup() const;
    string getFaculty() const;
    const vector<StudentGrade>& getGrades() const;
    void addNewGrade(const StudentGrade& grade);
     
    double calcAverage() const;

    string getScholarshipStatus() const;

    void showData() const;
    void showScholarshipData() const;
};
