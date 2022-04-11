#include "taskManager.h"
#include <iostream>
#include <cassert>
#include <cstring>

TaskManager::TaskManager() : size(0), capacity(INITIAL_CAPACITY)
{
    this->tasks = new (std::nothrow) Task[this->capacity];
    if (!this->tasks)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }
}

void TaskManager::deallocate()
{
    delete[] this->tasks;
}

void TaskManager::copy(const TaskManager& other)
{
    this->tasks = new (std::nothrow) Task[other.capacity];
    if (!this->tasks)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < other.size; ++i)
    {
        this->tasks[i] = other.tasks[i];
    }

    this->size = other.size;
    this->capacity = other.capacity;
}

void TaskManager::resize()
{
    Task* newTasks = new (std::nothrow) Task[this->capacity * INCREASE_STEP];
    if (!newTasks)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < this->size; ++i)
    {
        newTasks[i] = this->tasks[i];
    }

    this->deallocate();
    this->tasks = newTasks;
    this->capacity *= INCREASE_STEP;
}

TaskManager::TaskManager(const TaskManager& other)
{
    this->copy(other);
}

TaskManager& TaskManager::operator = (const TaskManager& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

TaskManager::~TaskManager()
{
    this->deallocate();
}

int TaskManager::getIndex(const char* title)
{
    assert(title);

    for (std::size_t i = 0; i < this->size; ++i)
    {
        if (strcmp(this->tasks[i].getTitle(), title) == 0)
        {
            return i;
        }
    }

    return -1;
}

std::size_t TaskManager::getTaskCount() const
{
    return this->size;
}

void TaskManager::addTask(const Task& task)
{
    if (this->getIndex(task.getTitle()) != -1)
    {
        std::cout << "There is already a task with name \"" << task.getTitle() << "\"" << std::endl;
        return;
    }

    if (this->size == this->capacity)
    {
        resize();
    }

    this->tasks[this->size++] = task;
}

void TaskManager::removeTask(const char* title)
{
    int index = this->getIndex(title);

    if (index == -1)
    {
        std::cout << "There is not a task with name \"" << title << "\""  << std::endl;
        return;
    }

    this->tasks[index] = this->tasks[--this->size];
}

const Task& TaskManager::getNextTask() const
{
    assert(this->size > 0);

    int resultIndex = 0;

    for (std::size_t i = 1; i < this->size; ++i)
    {
        if (this->tasks[i] < this->tasks[resultIndex])
        {
            resultIndex = i;
        }
    }

    return this->tasks[resultIndex];
}