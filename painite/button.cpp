#include "button.h"

Button::Button(std::string name):Entity()
{
	this->addSprite("assets/Button.tga");

	text = new Text();
	text->message(name, WHITE);
	float x = -25;
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
		doFunction();
	}
}

void Button::setTextxPosition(int x) 
{
	text->position.x = x;
}

void Button::setTextyPosition(int y)
{
	text->position.y = y;
}

void Button::setFunction(std::function<void()> value) 
{
	doFunction = value;
}

void Button::scaleText(float scale) 
{
	text->scale = Point2(scale, scale);
}

void Button::scaleButton(Point2 scale) 
{
	this->scale = scale;
}
