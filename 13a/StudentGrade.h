#pragma once
#include <string>

using namespace std;


enum class GradeType { Credit, Diff, Exam };

class StudentGrade {
private:
    string subjectName;
    GradeType gType;
    int points;

public:
    StudentGrade(const string& subjectName, GradeType gType, int points);
      
    string getSubject() const;
    GradeType getType() const;
    int getPoints() const;

    string convertToEcts() const;
    string getWordValue() const;
    
};