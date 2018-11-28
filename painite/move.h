/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file pokemon.h
*
* @brief description of move behavior.
*/

#ifndef MOVE_H
#define MOVE_H

#include <rt2d/entity.h>
#include <string.h>

/// @brief The MyEntity class is the Entity implementation.
class Move : public Entity
{
public:
	/// @brief Constructor
	Move(int pp, int power, std::string name);
	/// @brief Destructor
	virtual ~Move();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void Move::update(float deltaTime);


private:
	/* add your private declarations */
	int power;
	int pp;
	std::string name;
};

#endif /* ABSOL_H */
