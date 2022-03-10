#include <iostream>
#include <cstring>
#include "Gradebook.h"

void addGradeToSubject(Gradebook &gb, const char *subject, int grade)
{
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        if (strcmp(gb.subjects[i].name, subject) == 0)
        {
            gb.subjects[i].grades[gb.subjects[i].gradeIndex++] = grade;
            return;
        }
    }
    throw std::invalid_argument("Invalid parameters passed");
}

void summarizeSubject(const Gradebook &gb, const char *subject)
{
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        if (strcmp(gb.subjects[i].name, subject) == 0)
        {
            int sum = 0;
            for (int j = 0; j < gb.subjects[i].gradeIndex; j++)
            {
                sum += gb.subjects[i].grades[j];
                std::cout << gb.subjects[i].grades[j];
            }
            std::cout << sum / (gb.subjects[i].gradeIndex - 1);
            return;
        }
    }
    throw std::invalid_argument("Invalid args passed");
}

void summarizeGradebook (const Gradebook& gb){
    //almost the same as the above method
}  

bool checkForGrade(const Gradebook& gb, int grade, const char* subject){
    for (int i = 0; i < maxSubjectsCount; i++)
    {
        if (strcmp(gb.subjects[i].name, subject) == 0)
        {
            for (int j = 0; j < gb.subjects[i].gradeIndex; j++)
            {
                if(gb.subjects[i].grades[j] == grade){
                    return true;
                }
            }
            return false;
        }
    }
    throw std::invalid_argument("Invalid args passed");
}

int main()
{

    return 0;
}