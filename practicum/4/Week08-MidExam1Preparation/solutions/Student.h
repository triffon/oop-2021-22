#pragma once

#include <fstream>
/*
Напишете клас Student, съдържащ в себе си име (с точно заделена памет, max 1024 Bytes), 
факултетен номер, група и среден успех. Реализирайте Голяма Четворка (Rule of 3 + Default 
constructor), сетъри и гетъри за съответния  клас и предефинирайте потоците за вход и изход така, 
че да е възможно лесно четене и писане във файл. 
Предефинирайте оператор < (първо сравнявайте по среден успех, ако е еднакъв, сравнявайте по ФН) 
и оператор ==
*/

class Student
{
private:
    char* name;
    int fn;
    int group;
    double averageGrade;

public:
    Student();
    Student(const char* name, int fn, int group, int averageGrade);
    ~Student();
    Student& operator =(const Student &other);
    Student(const Student &other);
    bool operator <(const Student &other);
    bool operator ==(const Student &other);
    int getFn() const;

    friend std::ostream& operator <<(std::ostream& out, const Student &obj);
    friend std::istream& operator >>(std::istream& in, Student &obj);

};