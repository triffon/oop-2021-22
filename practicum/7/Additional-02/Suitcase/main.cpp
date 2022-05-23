#include "Suitcase.h"
#include "ClothingItem.h"
#include "Dress.h"
#include "Pants.h"
#include "Suit.h"
#include "Person.h"

int main() {
	Person pesho("Pesho", "Sofia, James Boucher, 105", "+35965273663");

	Suitcase s("bembeno", &pesho);

	Dress dress("red", "M", 105, 95);
	Pants pants("black", "L", 50, 100);
	Suit suit("yellow", "XL", 86);

	s.addClothing(&dress);
	s.addClothing(&pants);
	s.addClothing(&suit);
	
	s.print(std::cout);

	std::cout << std::boolalpha << s.isInsideColor("red") << "\n";
	std::cout << std::boolalpha << s.isInsideType(Type::PANTS) << "\n";
	std::cout << std::boolalpha << s.isInsideTypeColor(Type::PANTS, "red") << "\n";

	ClothingItem* removed = s.removeClothing(2);
	if (removed)
		removed->print(std::cout);

	s.print(std::cout);

	return 0;
}
