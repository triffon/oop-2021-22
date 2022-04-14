#pragma once

#include <cstddef>
#include "task.h"

const std::size_t INITIAL_CAPACITY = 2;
const std::size_t INCREASE_STEP = 2;

class TaskManager
{
private:
    std::size_t size;
    std::size_t capacity;
    Task* tasks;

    void copy(const TaskManager& other);
    void deallocate();
    void resize();

    int getIndex(const char* title);

public:
    TaskManager();
    TaskManager(const TaskManager& other);
    TaskManager& operator = (const TaskManager& other);
    ~TaskManager();

    std::size_t getTaskCount() const;
    void addTask(const Task& task);
    void removeTask(const char* title);
    const Task& getNextTask() const;
};