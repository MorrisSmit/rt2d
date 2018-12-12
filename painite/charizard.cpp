#include "charizard.h"



Charizard::Charizard(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	name = "Charizard";
	if (side == 1)
	{
		this->addSprite("assets/charizard_front.tga");
	}
	else
	{
		this->addSprite("assets/charizard_back.tga");
	}
}


Charizard::~Charizard()
{

}

