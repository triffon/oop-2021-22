#include "Soldier.h"
#include <string.h>

template <typename T>
Soldier::Soldier() : fName(nullptr), fAge(0), fSalary(0) { fCombatSkills{}; }

template <typename T>
Soldier::Soldier( const char* name, unsigned short age, unsigned short salary, T combatSkills )
{
	this->init( name, age, salary, combatSkills );
}

template <typename T>
Soldier::Soldier( const Soldier& other )
{
	this->copy( other );
}

template <typename T>
Soldier& Soldier::operator=( const Soldier & other )
{
	if ( this != &other )
	{
		this->clean();
		this->copy( other );

	}
	return *this;
}

template <typename T>
Soldier::~Soldier()
{
	this->clean();
}

template <typename T>
void Soldier::copy( const Soldier & other )
{
	this->init( other.fName, other.fAge, other.fSalary, other.fCombatSkills );
}

template <typename T>
void Soldier::clean()
{
	delete[] fName;
	fName = nullptr;
}

template <typename T>
void Soldier::init( const char * name, unsigned short age, unsigned short salary, T combatSkills )
{
	fName = new char[ strlen( name ) + 1 ];
	strcpy( fName, name );

	fAge = age;
	fSalary = salary;
	fCombatSkills = combatSkills;
}

template <typename T>
unsigned short Soldier::getSalary() const
{
	return fSalary;
}

template <typename T>
T Soldier::getCombatSkills() const
{
	return fCombatSkills;
}

template <typename T>
const char * Soldier::getName() const
{
	return fName;
}
