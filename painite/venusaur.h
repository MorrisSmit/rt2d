/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file venusaur.h
*
* @brief description of Absol behavior.
*/

#ifndef VENUSAUR_H
#define VENUSAUR_H

#include "pokemon.h"

/// @brief The MyEntity class is the Entity implementation.
class Venusaur : public Pokemon
{
public:
	/// @brief Constructor
	Venusaur(int side);
	/// @brief Destructor
	virtual ~Venusaur();


private:
	Venusaur();

};

#endif /* VENUSAUR_H */
