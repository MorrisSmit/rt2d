/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file pokemon.h
*
* @brief description of Pokemon behavior.
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

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void update(float deltaTime);


private:
	/* add your private declarations */
};

#endif /* ABSOL_H */
