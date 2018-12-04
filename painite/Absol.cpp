#include "absol.h"



Absol::Absol(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	name = "Absol";
	type = "dark";
	if (side == 1) 
	{
		this->addSprite("assets/absol_front.tga");
	}
	else 
	{
		this->addSprite("assets/absol_back.tga");
	}
}


Absol::~Absol()
{

}

