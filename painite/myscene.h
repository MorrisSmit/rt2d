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
#include "button.h"
#include <vector>

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
	void checkButtonClick();

	void makeButton();
	void test();


	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	Pokemon* venusaur;
	Pokemon* blastoise;
	Pokemon* charizard;
	
	Pokemon* venusaur2;
	Pokemon* blastoise2;
	Pokemon* charizard2;

	int randNum;
	int playerChoice;

	Button* testButton;
	std::vector<Button*> buttonList;

	Timer t;
	Point allyposition;
	Point enemyposition;

	std::vector<Pokemon*> playerTeam;
	std::vector<Pokemon*> computerTeam;

	Pokemon* currentAllyPokemon;
	Pokemon* currentEnemyPokemon;
};

#endif /* MYSCENE_H */
