
/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <cstdlib>

#include "myscene.h"
#include "blastoise.h"
#include "charizard.h"
#include "venusaur.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	allyposition = Point(250, 500);
	enemyposition = Point(500, 250);

	makePokemon();

	//charizard button
	cButton = new Button("Charizard");
	cButton->addSprite("assets/charizard_front.tga");
	cButton->setFunction(std::bind(&MyScene::chooseCharizard, this));
	cButton->position = Point2(750, 600);
	cButton->scaleText(0.5);
	cButton->setTextyPosition(50);
	buttonList.push_back(cButton);

	//charizard health text
	cHealth = new Text();
	cHealth->scale = Point2(0.3, 0.3);
	cHealth->position = Point2(900, 600);

	//venusaur button
	vButton = new Button("Venusaur");
	vButton->addSprite("assets/venusaur_front.tga");
	vButton->setFunction(std::bind(&MyScene::chooseVenusaur, this));
	vButton->position = Point2(750, 500);
	vButton->scaleText(0.5);
	vButton->setTextyPosition(50);
	buttonList.push_back(vButton);


	//venusaur health text
	vHealth = new Text();
	vHealth->scale = Point2(0.3, 0.3);
	vHealth->position = Point2(900, 500);

	//blastoise button
	bButton = new Button("Blastoise");
	bButton->addSprite("assets/blastoise_front.tga");
	bButton->setFunction(std::bind(&MyScene::chooseBlastoise, this));
	bButton->position = Point2(750, 400);
	bButton->scaleText(0.5);
	bButton->setTextyPosition(50);
	buttonList.push_back(bButton);

	//blastoise health text
	bHealth = new Text();
	bHealth->scale = Point2(0.3, 0.3);
	bHealth->position = Point2(900, 400);

	//switch button
	switchButton = new Button("switch");
	switchButton->setFunction(std::bind(&MyScene::playerSwitch, this));
	switchButton->position = Point2(250, SHEIGHT - 44);
	switchButton->scaleText(0.2);
	switchButton->scaleButton(Point2(3, 3));
	buttonList.push_back(switchButton);

	//attack button
	attackButton = new Button("attack");
	attackButton->setFunction(std::bind(&MyScene::attack, this));
	attackButton->position = Point2(500, SHEIGHT - 44);
	attackButton->scaleText(0.2);
	attackButton->scaleButton(Point2(3, 3));
	buttonList.push_back(attackButton);


	//set current ally and enemy pokemon to NULL
	currentEnemyPokemon = nullptr;
	currentAllyPokemon = nullptr;



	makeStartbuttons();
	



	//std::cout << "main\n";
}


MyScene::~MyScene()
{
	this->removeChild(venusaur);
	this->removeChild(venusaur2);
	this->removeChild(blastoise);
	this->removeChild(blastoise2);
	this->removeChild(charizard);
	this->removeChild(charizard2);

	// delete pokemon from the heap (there was a 'new' in the constructor)
	delete venusaur;
	delete venusaur2;
	delete blastoise;
	delete blastoise2;
	delete charizard;
	delete charizard2;
}

void MyScene::update(float deltaTime)
{	

	if (input()->getMouseDown(0)) 
	{
		checkButtonClick();
	}
	if (input()->getKeyUp(KeyCode::Escape)) 
	{
		this->stop();
	}

}

void MyScene::makePokemon() 
{
	venusaur = new Venusaur(0);
	this->addChild(venusaur);
	playerTeam.push_back(venusaur);

	blastoise = new Blastoise(0);
	this->addChild(blastoise);
	playerTeam.push_back(blastoise);

	charizard = new Charizard(0);
	this->addChild(charizard);
	playerTeam.push_back(charizard);
	
	venusaur2 = new Venusaur(1);
	this->addChild(venusaur2);
	computerTeam.push_back(venusaur2);

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
	
	activatePokemon(computerTeam[randNum], 1);
	std::cout << "The enemy sent out " << (currentEnemyPokemon->getName()) << "!" << std::endl;
	
}

void MyScene::computerSwitch()
{
	deactivatePokemon(1);
	randNum = rand() % computerTeam.size();
	if (computerTeam[randNum]->isAlive()) 
	{
		activatePokemon(computerTeam[randNum], 1);
		std::cout << "The enemy sent out " << currentEnemyPokemon->getName() << "!" << std::endl;
	}
	else if(!computerTeam[0]->isAlive() && !computerTeam[1]->isAlive() && !computerTeam[2]->isAlive())
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
		std::cout << "your " << currentAllyPokemon->getName() << " fainted" << std::endl;
		playerSwitch();
	}
}

