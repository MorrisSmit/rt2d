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
#include "move.h"
#include <vector>

/// @brief The Pokemon class is the Entity implementation.
class Pokemon : public Entity
{
public:
	/// @brief Constructor
	Pokemon();
	/// @brief Destructor
	virtual ~Pokemon();


	void Pokemon::update(float deltaTime);
	void takeDamage(int amount);
	int getHealth();
	void attack(Pokemon *p);
	std::string getName();
	bool isAlive();


protected:
	int health;
	std::vector<Move> moveset;
	std::string name;
	std::string type;
	Move* tackle;

private:

};

#endif /* POKEMON_H */
