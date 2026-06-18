#include "UniversityPerson.h"
#include <stdexcept>

UniversityPerson::UniversityPerson(const string& name, int age, int height) {
	if (name.empty()) throw invalid_argument("Ім'я не може бути порожнім!");
	if (age <= 0 || age > 150) throw invalid_argument("Некоректний вік!");
	if (height <= 0 || height > 300) throw invalid_argument("Некоректний зріст!");

	fullName = name;
	personAge = age;
	personHeight = height;
}

string UniversityPerson::getName() const {
	return fullName;
}
int UniversityPerson::getAge() const {
	return personAge;
}
int UniversityPerson::getHeight() const {
	return personHeight;
}
