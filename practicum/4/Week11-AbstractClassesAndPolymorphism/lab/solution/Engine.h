#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

#include "Utility.h"

#include "Furniture.h"
#include "Table.h"
#include "Chair.h"
#include "Bed.h"

#include "FurnitureHouse.h"

class Engine {
public:
	static Engine& getInstance();

	void run();

private:
	Engine();
	Engine(const Engine& engine) = delete;
	Engine& operator=(const Engine& other) = delete;

private:
	FurnitureHouse m_furnitureHouse;

	void printOperations();
	void enterOperation(char& operation) const;
	void executeOperation(const char operation);

	const int getFurnitureIdFromUser() const;
	Furniture* getFurnitureAtID(const int id) const;

	void addFurniture();
	Furniture* getFurnitureTypeFromUser() const;
	const std::string getValidFurnitureTypeFromUser() const;
	const bool checkIfFurnitureExists(Furniture* furniture);

	void removeFurnitureByID();
	void removeFurniture(Furniture* furniture);

	void printFurnitureByID() const;

	void printTheMostExpensiveFurniture() const;
	const Furniture* getTheMostExpensiveFurniture() const;
};

#endif // !ENGINE_H
