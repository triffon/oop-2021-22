const int maxSubjectNameLen = 40;
const int maxSubjects = 100;
const int maxStringLen = 50;

struct Subject
{
    char name[maxSubjectNameLen];
    double grade;
};

struct StudentsBook
{
    int failedExamsCounter = 0; //or we must count all subject in a different method
    double currentGradesSum = 0; //or we need O(n) traversal of all subjects

    int currCounter = 0;
    Subject subjects[maxSubjects];
    char name[maxStringLen];
    char facultyNumber[maxStringLen];
};

