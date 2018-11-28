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

	// create a single instance of absol in the middle of the screen.
	// the Sprite added in Constructor of absol.
	absol = new Absol();
	absol->position = Point2(250, 500);
	absol->scale = Point(4.0f, 4.0f);
	absol->addSprite("assets/absol_back.tga");
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(absol);

	absol2 = new Absol();
	absol2->position = Point2(500, 250);
	absol2->scale = Point(4.0f, 4.0f);
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
		absol->takeDamage(10);
		std::cout << "123" << std::endl;
	}

	


}
