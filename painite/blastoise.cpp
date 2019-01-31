
#include "blastoise.h"



Blastoise::Blastoise(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	name = "Blastoise";
	_type = 3;
	type = _type;
	attackdamage = 20;
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
	if (other != nullptr)
	{
		if (other->type == 2)
		{
			attackdamage = attackdamage * 0.75;
		}
		else if (other->type == 1)
		{
			attackdamage = attackdamage * 1.5;
		}
		other->takeDamage(attackdamage);
		attackdamage = 20;
	}
}


Blastoise::~Blastoise()
{

}

