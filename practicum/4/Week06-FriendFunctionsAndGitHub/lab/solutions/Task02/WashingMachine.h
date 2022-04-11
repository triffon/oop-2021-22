#pragma once
#include <iosfwd>

const int MAX_LENGHT = 1024;

class WashingMachine
{
private:
	char make[MAX_LENGHT];
	char model[MAX_LENGHT];
	int capacity;
	double electricity;
	double water;
	
public:
	WashingMachine();
	WashingMachine(const char* make, const char* model, const int capacity, const double electricity, const double water);

	void setMake(const char* make);
	void setModel(const char* model);
	void setCapacity(const int capacity);
	void setElectricity(const double electricity);
	void setWater(const double water);

	const char* getMake() const;
	const char* getModel() const;
	int getCapacity() const;
	double getElectricity() const;
	double getWater() const;
	
    bool operator > (const WashingMachine& other) const;
	
	friend std::istream& operator >> (std::istream& in,  WashingMachine& machine);
    friend std::ostream& operator << (std::ostream& out, const WashingMachine& machine);
};