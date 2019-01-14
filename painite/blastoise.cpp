#include "blastoise.h"



Blastoise::Blastoise(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	name = "Blastoise";
	if (side == 1)
	{
		this->addSprite("assets/blastoise_front.tga");
	}
	else
	{
		this->addSprite("assets/blastoise_back.tga");
	}
}

void Blastoise::attack(Pokemon *other)
{
	other->takeDamage(20);
}


Blastoise::~Blastoise()
{

}

