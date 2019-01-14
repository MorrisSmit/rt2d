
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

	currentEnemyPokemon = nullptr;
	currentAllyPokemon = nullptr;

	makePokemon();

	makeStartbuttons();
	
	counter = 0;




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
	if (counter == 0)
	{
		std::cout << buttonList[0]->sprite()->height() << std::endl;
		counter = 1;
	}
	

	if (input()->getMouseDown(0)) 
	{
		checkButtonClick();
	}
	if (input()->getKeyUp(KeyCode::Escape)) 
	{
		this->stop();
	}
	if (input()->getKeyUp(KeyCode::Up) && currentAllyPokemon != nullptr && currentEnemyPokemon->isAlive())
	{
		attack();
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
	randNum = rand() % computerTeam.size();
	if (computerTeam[randNum]->isAlive()) 
	{
		activatePokemon(computerTeam[randNum], 1);
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
	std::cout << (int)playerChoice << std::endl;

	if (playerTeam[playerChoice] == nullptr)
	{
		std::cout << "That is not a valid choice!" << std::endl;
		playerSwitch();
	}
	else if (!playerTeam[playerChoice]->isAlive()) 
	{
		std::cout << "that pokemon is not fit for battle anymore!" << std::endl;
		playerSwitch();
	}
	else 
	{
		activatePokemon(playerTeam[playerChoice], 0);
	}	
}

void MyScene::removeButton(Button* button) 
{
	removeChild(button);
	delete button;
}

void MyScene::checkButtonClick() 
{
	for (int i = 0; i < buttonList.size(); i++) {
		buttonList[i]->checkIfPressed();
	}
}

void MyScene::makeStartbuttons() 
{
	cButton = new Button("Charizard");
	cButton->addSprite("assets/charizard_front.tga");
	buttonList.push_back(cButton);
	this->addChild(cButton);
	cButton->setFunction(std::bind(&MyScene::chooseCharizard, this));
	cButton->position = Point2(750, SHEIGHT / 2);
	cButton->scaleText(0.5);
	cButton->setTextyPosition(50);


	vButton = new Button("Venusaur");
	vButton->addSprite("assets/venusaur_front.tga");
	buttonList.push_back(vButton);
	this->addChild(vButton);
	vButton->setFunction(std::bind(&MyScene::chooseVenusaur, this));
	vButton->position = Point2(500, SHEIGHT / 2);
	vButton->scaleText(0.5);
	vButton->setTextyPosition(50);

	bButton = new Button("Blastoise");
	bButton->addSprite("assets/blastoise_front.tga");
	buttonList.push_back(bButton);
	this->addChild(bButton);
	bButton->setFunction(std::bind(&MyScene::chooseBlastoise, this));
	bButton->position = Point2(250, SHEIGHT / 2);
	bButton->scaleText(0.5);
	bButton->setTextyPosition(50);

}

//void MyScene::makeButton(
//	std::string name, Scene* sceneToCall, std::function<void()> functionToCall,float xpos, float ypos, float scale
//) 
//{
//	Button* button = new Button(name);
//	button->setFunction(std::bind(&sceneToCall::functionToCall, this));
//}

void MyScene::chooseCharizard() 
{
	activatePokemon(charizard, 0);
	computerStart();
	removeButtons();
	makeBattleButtons();
}

void MyScene::chooseVenusaur()
{
	activatePokemon(venusaur, 0);
	computerStart();
	removeButtons();
	makeBattleButtons();
}

void MyScene::chooseBlastoise() 
{
	activatePokemon(blastoise, 0);
	computerStart();
	removeButtons();
	makeBattleButtons();
}

void MyScene::makeBattleButtons() 
{
	Button* switchButton = new Button("switch");
	buttonList.push_back(switchButton);
	switchButton->setFunction(std::bind(&MyScene::playerSwitch, this));
	switchButton->position = Point2(250, SHEIGHT - 44);
	switchButton->scaleText(0.2);
	switchButton->scaleButton(Point2(3,3));
	this->addChild(switchButton);
	std::cout << switchButton->sprite() << std::endl;

	Button* attackButton = new Button("attack");
	buttonList.push_back(attackButton);
	attackButton->setFunction(std::bind(&MyScene::attack, this));
	attackButton->position = Point2(500, SHEIGHT - 44);
	attackButton->scaleText(0.2);
	attackButton->scaleButton(Point2(3,3));
	this->addChild(attackButton);
	std::cout << attackButton->sprite()->height() << std::endl;
}
void MyScene::activatePokemon(Pokemon* p, int side) 
{
	if (side == 0)
	{
		currentAllyPokemon = p;
		p->position = allyposition;
		std::cout << "you sent out " << currentAllyPokemon->getName() << "!" << std::endl;
	}
	else 
	{
		currentEnemyPokemon = p;
		p->position = enemyposition;
		std::cout << "The enemy sent out " << currentEnemyPokemon->getName() << "!" << std::endl;
	}
}
void MyScene::removeButtons() 
{
	for (auto it = buttonList.begin(); it != buttonList.end();) {
		removeChild(*it);
		delete (*it); // delete the Bullet from the heap
		it = buttonList.erase(it); // 'remove' from bullet list. 'erase' returns a pointer to the next element in the list.				   //++counter; // uncomment to find the new index
	}
	buttonList.clear();
}




