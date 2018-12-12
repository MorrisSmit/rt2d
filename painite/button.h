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


class Button : public Entity
{
public:
   // Button constructor
	Button();

   // Button destructor
   ~Button();

	//check if button is pressed
	bool isPressed();
private:
	
};

#endif // !BUTTON_H
