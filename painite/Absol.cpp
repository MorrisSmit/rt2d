#include "absol.h"



Absol::Absol() : Pokemon()
{
	moveset;
	health = 20;
	name = "Absol";
	type = "dark";
	//tackle = new Move(10, 30, "tackle");
}


Absol::~Absol()
{

}


void Absol::takeDamage(int amount)
{
	this->health -= amount;
	
}


