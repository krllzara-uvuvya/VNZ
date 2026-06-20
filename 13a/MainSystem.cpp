#include "MainSystem.h"
#include <cctype> 
#include <algorithm> 


bool isValidNameInput(const string& name) {
    if (name.empty()) return false;
    if (name.find_first_not_of(' ') == string::npos) return false;
    for (char const& c : name) {
        if (isdigit(c)) return false;
    }
    return true;
}

void MainSystem::displayMenu() {
    int userChoice = -1;
    while (userChoice != 0) {
        cout << "\n=== СИСТЕМА УПРАВЛIННЯ ВНЗ ===" << endl;
        cout << "1. Додати нового студента" << endl;
        cout << "2. Додати викладача" << endl;
        cout << "3. Вивести список викладачів" << endl;
        cout << "4. Вивести список студентів" << endl;
        cout << "5. Поставити оцiнку студенту" << endl;
        cout << "6. Перевiрити стипендiю" << endl;
        cout << "7. Видалити особу з бази" << endl;
        cout << "8. Сортувати студентiв за середнiм балом" << endl;
        cout << "0. Вихiд" << endl;
        cout << "Зробiть ваш вибiр: ";

        if (!(cin >> userChoice)) {
            cout << "Помилка вводу! Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            userChoice = -1;
            continue;
        }
        cin.ignore(32767, '\n');
        try {
            if (userChoice == 1) createNewStudent();
            else if (userChoice == 2) createNewTeacher();
            else if (userChoice == 3) showAllTeachers();
            else if (userChoice == 4) showAllStudents();
            else if (userChoice == 5) assignGradeToStudent();
            else if (userChoice == 6) checkScholaships();
            else if (userChoice == 7) removePerson();
            else if (userChoice == 8) sortStudentsByPerformance();
            else if (userChoice == 0) cout << "Програма завершує роботу." << endl;
            else cout << "Нevірна дiя!" << endl;
        }
        catch (const invalid_argument& exception) {
            cout << "\n[ПОМИЛКА ВАЛІДАЦІЇ]: " << exception.what() << " Спробуйте знову." << endl;
        }
    }
}

void MainSystem::clearMemory() {
    for (auto teacher : Teachers) delete teacher;
    Teachers.clear();
    for (auto student : Students) delete student;
    Students.clear();
}

void MainSystem::createNewStudent() {
    string name, group, faculty;
    int age, height;
    while (true) {
        cout << "ПIБ студента: ";
        getline(cin, name);
        if (isValidNameInput(name)) break;
        cout << "Помилка! ПIБ не може бути порожнiм або мiстити цифри." << endl;
    }
    cout << "Вiк: ";
    cin >> age;
    cout << "Зрiст (см): ";
    cin >> height;
    cin.ignore(32767, '\n');
    cout << "Група: ";
    getline(cin, group);
    cout << "Факультет: ";
    getline(cin, faculty);

    Students.push_back(new UniversityStudent(name, age, height, group, faculty));
    cout << "Студента успiшно створено." << endl;
}

void MainSystem::createNewTeacher() {
    string name, degree, subject;
    int age, height;
    while (true) {
        cout << "ПIБ викладача: ";
        getline(cin, name);
        if (isValidNameInput(name)) break;
        cout << "Помилка! ПIБ не може бути порожнiм або мiстити цифри." << endl;
    }

    cout << "Вiк: ";
    cin >> age;
    cout << "Зрiст (см): ";
    cin >> height;
    cin.ignore(32767, '\n');
    cout << "Вчений ступiнь: ";
    getline(cin, degree);
    cout << "Предмет: ";
    getline(cin, subject);
    Teachers.push_back(new UniversityTeacher(name, age, height, degree, subject));
    cout << "Викладача успiшно створено." << endl;
}

void MainSystem::showAllTeachers() const {
    if (Teachers.empty()) {
        cout << "База даних вчителів порожня." << endl;
        return;
    }
    cout << "\n--- Зареєстрованi особи у базi ---" << endl;
    for (size_t i = 0; i < Teachers.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        Teachers[i]->showData();
        cout << endl;
    }
}

void MainSystem::showAllStudents() const {
    if (Students.empty()) {
        cout << "База даних учнів порожня." << endl;
        return;
    }
    cout << "\n--- Зареєстрованi особи у базi ---" << endl;
    for (size_t i = 0; i < Students.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        Students[i]->showData();
        cout << endl;
    }
}

