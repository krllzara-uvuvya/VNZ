#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "UniversityTeacher.h"
#include "UniversityStudent.h"

using namespace std;

class MainSystem {
private:
    vector<UniversityTeacher*> Teachers;
    vector<UniversityStudent*> Students;

public:
    MainSystem() {
    }

    ~MainSystem() {
        clearMemory();
    }

    void displayMenu();
    void clearMemory();
    void createNewStudent();
    void createNewTeacher();
    void showAllTeachers() const;
    void showAllStudents() const;
    void assignGradeToStudent();
    void checkScholaships() const;
    void removePerson();
    void sortStudentsByPerformance();
};