#include "absol.h"



Absol::Absol() : Pokemon()
{
	this->addSprite("assets/absol_back.tga");
	this->scale = Point(4.0f, 4.0f);
	name = "Absol";
	type = "dark";
}


Absol::~Absol()
{

}

