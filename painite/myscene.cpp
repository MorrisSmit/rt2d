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

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite added in Constructor of MyEntity.
	absol = new Absol();
	absol->position = Point2(250, 500);
	absol->scale = Point(4.0f, 4.0f);
	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(absol);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(absol);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete absol;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	

	// ###############################################################
	// Rotate color
	// ###############################################################
	/*if (t.seconds() > 0.0333f) {
		RGBAColor color = absol->sprite()->color;
		absol->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}*/
}
