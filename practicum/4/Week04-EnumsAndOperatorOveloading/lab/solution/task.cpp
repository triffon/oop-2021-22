#include "task.h"
#include <cstring>
#include <iostream>
#include <cassert>

const std::size_t MAX_CATEGORY_SIZE = 15;

Task::Task(const char* title, const char* description, const TaskCategory category, const Date deadline)
    : category(category), deadline(deadline)
{
    this->setTitle(title);
    this->setDescription(description); 
}

Task::Task() : Task("", "", TaskCategory::UNKNOWN, Date(1,1,1)) {}

const char* Task::getTitle() const
{
    return this->title;
}   

const char* Task::getDescription() const
{
    return this->description;
}

TaskCategory Task::getCategory() const
{
    return this->category;
}

Date Task::getDeadline() const
{
    return this->deadline;
}

void Task::setTitle(const char* title)
{
    assert(title);
    strcpy(this->title, title);
}

void Task::setDescription(const char* description)
{
    assert(title);
    strcpy(this->description, description);
}

void Task::setCategory(const TaskCategory category)
{
    this->category = category;
}

void Task::setDeadline(const Date deadline)
{
    this->deadline = deadline;
}

bool Task::operator < (const Task& other) const
{
    return this->deadline < other.deadline;
}

void Task::print() const
{
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Description: " << this->description << std::endl;

    char temp[MAX_CATEGORY_SIZE];
    switch (this->category)
    {
    case TaskCategory::UNKNOWN:
        strcpy(temp, "unknown");
        break;
    case TaskCategory::UNIVERSITY:
        strcpy(temp, "university");
        break;
    case TaskCategory::WORK:
        strcpy(temp, "work");
        break;
    case TaskCategory::FOR_HOME:
        strcpy(temp, "for home");
        break;
    case TaskCategory::OTHER:
        strcpy(temp, "other");
        break;
    }

    std::cout << "Category: " << temp << std::endl;
    std::cout << "Deadline: ";
    this->deadline.print();
}