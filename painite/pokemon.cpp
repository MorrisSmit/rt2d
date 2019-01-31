/**
 * This class describes Pokemon behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include "pokemon.h"
#include <vector>


 Pokemon::Pokemon() : Entity()
{
	health = 100;
	name = "unknown";
	this->position = Point(0, 1250);
}

Pokemon::~Pokemon()
{

}

void Pokemon::update(float deltaTime)
{
	
}


void Pokemon::takeDamage(int amount)
{
	if ((this->health - amount) <= 0) 
	{
		this->health -= amount;
		this->position = Point(0, 1250);
	}
	else {
		this->health -= amount;
	}
	
}

int Pokemon::getHealth()
{
	return health;
}

std::string Pokemon::getName() 
{
	return name;
}

bool Pokemon::isAlive() 
{
	if (this->health <= 0)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
