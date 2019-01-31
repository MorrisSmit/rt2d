#include "move.h"



Move::Move(int _power, std::string _name, int _type ) : Entity()
{
	power = _power;
	name = _name;
	type = _type;
}


Move::~Move()
{

}

void Move::update(float deltatime)
{

}






