#include "taskManager.h"
#include <iostream>

int main()
{
    Task algebra("Algebra 2", "izvanredna lekciq", TaskCategory::UNIVERSITY, Date(1,4,2022));
    Task tennis("tennis.bg", "napishi statiq za Grigor", TaskCategory::WORK, Date(3,4,2022));
    Task disco("Illuzion", "otidi na Medi", TaskCategory::OTHER, Date(30,3,2022));

    TaskManager tasks;
    tasks.addTask(algebra);
    tasks.addTask(tennis);
    tasks.addTask(tennis);
    std::cout << std::endl;
    tasks.addTask(disco);

    TaskManager copy;
    copy = tasks;

    Task room("Chistene", "izchisti si staqta", TaskCategory::FOR_HOME, Date(27,3,2022));
    copy.addTask(room);

    tasks.getNextTask().print();
    std::cout << std::endl << std::endl;
    copy.getNextTask().print();
    std::cout << std::endl << std::endl;

    tasks.removeTask("alo");
    tasks.removeTask("Illuzion");
    std::cout << std::endl;
    tasks.getNextTask().print();
    std::cout << std::endl;

    return 0;
}