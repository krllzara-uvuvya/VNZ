#pragma once

#include <string>
#include <fstream>

using namespace std;


class UniversityPerson {
private:
	string fullName;
	int personAge;
	int personHeight;

public:
	UniversityPerson(const string& name, int age, int height);

	string getName() const;
	int getAge() const;
	int getHeight() const;

	virtual void showData() const = 0;
	virtual ~UniversityPerson() = default;
};