#include "button.h"

Button::Button(std::string name)
{
	this->addSprite("assets/Button.tga");

	text = new Text();
	text->message(name, WHITE);

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
	if (mouseX > xPos && mouseX < xPos + (this->sprite()->width() * scale.x) && mouseY > yPos && mouseY < yPos + (this->sprite()->height() * scale.y)) {
		this->sprite()->color = RED;
		runFunction();
	}
}
void Button::runFunction() 
{

}

void Button::setFunction(std::function<void()> value) 
{
	doFunction = value;
}
