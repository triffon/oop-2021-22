#pragma once


template <typename T>
class Soldier
{
protected:
	char* fName;
	unsigned short fAge;
	unsigned short fSalary;
	T fCombatSkills;
	
public:
	Soldier();
	Soldier( const char* name, unsigned short age, unsigned short salary, T combatSkills );
	Soldier( const Soldier& other );
	Soldier& operator=( const Soldier& other );
	~Soldier();

protected:
	void copy( const Soldier& other );
	void clean();

	void init( const char* name, unsigned short age, unsigned short salary, T combatSkills );

public:
	unsigned short getSalary() const;
	T getCombatSkills() const;
	const char* getName() const;
};
