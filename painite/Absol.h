/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file absol.h
*
* @brief description of Absol behavior.
*/

#ifndef ABSOL_H
#define ABSOL_H

#include "pokemon.h"

/// @brief The MyEntity class is the Entity implementation.
class Absol : public Pokemon
{
public:
	/// @brief Constructor
	Absol();
	/// @brief Destructor
	virtual ~Absol();

	void takeDamage(int amount);


private:

	std::vector<Move> moveset;
	int health;
	std::string name;
	std::string type;
	//Move tackle;

};

#endif /* ABSOL_H */
