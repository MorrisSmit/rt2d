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
	Absol(int side);
	/// @brief Destructor
	virtual ~Absol();


private:
	Absol();

};

#endif /* ABSOL_H */
