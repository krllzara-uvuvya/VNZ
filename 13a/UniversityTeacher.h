#pragma once
#include "UniversityPerson.h"
#include <iostream>
class UniversityTeacher : public UniversityPerson {
private:
    string scienceDegree;
    string mainSubject;

public:
    UniversityTeacher(const string& name, int age, int height, string degree, string subject);
       
    string getDegree() const;
    string getSubject() const;

    void showData() const ;
};