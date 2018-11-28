/**
 * This class describes Pokemon behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include "pokemon.h"
#include <vector>


Pokemon::Pokemon() : Entity()
{
	health = 0;
	type = "normal";
	name = "unknown";

}

Pokemon::~Pokemon()
{

}

void Pokemon::update(float deltaTime)
{
	
}

void Pokemon::takeDamage(int amount) 
{
	this->health -= amount;
}
