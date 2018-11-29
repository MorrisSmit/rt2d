/**
 * This class describes Pokemon behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include "pokemon.h"
#include <vector>


Pokemon::Pokemon() : Entity()
{
	_health = 100;
	type = "normal";
	name = "unknown";
	tackle = new Move(30, 20, "tackle");

}

Pokemon::~Pokemon()
{

}

void Pokemon::update(float deltaTime)
{
	
}

void Pokemon::takeDamage(int amount)
{
	this->_health -= amount;
}

int Pokemon::gethealth()
{
	return _health;
}
