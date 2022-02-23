#include <iostream>
#include <cstring>
using namespace std;

struct Point {
    double x, y;
};

const size_t MAX = 60;

struct Student {
    char name[MAX];
    int year;
    double grade;
};

void printStudent(Student const& s) {
    cout << s.name << ' ' << s.year << ' ' << s.grade << endl;
}

void readStudent(Student& s) {
    cout << "Име: ";
    cin.getline(s.name, MAX);
    do {
        cout << "Курс: ";
        cin >> s.year;
    } while(s.year < 1 || s.year > 4);
    cout << "Оценка: ";
    cin >> s.grade;
}

/*
Student readStudent() {
    // тук ще има копиране на записа
}
*/

int readStudents(Student students[]) {
    int nStudents;
    cout << "Моля, въведете брой студенти: ";
    cin >> nStudents;
    for(int i = 0; i < nStudents; i++) {
        // изчистваме останалия нов ред, за да можем да четем правилно имена
        char temp[MAX];
        cin.getline(temp, MAX);
        // cin.get()
        cout << "Моля, въведете студент " << i + 1 << ':' << endl;
        readStudent(students[i]);
    }
    return nStudents;
}

void testSizes() {
    int a[10];
    cout << sizeof(int) << ' ' << sizeof(a) << endl;
    cout << sizeof(double) << ' ' << sizeof(Point) << endl;
    cout << sizeof(Student) << endl;
}

void printHeader() {
    cout << endl;
    cout << "| ";
    cout.setf(ios::left);
    cout.width(MAX);
    cout << "Name";
    cout << " | Year | Grade |";
    cout << endl;
    cout << '+';
    cout.unsetf(ios::left);
    cout.setf(ios::right);
    cout.fill('-');
    cout.width(78);
    cout << '+' << endl;
    // възстановяване на настройките по подразбиране
    cout.unsetf(ios::right);
    cout.fill(' ');
}

void printStudentLine(Student const& student) {
    cout.fill(' ');
    cout << "| ";
    cout.setf(ios::left);
    cout.width(MAX);
    cout << student.name;
    cout << " | ";
    cout.width(4);
    cout.unsetf(ios::left);
    cout.setf(ios::right);
    cout << student.year;
    cout << " | ";
    cout.width(5);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << student.grade;
    cout << " |" << endl;
    // възстановяване на настройките по подразбиране
    cout.unsetf(ios::right);
    cout.unsetf(ios::fixed);
    cout.precision(6);
    // !!! student.grade += 1;
}

void sortStudents(Student students[], size_t nStudents) {
    for(int i = 0; i < nStudents - 1; i++) {
        int mini = i;
        for(int j = i + 1; j < nStudents; j++)
            if (strcmp(students[j].name, students[mini].name) < 0)
                mini = j;
        Student tmp = students[mini];
        students[mini] = students[i];
        students[i] = tmp;
    }
}

void printStudents(Student students[], size_t nStudents) {
    printHeader();
    for(int i = 0; i < nStudents; i++)
        printStudentLine(students[i]);
}

void testStudents() {
    const size_t MAXS = 30;
    Student students[MAXS];
    int nStudents = readStudents(students);
    printStudents(students, nStudents);
    cout << endl << endl;
    sortStudents(students, nStudents);
    printStudents(students, nStudents);
}

int main() {
    // testSizes();
    testStudents();
    return 0;
}