void MainSystem::assignGradeToStudent() {
    if (Teachers.empty()) {
        cout << "База даних вчителів порожня,нема кому ставити оцінки" << endl;
        return;
    }
    showAllStudents();
    if (Students.empty()) return;
    int num;
    cout << "Введiть порядковий номер студента: ";
    cin >> num;
    num--;

    if (num < 0 || num >= Students.size()) {
        cout << "Помилка: невiрний номер!" << endl;
        return;
    }
    UniversityStudent* studentPtr = Students[num];

    showAllTeachers();
    cout << "Введiть порядковий номер викладача: ";
    cin >> num;
    num--;
    if (num < 0 || num >= Teachers.size()) {
        cout << "Помилка: невiрний номер!" << endl;
        return;
    }
    UniversityTeacher* teacherPtr = Teachers[num];

    string subject = teacherPtr->getSubject();

    cout << "Оберiть тип контролю (1 - Залiк, 2 - Диф. залiк, 3 - Iспит): " << endl;
    int typeSelect = 0;

    GradeType finalType = GradeType::Credit;
    while (typeSelect < 1 || typeSelect > 3) {
        cin >> typeSelect;
        if (typeSelect == 1) {
            finalType = GradeType::Credit;
        }
        else if (typeSelect == 2) {
            finalType = GradeType::Diff;
        }
        else if (typeSelect == 3) {
            finalType = GradeType::Exam;
        }
        else {
            cout << "Невідомий тип контролю!" << endl;
        }
    }

    int points;
    cout << "Введiть оцiнку (0-100): ";
    cin >> points;
    StudentGrade grade = StudentGrade(subject, finalType, points);
    studentPtr->addNewGrade(grade);
    cout << "Оцiнка успiшно внесена в базу." << endl;
}

void MainSystem::checkScholaships() const {
    showAllStudents();
    if (Students.empty()) return;

    int num;
    cout << "Введiть порядковий номер студента: ";
    cin >> num;
    num--;
    if (num < 0 || num >= (Students.size())) {
        cout << "Помилка: невiрний номер!" << endl;
        return;
    }

    UniversityStudent* studentPtr = Students[num];
    studentPtr->showScholarshipData();
}

void MainSystem::removePerson() {
    cout << "\n--- Видалення особи ---" << endl;
    cout << "1. Видалити студента" << endl;
    cout << "2. Видалити викладача" << endl;
    cout << "0. Скасувати" << endl;
    cout << "Ваш вибір: ";

    int typeChoice;
    cin >> typeChoice;

    if (typeChoice == 0) {
        return;
    }
    else if (typeChoice == 1) {
        showAllStudents();
        if (Students.empty()) return;

        int num;
        cout << "Введіть номер студента для ВИДАЛЕННЯ: ";
        cin >> num;
        num--;
        if (num < 0 || num >= Students.size()) {
            cout << "Помилка: невірний номер!" << endl;
            return;
        }
        delete Students[num];
        Students.erase(Students.begin() + num);
        cout << "Студента успішно видалено з бази даних." << endl;
    }
    else if (typeChoice == 2) {
        showAllTeachers();
        if (Teachers.empty()) return;
        int num;
        cout << "Введіть номер викладача для ВИДАЛЕННЯ: ";
        cin >> num;
        num--;
        if (num < 0 || num >= Teachers.size()) {
            cout << "Помилка: невірний номер!" << endl;
            return;
        }
        delete Teachers[num];
        Teachers.erase(Teachers.begin() + num);
        cout << "Викладача успішно видалено з бази даних." << endl;
    }
    else {
        cout << "Помилка: невірний вибір!" << endl;
    }
}

void MainSystem::sortStudentsByPerformance() {
    vector<UniversityStudent*> students;
    for (auto student : Students) {
        UniversityStudent* s = (student);
        if (s) students.push_back(s);
    }

    if (students.empty()) {
        cout << "У базі немає студентів для сортування." << endl;
        return;
    }

    sort(students.begin(), students.end(), [](const UniversityStudent* first, const UniversityStudent* second) {
        return first->calcAverage() > second->calcAverage();
        });

    cout << "\n--- Рейтинг студентів за середнім баллом ---" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". " << students[i]->getName() << " (Група: " << students[i]->getGroup()
            << ") - Середній бал: " << students[i]->calcAverage() << endl;
    }
}