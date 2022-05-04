#pragma once
#include <iostream>
#include "Students.h"

class DBManager {

public:
	static void readStudentsInfoFromDB(Students& students);
	static void save();
};

void DBManager::readStudentsInfoFromDB(Students& students) {

	std::cout << "Data was read successfully\n";
}

void DBManager::save()
{
	std::cout << "Successfully saved all the information\n";
}
