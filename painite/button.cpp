#include "button.h"

Button::Button(std::string name)
{
	this->addSprite("assets/Button.tga");

	text = new Text();
	text->message(name, WHITE);
	scaleText(0.45);
	float x = -20;
	text->position.x = x;

	this->addChild(text);
}

Button::~Button()
{
   
}

void Button::update(float deltatime) 
{

}

void Button::checkIfPressed()
{
	mouseX = input()->getMouseX();
	mouseY = input()->getMouseY();
	xPos = position.x - ((this->sprite()->width() * scale.x) / 2);
	yPos = position.y - ((this->sprite()->height() * scale.y) / 2);
	if (mouseX > xPos && mouseX < xPos + (this->sprite()->width() * scale.x) && mouseY > yPos && mouseY < yPos + (this->sprite()->height() * scale.y)) 
	{
		this->sprite()->color = RED;
		doFunction();
	}
}


void Button::setFunction(std::function<void()> value) 
{
	doFunction = value;
}

void Button::scaleText(float scale) 
{
	text->scale = Point2(scale, scale);
}
