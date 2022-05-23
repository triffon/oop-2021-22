#include "Engine.h"

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

Engine::Engine() {
}

void Engine::run() {
	char operation;

	do {
		printOperations();
		enterOperation(operation);
		executeOperation(operation);

		system("pause");
		system("cls");
	} while (operation != '5');
}

void Engine::printOperations() {
	std::cout << "Select an operation:" << std::endl;
	std::cout << "1) Add a furniture" << std::endl;
	std::cout << "2) Remove a furniture" << std::endl;
	std::cout << "3) Show information about a furniture" << std::endl;
	std::cout << "4) Show information about the most expensive furniture" << std::endl;
	std::cout << "5) Exit" << std::endl;
}

void Engine::enterOperation(char& operation) const {
	std::cout << "Enter: ";

	std::cin >> operation;
}

void Engine::executeOperation(const char operation) {
	if (operation == '1')
		addFurniture();
	else if (operation == '2')
		removeFurnitureByID();
	else if (operation == '3')
		printFurnitureByID();
	else if (operation == '4')
		printTheMostExpensiveFurniture();
	else if (operation == '6')
		m_furnitureHouse.print();
	else if (operation != '5')
		std::cout << "Invalid operation!" << std::endl;
}

const int Engine::getFurnitureIdFromUser() const {
	std::cout << "Enter Furniture Id: ";

	int id;

	std::cin >> id;

	return id;
}

Furniture* Engine::getFurnitureAtID(const int id) const {
	return m_furnitureHouse.getFurnitureAtID(id);
}

void Engine::addFurniture() {
	Furniture* newFurniture = getFurnitureTypeFromUser();

	newFurniture->read(std::cin);

	if (checkIfFurnitureExists(newFurniture)) {
		delete newFurniture;
		newFurniture = nullptr;

		return;
	}

	m_furnitureHouse += newFurniture;
}

Furniture* Engine::getFurnitureTypeFromUser() const {
	std::string furnitureType = getValidFurnitureTypeFromUser();

	if (furnitureType == "bed")
		return new Bed();
	else if (furnitureType == "chair")
		return new Chair();
	else if (furnitureType == "table")
		return new Table();

	return nullptr;
}

const std::string Engine::getValidFurnitureTypeFromUser() const {
	std::cout << "Enter furniture type (bed, chair, table): ";

	std::string furnitureType;

	do {
		std::cin >> furnitureType;

		furnitureType = Utility::toLowerStr(furnitureType);
	} while (furnitureType != "bed" && furnitureType != "chair" && furnitureType != "table");

	return furnitureType;
}

const bool Engine::checkIfFurnitureExists(Furniture* furniture) {
	for (size_t i = 0; i < m_furnitureHouse.size(); ++i) {
		if (m_furnitureHouse[i]->getStrComparator() == furniture->getStrComparator()) {
			m_furnitureHouse[i]->setQuantity(m_furnitureHouse[i]->getQuantity() + furniture->getQuantity());

			--Furniture::COUNTER;

			return true;
		}
	}

	return false;
}

void Engine::removeFurnitureByID() {
	const int ID = getFurnitureIdFromUser();

	Furniture* furniture = getFurnitureAtID(ID);

	if (furniture == nullptr) std::cout << "Invalid ID" << std::endl;
	else removeFurniture(furniture);
}

void Engine::removeFurniture(Furniture* furniture) {
	m_furnitureHouse -= furniture;
}

void Engine::printFurnitureByID() const {
	const int ID = getFurnitureIdFromUser();

	const Furniture* furniture = getFurnitureAtID(ID);

	if (furniture == nullptr) std::cout << "Invalid ID" << std::endl;
	else std::cout << furniture->getInfo() << std::endl;
}

void Engine::printTheMostExpensiveFurniture() const {
	if (m_furnitureHouse.size() == 0)
		std::cout << "There are no furnitures in store!" << std::endl;
	else
		std::cout << getTheMostExpensiveFurniture()->getInfo() << std::endl;
}

const Furniture* Engine::getTheMostExpensiveFurniture() const {
	Furniture* mostExpensiveFurniture = nullptr;

	for (size_t i = 0; i < m_furnitureHouse.size(); ++i)
		if (mostExpensiveFurniture == nullptr ||
			m_furnitureHouse[i]->getPrice() > mostExpensiveFurniture->getPrice())
			mostExpensiveFurniture = (Furniture*) m_furnitureHouse[i];

	return mostExpensiveFurniture;
}
