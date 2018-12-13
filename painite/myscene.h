/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>


#include "pokemon.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();
	void makePokemon();
	void computerStart();
	void computerSwitch();
	void attack();
	void enemyAttack();
	void playerSwitch();
	void faintPokemon(Pokemon* p);


	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	Pokemon* absol;
	Pokemon* blastoise;
	Pokemon* charizard;
	
	Pokemon* absol2;
	Pokemon* blastoise2;
	Pokemon* charizard2;

	int randNum;
	int playerChoice;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	Point allyposition;
	Point enemyposition;

	std::vector<Pokemon*> playerTeam;
	std::vector<Pokemon*> computerTeam;

	Pokemon* currentAllyPokemon;
	Pokemon* currentEnemyPokemon;
};

#endif /* MYSCENE_H */
