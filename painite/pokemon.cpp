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

void Pokemon::attack(Pokemon* p) 
{
	p->takeDamage(20);
}

void Pokemon::takeDamage(int amount)
{
	if ((this->health - amount) <= 0) 
	{
		this->addSprite("assets/square.tga");
		this->health -= amount;
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
