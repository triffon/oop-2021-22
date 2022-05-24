#pragma once

#include "Soldier.h"

template <typename T>
class Commander : public Soldier<T>
{
	Soldier<T>* fSquad;
	size_t fSize;
	size_t fCapacity;
	char* fDescription;

public:
	Commander();
	Commander( const char* name, unsigned short age, unsigned short salary, T combatSkills,
					const char* desc, size_t fCapacity = 16 );
	Commander( const Soldier<T>& soldier, const char* desc, size_t fCapacity = 16 );
	Commander( const Commander& other );
	Commander& operator=( const Commander& other );
	~Commander();


private:
	void copy( const Commander& other );
	void clean();
	void init( const char* desc, size_t fCapacity );
	bool resize();

public:
	bool addSoldier( const Soldier<T>& soldier );
	unsigned int getSquadSalary() const;
	unsigned int getSquadSize() const;
	T getSquadCombatSkills() const;
	
};
