#include <iostream>
#include "CommandsHelper.h"
#include "Students.h"
#include "Program.h"

int main() {

	Program p;
	p.start();

	char command[32];

	int commandNumber;
	CommandsHelper::printCommands();
	do {
		std::cout << "Enter your command: ";
		std::cin >> command;
		commandNumber = CommandsHelper::getCommand(command);
		switch (commandNumber)
		{
			case ADD:  p.executeAdd(); break;
			case help: CommandsHelper::printCommands(); break;
			case notFound: std::cout << "Command not found, try again\n"; break;
			default: break;
		}

	} while (commandNumber != exitProgram);

	DBManager::save();
	return 0;
}