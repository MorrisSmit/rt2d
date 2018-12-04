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

	//std::cout << "main\n";
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(absol);
	this->removeChild(absol2);
	this->removeChild(blastoise);
	this->removeChild(blastoise2);

	// delete absol from the heap (there was a 'new' in the constructor)
	delete absol;
	delete absol2;
	delete blastoise;
	delete blastoise2;
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
		currentAllyPokemon->attack(currentEnemyPokemon);
		std::cout << "The enemy " << currentEnemyPokemon->getName() << " took damage! Remaining health: " << currentEnemyPokemon->getHealth() << std::endl;
		if (!currentEnemyPokemon->isAlive()) 
		{
			std::cout << "The enemy " << currentEnemyPokemon->getName() << " fainted" << std::endl;
			computerSwitch();
			
			
		}
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

}
void MyScene::makePokemon() 
{
	
	absol = new Absol(0);
	blastoise = new Blastoise(0);
	this->addChild(absol);
	playerTeam.push_back(absol);
	this->addChild(blastoise);
	playerTeam.push_back(blastoise);
	
	absol2 = new Absol(1);
	blastoise2 = new Blastoise(1);
	this->addChild(absol2);
	computerTeam.push_back(absol2);
	this->addChild(blastoise2);
	computerTeam.push_back(blastoise2);
}

void MyScene::computerStart() 
{
	srand(time(nullptr));
	randNum = rand() % 2;
	if (randNum == 1) 
	{
		std::cout << "The enemy sent out Absol!" << std::endl;
		currentEnemyPokemon = computerTeam[0];
		computerTeam[0]->position = enemyposition;
		std::cout << "The enemy sent out " << (currentEnemyPokemon->getName()) << "!" << std::endl;
	}
	else 
	{
		std::cout << "The enemy sent out Blastoise!" << std::endl;
		currentEnemyPokemon = computerTeam[1];
		computerTeam[1]->position = enemyposition;
		std::cout << "The enemy sent out " << (currentEnemyPokemon->getName()) << "!" << std::endl;
	}
}

void MyScene::computerSwitch()
{
	randNum = rand() % 2;
	if (randNum == 0 && computerTeam[randNum]->isAlive()) 
	{
		currentEnemyPokemon = computerTeam[0];
		computerTeam[0]->position = enemyposition;
		std::cout << "The enemy sent out " << currentEnemyPokemon->getName() << "!" << std::endl;
	}
	else if (computerTeam[1]->isAlive())
	{
		currentEnemyPokemon = computerTeam[1];
		computerTeam[1]->position = enemyposition;
		std::cout << "The enemy sent out " << currentEnemyPokemon->getName() << "!" << std::endl;
	}
	else 
	{
		std::cout << "You won!" << std::endl;
	}
}



