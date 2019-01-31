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
#include "blastoise.h"
#include "venusaur.h"
#include "charizard.h"
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
	void computerSwitch();
	void attack();
	void enemyAttack();
	void playerSwitch();
	void activatePokemon(Pokemon* p, int side);
	void deactivatePokemon(int side);

	void chooseBlastoise();
	void chooseVenusaur();
	void chooseCharizard();

	void checkButtonClick();

	void makeStartbuttons();

	void removeButton(Button* button);

	void makeBattleButtons();

	void updateText();

	void emptyTextstr();

	//void makeButton(std::string name, std::function<void()> functionToCall, float xpos, float ypos, float scale);
	

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltatime);

private:
	/// @brief the rotating square in the middle of the screen
	Pokemon* venusaur;
	Pokemon* blastoise;
	Pokemon* charizard;
	
	Pokemon* venusaur2;
	Pokemon* blastoise2;
	Pokemon* charizard2;

	int randNum;

	Button* bButton;
	Button* vButton;
	Button* cButton;
	Button* switchButton;
	Button* attackButton;
	std::vector<Button*> buttonList;

	Text* cHealth;
	Text* vHealth;
	Text* bHealth;
	
	std::stringstream charizardHealth;
	std::stringstream venusaurHealth;
	std::stringstream blastoiseHealth;

	std::stringstream UiTextstr;
	std::stringstream UiText2str;

	Text* UiText;
	Text* UiText2;

	Timer t;
	Point allyposition;
	Point enemyposition;

	int checkIfGameOver();
	void endGame();

	std::vector<Pokemon*> playerTeam;
	std::vector<Pokemon*> computerTeam;

	Pokemon* currentAllyPokemon;
	Pokemon* currentEnemyPokemon;
};

#endif /* MYSCENE_H */
