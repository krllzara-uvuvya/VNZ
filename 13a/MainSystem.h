#pragma once
#include <algorithm>
#include "UniversityTeacher.h"
#include "UniversityStudent.h"
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

private:
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