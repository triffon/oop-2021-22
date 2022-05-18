#pragma once
#include "Students.h"
#include <cstring>

const int ADD = 1;
const int edit = 2;
const int removeEl = 3;
const int makesthelse = 4;
const int exitProgram = 5;
const int help = 6;
const int notFound = 0;

class CommandsHelper {

public:
	static void printCommands();
	static int getCommand(const char* command);
};

int CommandsHelper::getCommand(const char* command)
{
	if (strcmp(command, "add") == 0)
	{
		return ADD;
	}
	else if (strcmp(command, "edit") == 0)
	{
		return edit;
	}
	else if (strcmp(command, "remove") == 0)
	{
		return removeEl;
	}
	else if (strcmp(command, "makesthelse") == 0)
	{
		return makesthelse;
	}
	else if (strcmp(command, "exit") == 0)
	{
		return exitProgram;
	}
	else if (strcmp(command, "help") == 0)
	{
		return help;
	}
	else
	{
		return notFound;
	}
}

void CommandsHelper::printCommands() {
	std::cout << "1.Add - adds a student to db\n2.Edit\n.Remove...\3\n";
}