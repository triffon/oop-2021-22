#include "University.h"

int main() {

	University su(10);

	su.hire("Bosa Na Kokosa", ASSOC_PROF, 1000, 100);
	su.hire("Tupcho Neumnikov", ASSOC_PROF, 5000, 80);
	su.hire("Nadi", ASSISTANT, 200, 0);
	su.hire("Shefa Shefa", PROF, 55555, 90);

	su.print();
	
	su.fire("Tupcho"); //Nothing will hapen
	su.fire("Tupcho Neumnikov");

	su.print();

	return 0;
}