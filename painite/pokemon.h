/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file pokemon.h
 *
 * @brief description of Pokemon behavior.
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Pokemon : public Entity
{
public:
	/// @brief Constructor
	Pokemon();
	/// @brief Destructor
	virtual ~Pokemon();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void moveLeft();

private:
	/* add your private declarations */
};

#endif /* POKEMON_H */
