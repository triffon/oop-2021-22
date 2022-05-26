#include "Commander.h"
#include <exception>
#include <iostream>
#include <string.h>

static const unsigned short reduceWith = 8;

template <typename T>
Commander::Commander() : fDescription(nullptr), fSquad(nullptr), fSize(0), fCapacity(0) {}

template <typename T>
Commander::Commander( const char* name, unsigned short age, unsigned short salary,
	T combatSkills, const char* desc, size_t fCapacity )
	: Soldier( name, age, salary, combatSkills )
	, fCapacity( fCapacity ), fSize( 0 ), fDescription( nullptr ), fSquad( nullptr )
{
	this->init( desc, fCapacity );
}

template <typename T>
Commander::Commander( const Soldier<T>& soldier, const char * desc, size_t fCapacity ) 
			: Soldier( soldier )
{
	this->init( desc, fCapacity );
}

template <typename T>
Commander::Commander( const Commander& other ) : Soldier( other )
{
	this->copy( other );
}

template <typename T>
Commander& Commander::operator=( const Commander & other )
{
	if ( this != &other )
	{
		Soldier::operator=( other );
		this->clean();
		this->copy( other );
	}
	return *this;
}

template <typename T>
Commander::~Commander()
{
	this->clean();
}

template <typename T>
void Commander::copy( const Commander & other )
{
	this->init( other.fDescription, other.fCapacity );

	fSize = other.fSize;
	fCapacity = other.fCapacity;
	Soldier::copy( other );

	for (int i = 0; i < other.fSize; ++i) 
	{
		fSquad[ i ] = other.fSquad[ i ];
	}

}

template <typename T>
void Commander::clean()
{
	delete[] fDescription;
	fDescription = nullptr;
	delete[] fSquad;
	fSquad = nullptr;
}

template <typename T>
void Commander::init( const char* desc, size_t fCapacity )
{
	try
	{
		fDescription = new char[ strlen( desc ) + 1 ];

		strcpy( fDescription, desc );

		fSquad = new Soldier[ fCapacity ];
	}
	catch ( std::bad_alloc& e )
	{
		Soldier::clean();
		//this->clean();
		Commander::clean();

		std::cerr << "Not enough memory to create new squad! \n";
		throw;
	}
}

template <typename T>
bool Commander::resize()
{
	int newCapacity = fCapacity * 2;
	Soldier<T>* newArmy = nullptr;

	do
	{
		try
		{
			newArmy = new Soldier<T>[ newCapacity ];
		}
		catch ( std::bad_alloc& e )
		{
			newCapacity -= reduceWith;
		}
	}
	while ( ( newCapacity > fCapacity ) && !newArmy );

	if ( !newArmy )
	{
		return false;
	}

	for ( int i = 0; i < fSize; ++i )
	{
		newArmy[ i ] = fSquad[ i ];
	}
	delete[] fSquad;
	fSquad = newArmy;
	fCapacity = newCapacity;

	return true;
}

template <typename T>
bool Commander::addSoldier( const Soldier<T>& soldier )
{
	bool result = true;
	if ( fSize >= fCapacity )
	{
		result = this->resize();
	}
	fSquad[ fSize++ ] = soldier;
 	return result;
}

template <typename T>
unsigned int Commander::getSquadSalary() const
{

	unsigned int squadSalary = this->getSalary(); // starting from sergeant's salary

	for ( size_t i = 0; i < fSize; i++ )
		squadSalary += fSquad[ i ].getSalary();

	return squadSalary;
}

template <typename T>
unsigned int Commander::getSquadSize() const
{
	return fSize + 1; // +1 for the sergeant
}

template <typename T>
T Commander::getSquadCombatSkills() const
{

	T squadCombatSkills = this->getCombatSkills();

	for ( size_t i = 0; i < fSize; i++ )
		squadCombatSkills += fSquad[ i ].getCombatSkills();

	return squadCombatSkills;
}
