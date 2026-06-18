#include "UniversityStudent.h"
#include <clocale>

UniversityStudent::UniversityStudent(const string& name, int age, int height, string group, string faculty)
    : UniversityPerson(name, age, height)
{
    academicGroup = group;
    facultyName = faculty;
}

string UniversityStudent::getGroup() const { return academicGroup; }
string UniversityStudent::getFaculty() const { return facultyName; }
const vector<StudentGrade>& UniversityStudent::getGrades() const { return gradesList; }

void UniversityStudent::addNewGrade(const StudentGrade& grade) {
    gradesList.push_back(grade);
}

double UniversityStudent::calcAverage() const {
    if (gradesList.empty())
        return 0.0;
    double total = 0;
    for (const auto& grade : gradesList) {
        total += grade.getPoints();
    }
    return total / gradesList.size();
}

string UniversityStudent::getScholarshipStatus() const {
    if (gradesList.empty()) return "Немає оцінок";
    bool onlyExcellent = true;
    bool hasBadGrades = false;

    for (const auto& grade : gradesList) {
        if (grade.getPoints() < 60) hasBadGrades = true;
        if (grade.getPoints() < 90) onlyExcellent = false;
    }

    if (onlyExcellent) return "Підвищена стипендія";
    else if (!hasBadGrades && calcAverage() >= 75.0) return "Звичайна стипендія";
    else {
        return "Стипендія не призначена";
    }
    
}

void UniversityStudent::showData() const  {
    cout << getName() << ", Вік: " << getAge() << ", Зріст: " << getHeight() << " см" << endl;
    cout << "\t\tФакультет: " << facultyName << ", Група: " << academicGroup << endl;
}

void UniversityStudent::showScholarshipData() const {

    cout << getName() << ", Вік: " << getAge() << ", Зріст: " << getHeight() << " см" << endl;
    cout << "\t\tФакультет: " << facultyName << ", Група: " << academicGroup << endl;
    cout << "\t\tСтатус стипендії: " << getScholarshipStatus() << endl;

    if (!gradesList.empty()) {
        cout << "\t\tУспішність:" << endl;
        for (const auto& grade : gradesList) {
            string tStr = (grade.getType() == GradeType::Credit) ? "Залік" :
                (grade.getType() == GradeType::Diff) ? "Диф. залік" : "Іспит";
            cout << "\t\t- " << grade.getSubject() << " (" << tStr << "): "
                << grade.getPoints() << " балів [" << grade.convertToEcts()
                << " - " << grade.getWordValue() << "]" << endl;
        }
        cout << "\t\tСередній бал: " << calcAverage() << endl;
    }
}

    