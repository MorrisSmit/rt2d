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
#include "move.h";
#include <vector>

/// @brief The MyEntity class is the Entity implementation.
class Pokemon : public Entity
{
public:
	/// @brief Constructor
	Pokemon();
	/// @brief Destructor
	virtual ~Pokemon();


	void Pokemon::update(float deltaTime);
	void takeDamage(int amount);
	int gethealth();

protected:
	int _health;
	std::vector<Move> moveset;
	std::string name;
	std::string type;
	Move* tackle;

private:
	/* add your private declarations */

};

#endif /* POKEMON_H */
