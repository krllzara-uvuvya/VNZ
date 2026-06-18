#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>
#include <limits>
#include <algorithm> 
#include <clocale>
#include "UniversityStudent.h"
#include "UniversityTeacher.h"
#include "MainSystem.h"
using namespace std;



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "ukr");

    MainSystem system;
    system.displayMenu();

    return 0;
}