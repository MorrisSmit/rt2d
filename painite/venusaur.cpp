#include "venusaur.h"



Venusaur::Venusaur(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	name = "Venusaur";
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
	other->takeDamage(20);
}

Venusaur::~Venusaur()
{

}

