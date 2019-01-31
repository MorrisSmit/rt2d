#include "venusaur.h"



Venusaur::Venusaur(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	name = "Venusaur";
	_type = 2;
	type = _type;
	attackdamage = 20;
	if (side == 1)
	{
		this->addSprite("assets/venusaur_front.tga");
	}
	else
	{
		this->addSprite("assets/venusaur_back.tga");
	}
}

void Venusaur::attack(Pokemon *other)
{
	if (other != nullptr)
	{
		if (other->type == 1)
		{
			attackdamage = attackdamage * 0.75;
		}
		else if (other->type == 3)
		{
			attackdamage = attackdamage * 1.5;
		}
		other->takeDamage(attackdamage);
		attackdamage = 20;
	}
}

Venusaur::~Venusaur()
{

}