void MyScene::playerSwitch() 
{

	this->addChild(cButton);
	charizardHealth.clear();
	charizardHealth << "Remaining health: " << charizard->getHealth();
	cHealth->message(charizardHealth.str());
	this->addChild(cHealth);

	cButton->position = Point2(800, 600);


	this->addChild(vButton);
	venusaurHealth.clear();
	venusaurHealth << "Remaining health: " << venusaur->getHealth();
	vHealth->message(venusaurHealth.str());
	this->addChild(vHealth);

	vButton->position = Point2(800, 500);


	this->addChild(bButton);
	blastoiseHealth.clear();
	blastoiseHealth << "Remaining health: " << blastoise->getHealth();
	bHealth->message(blastoiseHealth.str());
	this->addChild(bHealth);

	bButton->position = Point2(800, 400);

	/*Button* baButton;
	baButton = new Button("Back");
	buttonList.push_back(baButton);
	this->addChild(baButton);
	baButton->setFunction(std::bind(&MyScene::removeButtons, this));
	baButton->position = Point2(400, SHEIGHT - 32);
	baButton->scaleText(0.5);
	baButton->setTextyPosition(50);*/
}

void MyScene::removeButton(Button* button) 
{
	removeChild(button);
}

void MyScene::checkButtonClick() 
{
	for (int i = 0; i < buttonList.size(); i++) {
		buttonList[i]->checkIfPressed();
	}
}

void MyScene::makeStartbuttons() 
{
	this->addChild(cButton);
	cButton->position = Point2(750, SHEIGHT / 2);
	cButton->scaleText(0.5);
	cButton->setTextyPosition(50);


	this->addChild(vButton);
	vButton->position = Point2(500, SHEIGHT / 2);
	vButton->scaleText(0.5);
	vButton->setTextyPosition(50);


	this->addChild(bButton);
	bButton->position = Point2(250, SHEIGHT / 2);
	bButton->scaleText(0.5);
	bButton->setTextyPosition(50);
}


void MyScene::chooseCharizard() 
{
	if (currentAllyPokemon != nullptr) 
	{
		deactivatePokemon(0);
	}
	activatePokemon(charizard, 0);
	computerStart();
	removeButton(vButton);
	removeButton(cButton);
	removeButton(bButton);
	this->removeChild(cHealth);
	this->removeChild(vHealth);
	this->removeChild(bHealth);
	makeBattleButtons();

}

void MyScene::chooseVenusaur()
{
	if (currentAllyPokemon != nullptr)
	{
		deactivatePokemon(0);
	}
	activatePokemon(venusaur, 0);
	computerStart();
	removeButton(vButton);
	removeButton(cButton);
	removeButton(bButton);
	this->removeChild(cHealth);
	this->removeChild(vHealth);
	this->removeChild(bHealth);
	makeBattleButtons();
}

void MyScene::chooseBlastoise() 
{
	if (currentAllyPokemon != nullptr)
	{
		deactivatePokemon(0);
	}
	activatePokemon(blastoise, 0);
	computerStart();
	removeButton(vButton);
	removeButton(cButton);
	removeButton(bButton);
	this->removeChild(cHealth);
	this->removeChild(vHealth);
	this->removeChild(bHealth);
	makeBattleButtons();
	
}

void MyScene::makeBattleButtons() 
{
	this->addChild(switchButton);

	this->addChild(attackButton);
}

void MyScene::activatePokemon(Pokemon* p, int side) 
{
	if (side == 0)
	{
		currentAllyPokemon = p;
		currentAllyPokemon->position = allyposition;
		std::cout << "you sent out " << currentAllyPokemon->getName() << "!" << std::endl;
	}
	else 
	{
		currentEnemyPokemon = p;
		currentEnemyPokemon->position = enemyposition;
		std::cout << "The enemy sent out " << currentEnemyPokemon->getName() << "!" << std::endl;
	}
}

void MyScene::deactivatePokemon(int side) 
{
	if (side == 0) 
	{
		currentAllyPokemon->position = Point2(0, 1250);
		currentAllyPokemon = nullptr;
	}
	else
	{
		currentEnemyPokemon->position = Point2(0, 1250);
		currentEnemyPokemon = nullptr;
	}
}





