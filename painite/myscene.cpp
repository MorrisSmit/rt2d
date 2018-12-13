/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <cstdlib>

#include "myscene.h"
#include "absol.h"
#include "blastoise.h"
#include "charizard.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	allyposition = Point(250, 500);
	enemyposition = Point(500, 250);

	currentEnemyPokemon = nullptr;
	currentAllyPokemon = nullptr;
	

	makePokemon();


	std::cout << "which pokemon would u like to send out first? " << std::endl;
	std::cout << "press A for absol " << std::endl;
	std::cout << "press S for blastoise " << std::endl;
	std::cout << "press D for charizard " << std::endl;

	//std::cout << "main\n";
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(absol);
	this->removeChild(absol2);
	this->removeChild(blastoise);
	this->removeChild(blastoise2);
	this->removeChild(charizard);
	this->removeChild(charizard2);

	// delete absol from the heap (there was a 'new' in the constructor)
	delete absol;
	delete absol2;
	delete blastoise;
	delete blastoise2;
	delete charizard;
	delete charizard2;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) 
	{
		this->stop();
	}
	if (input()->getKeyUp(KeyCode::Up) && currentAllyPokemon != nullptr && currentEnemyPokemon->isAlive())
	{
		attack();
	}
	if (input()->getKeyUp(KeyCode::A) && currentAllyPokemon == nullptr)
	{
		std::cout << "you sent out " << absol->getName()<< "!" << std::endl;
		playerTeam[0]->position = allyposition;
		currentAllyPokemon = playerTeam[0];
		computerStart();
	}
	if (input()->getKeyUp(KeyCode::S) && currentAllyPokemon == nullptr)
	{
 		std::cout << "you sent out "<< playerTeam[1]->getName() << "!"  <<  std::endl;
		playerTeam[1]->position = allyposition;
		currentAllyPokemon = playerTeam[1];
		computerStart();
	}
	if (input()->getKeyUp(KeyCode::D) && currentAllyPokemon == nullptr)
	{
		std::cout << "you sent out " << playerTeam[2]->getName() << "!" << std::endl;
		playerTeam[2]->position = allyposition;
		currentAllyPokemon = playerTeam[2];
		computerStart();
	}

}
void MyScene::makePokemon() 
{
	absol = new Absol(0);
	this->addChild(absol);
	playerTeam.push_back(absol);

	blastoise = new Blastoise(0);
	this->addChild(blastoise);
	playerTeam.push_back(blastoise);

	charizard = new Charizard(0);
	this->addChild(charizard);
	playerTeam.push_back(charizard);
	

	absol2 = new Absol(1);
	this->addChild(absol2);
	computerTeam.push_back(absol2);

	blastoise2 = new Blastoise(1);
	this->addChild(blastoise2);
	computerTeam.push_back(blastoise2);

	charizard2 = new Charizard(1);
	this->addChild(charizard2);
	computerTeam.push_back(charizard2);
}

void MyScene::computerStart() 
{
	srand(time(nullptr));
	randNum = rand() % 2;
	
	currentEnemyPokemon = computerTeam[randNum];
	computerTeam[randNum]->position = enemyposition;
	std::cout << "The enemy sent out " << (currentEnemyPokemon->getName()) << "!" << std::endl;
	
}

void MyScene::computerSwitch()
{
	randNum = rand() % computerTeam.size();
	if (computerTeam[randNum]->isAlive()) 
	{
		currentEnemyPokemon = computerTeam[randNum];
		computerTeam[randNum]->position = enemyposition;
		std::cout << "The enemy sent out " << currentEnemyPokemon->getName() << "!" << std::endl;
	}
	else if(!computerTeam[0]->isAlive() && !computerTeam[1]->isAlive() && !computerTeam[1]->isAlive())
	{
		std::cout << "You won!" << std::endl;
		this->stop();
	}
}
void MyScene::attack() 
{
	currentAllyPokemon->attack(currentEnemyPokemon);
	std::cout << "The enemy " << currentEnemyPokemon->getName() << " took damage! Remaining health: " << currentEnemyPokemon->getHealth() << std::endl;
	if (!currentEnemyPokemon->isAlive())
	{
		std::cout << "The enemy " << currentEnemyPokemon->getName() << " fainted" << std::endl;
		computerSwitch();
	}
	enemyAttack();
}
void MyScene::enemyAttack() 
{
	currentEnemyPokemon->attack(currentAllyPokemon);
	std::cout << "your " << currentAllyPokemon->getName() << " took damage! Remaining health: " << currentAllyPokemon->getHealth() << std::endl;
	if (!currentAllyPokemon->isAlive())
	{
		currentAllyPokemon->position = Point2(0, 1250);
		std::cout << "your " << currentAllyPokemon->getName() << " fainted" << std::endl;
		playerSwitch();
	}
}
void MyScene::playerSwitch() 
{
	std::cout << "Which pokemon would you like to send out? " << std::endl;
	for (int i = 0; i < playerTeam.size(); i++) {
		std::cout << i  << " " << playerTeam[i]->getName() << " remaining health: " <<  playerTeam[i]->getHealth() <<  std::endl;
	}

	std::cin >> playerChoice;

	if (!playerTeam[playerChoice]->isAlive()) 
	{
		std::cout << "that pokemon is not fit for battle anymore!" << std::endl;
		playerSwitch();
	}
	else if (playerTeam[playerChoice] == NULL) 
	{
		std::cout << "That is not a valid choice!" << std::endl;
		playerSwitch();
	}
	else 
	{
		currentAllyPokemon = playerTeam[playerChoice];
		currentAllyPokemon->position = allyposition;
		std::cout << "You sent out: " << playerTeam[playerChoice]->getName() << "!" << std::endl;
	}	
}
void MyScene::faintPokemon(Pokemon* p)
{
	
}



