/**
* Copyright 2015 Your Name <you@yourhost.com>
*
* @file button.h
*
* @brief description of button behavior.
*/


#ifndef BUTTON_H
#define BUTTON_H

#include <rt2d/entity.h>
#include <rt2d/text.h>
#include <functional>


class Button : public Entity
{
public:
   // Button constructor
	Button(std::string name);

   // Button destructor
   ~Button();

	//check if button is pressed
	void checkIfPressed();

	void runFunction();

	void setFunction(std::function<void()> value);
	
	void update(float deltatime);


private:
	int yPos;
	int xPos;
	double mouseY;
	double mouseX;
	Text* text;

	std::function<void()> doFunction = nullptr;

};

#endif // !BUTTON_H
