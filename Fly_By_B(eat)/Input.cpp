#include "Input.h"

bool Input::keyPress[256] = { false };

void keyPressed(unsigned char key, int x, int y)
{
	Input::keyPress[key] = true;
}

void keyPressedUp(unsigned char key, int x, int y)
{
	Input::keyPress[key] = false;
}

bool Input::GetKey(unsigned char key)
{
	return keyPress[key];
}