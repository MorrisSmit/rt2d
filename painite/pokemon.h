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
	virtual void attack(Pokemon *other) = 0;
	std::string getName();
	bool isAlive();

	float type;


protected:
	int health;
	std::string name;
	float _type;
	float attackdamage;


private:


};

#endif /* POKEMON_H */
