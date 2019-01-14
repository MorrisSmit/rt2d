/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file absol.h
*
* @brief description of Absol behavior.
*/

#ifndef BLASTOISE_H
#define BLASTOISE_H

#include "pokemon.h"

/// @brief The MyEntity class is the Entity implementation.
class Blastoise : public Pokemon
{
public:
	/// @brief Constructor
	Blastoise(int side);
	/// @brief Destructor
	virtual ~Blastoise();

	void attack(Pokemon *other);



private:
	Blastoise();

};

#endif /* BLASTOISE_H */
