#ifndef INPUT_H
#define INPUT_H

#pragma once
class Input {
public:
	static bool keyPress[256];
	static bool GetKey(unsigned char key);
	static bool GetKey(int key);
};

void keyPressed(unsigned char key, int x, int y);
void keyPressedUp(unsigned char key, int x, int y);
void specialkeyPressed(int key, int x, int y);
void specialkeyPressedUp(int key, int x, int y);
#endif
