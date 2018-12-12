/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file absol.h
*
* @brief description of Absol behavior.
*/

#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "pokemon.h"

/// @brief The MyEntity class is the Entity implementation.
class Charizard : public Pokemon
{
public:
	/// @brief Constructor
	Charizard(int side);
	/// @brief Destructor
	virtual ~Charizard();


private:
	Charizard();

};

#endif /* CHARIZARD_H */
