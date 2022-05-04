#pragma once
#include "Students.h"
#include "DBManager.h"

class Program {
private:
	Students students;

public:
	void start()
	{
		DBManager::readStudentsInfoFromDB(students);
	}
	void executeAdd() {
		Student st;
		students.add(st);
	}
};