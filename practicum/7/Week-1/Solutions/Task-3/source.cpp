#include "StudentsBook.h"
#include <exception>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool validGrade(const double &grade)
{
    return grade >= 2 && grade <= 6;
}

void swap(double &a, double &b)
{
    double temp = b;
    b = a;
    a = temp;
}

void swapSubjects(Subject &first, Subject &second)
{
    swap(first.grade, second.grade);

    char temp[maxSubjectNameLen];
    strncpy(temp, second.name, strlen(second.name) + 1);
    strncpy(second.name, first.name, strlen(first.name) + 1);
    strncpy(first.name, temp, strlen(temp) + 1);
}

bool addGrade(StudentsBook &sb, double grade, const char *subjName)
{
    if (!validGrade(grade))
    {
        return false;
    }
    sb.currentGradesSum += grade;
    if (grade < 3)
    {
        sb.failedExamsCounter++;
    }

    for (int i = 0; i < sb.currCounter; i++)
    {
        if (strcmp(sb.subjects[i].name, subjName) == 0)
        {
            sb.subjects[i].grade = grade;
            return true;
        }
    }

    sb.subjects[sb.currCounter].grade = grade;
    strncpy(sb.subjects[sb.currCounter].name, subjName, strlen(subjName) + 1);
    sb.currCounter++;
    return true;
}

void sortGrades(StudentsBook &sb)
{
    for (int i = 0; i < sb.currCounter - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < sb.currCounter; j++)
        {
            if (sb.subjects[j].grade < sb.subjects[minIndex].grade)
            {
                minIndex = j;
            }
        }
        swapSubjects(sb.subjects[i], sb.subjects[minIndex]);
    }
}

double calculateAverage(const StudentsBook &sb, bool includeFailed = 1)
{
    if (includeFailed)
    {
        return sb.currentGradesSum / sb.currCounter;
    }
    return sb.currentGradesSum / (sb.currCounter - sb.failedExamsCounter);
}

bool canPass(const StudentsBook &sb)
{
    if (sb.failedExamsCounter < 4)
    {
        return true;
    }
    else if (sb.failedExamsCounter > 4)
    {
        return false;
    }
    return calculateAverage(sb) >= 3.00;
}

bool canGetScolarship(const StudentsBook &sb)
{
    return calculateAverage(sb) >= 5.00 && sb.failedExamsCounter == 0;
}

void printGrades(const StudentsBook &sb)
{
    for (int i = 0; i < sb.currCounter; i++)
    {
        std::cout << sb.subjects[i].name << ' ' << sb.subjects[i].grade << '\n';
    }
}

int main()
{
    StudentsBook sb;
    strncpy(sb.name, "John", 5);

    addGrade(sb, 6, "Algebra");
    addGrade(sb, 4, "Calculus");
    addGrade(sb, 5, "Programing");
    addGrade(sb, 2, "Minko");

    // printGrades(sb); std::cout << '\n';
    // sortGrades(sb);
    // printGrades(sb);
    // char* arr = new char[4];
    // char* arr2 = new char[4];
    // strcpy(arr,"Azz");
    // strcpy(arr2,"aazi");
    // std::cout << arr;
    // std::cout << mystery(arr,arr2);

    int sum = 0;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum++;
        }
    }
    std::cout << sum;
    
    // std::cout << canPass(sb);

    return 0;
}