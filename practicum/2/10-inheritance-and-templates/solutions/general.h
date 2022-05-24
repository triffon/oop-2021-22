#pragma once
#include "Soldier.h"
#include "Commander.h"

template <typename T>
class General : public Soldier<T>
{
	char* fDescription;
	Commander* fArmy;
	unsigned short fSize;
	unsigned short fCapacity;

public:

	General();
	General( const Soldier<T>& other, const char* armyDescription, unsigned short capacity = 16 );
	General( const char* name, unsigned short age, unsigned short salary,
			T combatSkills, const char* armyDescription, unsigned short capacity = 16 );
	General( const General<T>& other );
	General& operator=( const General<T>& other );
	~General();

private:

	unsigned int getArmySize() const;

	void copy( const General<T>& warrior );
	bool resize();
	void clean();
	void init( const char* desc, size_t fCapacity );

public:

	bool addComm( const Commander<T>& warrior );

	unsigned int getArmySalary() const;
	T getArmyCombatSkills() const;
	unsigned int getArmyAverageCombatSkills() const;

	const char* getArmyDesc() const;
	const char* getName() const;

};
