#include "Pet.h"

int main() {
	Pet a("Gosho", 13, "mitko", 897221543);
	Pet b("Pesho", 10, "dancho", 997651243);

	a = b;
	a.print();

	return 0;
}