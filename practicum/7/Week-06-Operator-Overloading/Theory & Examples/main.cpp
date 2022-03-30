#include "IntArr.h"
#include <iostream>

int main() {

	IntArr arr1;
	IntArr arr2 = arr1 + 5 + 10 + 3;

	std::cout << "arr2: \n";
	arr2.print();

	std::cout << "\narr1: \n";
	arr1.print();

	std::cout << "\nIs arr1 empty: " << std::boolalpha << !arr1
		<< "\nIs arr2 empty: " << std::boolalpha << !arr2 << std::endl;

	arr1 += 2;
	arr1 += 4;

	std::cout << "\narr1: \n";
	arr1.print();
	
	std::cout << "\nIs arr2 bigger than arr1: " << std::boolalpha << (arr2 > arr1) << std::endl;

	std::cout << "\narr1++: \n";
	(arr1++);
	arr1.print();

	IntArr arr3 = arr1 + arr2;

	std::cout << "\narr3: \n";
	arr3.print();

	arr3 *= 2;
	std::cout << "\nDoubled arr3: \n";
	arr3.print();

	std::cout << "\nElement 3 of arr3: \n" << arr3[3] << std::endl;

	return 0;
}