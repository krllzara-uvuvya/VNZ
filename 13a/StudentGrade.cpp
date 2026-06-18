#include "StudentGrade.h"
#include <stdexcept>
StudentGrade::StudentGrade(const string& subject, GradeType gradeType, int gradePoints) {
    if (subjectName.empty()) throw invalid_argument("Назва предмета не може бути порожньою!");
    if (points < 0 || points > 100) throw invalid_argument("Оцінка повинна бути в межах від 0 до 100!");

    subjectName = subject;
    gType = gradeType;
    points = gradePoints;
}

string StudentGrade::getSubject() const { return subjectName; }
GradeType StudentGrade::getType() const { return gType; }
int StudentGrade::getPoints() const { return points; }

string StudentGrade::convertToEcts() const {
    if (points >= 90) return "A";
    if (points >= 85) return "B";
    if (points >= 75) return "C";
    if (points >= 65) return "D";
    if (points >= 60) return "E";
    return (gType == GradeType::Credit) ? "F (незарах.)" : "F (незадов.)";
}

string StudentGrade::getWordValue() const {
    if (gType == GradeType::Credit) {
        return (points >= 60) ? "Зараховано" : "Незараховано";
    }
    if (points >= 90) return "Відмінно";
    if (points >= 75) return "Добре";
    if (points >= 60) return "Задовільно";
    return "Незадовільно";
}