const int maxSubjectsCount = 100;
const int subjectNameMaxLen = 30;
const int subjectMaxGrades = 15;

struct Subject{
    int gradeIndex = 0;
    int grades[subjectMaxGrades];
    char name[subjectNameMaxLen];
};

struct Gradebook
{
    Subject subjects[maxSubjectsCount];
};
