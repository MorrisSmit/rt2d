#include "charizard.h"



Charizard::Charizard(int side) : Pokemon()
{
	this->scale = Point(4.0f, 4.0f);
	attackdamage = 20;
	this->_type = 1;
	type = _type;
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

 void Charizard::attack(Pokemon *other) 
{
	 if (other != nullptr)
	 {
		 if (other->type == 3)
		 {
			 attackdamage = attackdamage * 0.75;
		 }
		 else if (other->type == 2)
		 {
			 attackdamage = attackdamage * 1.5;
		 }
		 other->takeDamage(attackdamage);
		 attackdamage = 20;
	 }
}


Charizard::~Charizard()
{

}

void Charizard::calculateDamage(float def, float att)
{

}

