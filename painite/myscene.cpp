/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
#include "absol.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	allyposition *= (250, 500);
	enemyposition *= (500, 250);
	// create a single instance of absol in the middle of the screen.
	// the Sprite added in Constructor of absol.
	absol = new Absol();
	absol->position = allyposition;
	
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(absol);

	absol2 = new Absol();
	absol2->position = enemyposition;
	
	absol2->addSprite("assets/absol_front.tga");
	this->addChild(absol2);

	std::cout << "main\n";
	
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(absol);
	this->removeChild(absol2);

	// delete absol from the heap (there was a 'new' in the constructor)
	delete absol;
	delete absol2;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	if (input()->getKeyUp(KeyCode::Up)) {
		absol->takeDamage(1);
		std::cout << "absol took damage! remaining health: " <<absol->gethealth() << std::endl;
	}

	


}
