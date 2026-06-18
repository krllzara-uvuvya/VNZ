#include "UniversityTeacher.h"

UniversityTeacher::UniversityTeacher(const string& name, int age, int height, string degree, string subject)
        : UniversityPerson(name, age, height) {
        if (degree.empty()) throw invalid_argument("Ступінь не може бути порожнім!");
        if (subject.empty()) throw invalid_argument("Предмет не може бути порожнім!");
        scienceDegree = degree;
        mainSubject = subject;
    }


    string UniversityTeacher::getDegree() const { return scienceDegree; }
    string UniversityTeacher::getSubject() const { return mainSubject; }

    void UniversityTeacher::showData() const  {
        cout  << getName() << ", Вік: " << getAge() << ", Зріст: " << getHeight() << " см" << endl;
        cout << "\t\tСтупінь: " << scienceDegree << ", Дисципліна: " << mainSubject << endl;
    }


