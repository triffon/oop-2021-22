const int subjectMaxGradesCount = 15;
const int subjectMaxNameLen = 30;
const int maxSubjectsCount = 100;

#include <cstring>
#include <exception>
#include <iostream>

template <typename K, typename V>
struct Pair{
    K first;
    V second;
};


struct Subject
{
    int mGradesIndex = 0;
    int mGrades[subjectMaxGradesCount];
    char mName[subjectMaxNameLen];
};

struct Gradebook
{
    // int mSubjectIndex = 0;
    Subject mSubjects[maxSubjectsCount];
};

// dopuskame che sushtestuvuva takuv predmet
void addGradeToSubject(Gradebook &gb, int grade, const char *subjectName)
{
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        if (strcmp(gb.mSubjects[i].mName, subjectName) == 0)
        {
            // int currGradeIndx = gb.mSubjects->mGradesIndex;
            gb.mSubjects[i].mGrades[gb.mSubjects->mGradesIndex++] = grade;
        }
    }
    throw std::invalid_argument("Invalid args passed");
}

void printSubject(const Subject &s)
{
    int sum = 0;
    for (int j = 0; j < s.mGradesIndex; j++)
    {
        sum += s.mGrades[j];
        std::cout << s.mGrades[j];
    }
    std::cout << (double)sum / (s.mGradesIndex);
}

void summarizeSubject(const Gradebook &gb, const char *subject)
{
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        if (strcmp(gb.mSubjects[i].mName, subject) == 0)
        {
            printSubject(gb.mSubjects[i]);
            return;
        }
    }
    throw std::invalid_argument("Invalid args passed");
}

void summarizeGradebook(const Gradebook &gb)
{
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        printSubject(gb.mSubjects[i]);
    }
}

bool checkForGrade(const Gradebook &gb, int grade, const char *subject)
{
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        if (strcmp(gb.mSubjects[i].mName, subject) == 0)
        {
            for (int j = 0; j < gb.mSubjects[i].mGradesIndex; j++)
            {
                if (gb.mSubjects[i].mGrades[j] == grade)
                {
                    return true;
                }
            }
            return false;
        }
    }
    throw std::invalid_argument("Invalid args passed");
}

int main(){
    Pair<int, std::string> a;
    a.first = 0;
    a.second = "Gosho";

    std::cout << a.first << a.second;
}