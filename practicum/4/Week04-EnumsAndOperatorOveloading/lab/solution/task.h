#pragma once

#include "taskCategory.h"
#include "date.h"

const std::size_t MAX_TITLE_SIZE = 50;
const std::size_t MAX_DESCRIPTION_SIZE = 500;

class Task
{
private:
    char title[MAX_TITLE_SIZE];
    char description[MAX_DESCRIPTION_SIZE];
    TaskCategory category;
    Date deadline;

public:
    Task();
    Task(const char* title, const char* description, 
            const TaskCategory category, const Date deadline);

    const char* getTitle() const;
    const char* getDescription() const;
    TaskCategory getCategory() const;
    Date getDeadline() const;

    void setTitle(const char* title);
    void setDescription(const char* description);
    void setCategory(const TaskCategory category);
    void setDeadline(const Date deadline);

    bool operator < (const Task& other) const;

    void print() const;
};