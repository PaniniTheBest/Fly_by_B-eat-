#include "Input.h"
#include "vector3.h"


Vector3 playerPos;

bool Input::keyPress[256] = { false };

void keyPressed(unsigned char key, int x, int y)
{
	Input::keyPress[key] = true;
}

void keyPressedUp(unsigned char key, int x, int y)
{
	Input::keyPress[key] = false;
}

void specialkeyPressed(int key, int x, int y)
{
	Input::keyPress[key] = true;
}

void specialkeyPressedUp(int key, int x, int y)
{
	Input::keyPress[key] = false;
}

bool Input::GetKey(unsigned char key)
{
	return keyPress[key];
}

bool Input::GetKey(int key)
{
	return keyPress[key];
}


void processNormalKeys()
{
    const char keys[] = { 'w', 'a', 's', 'd' };

    for (char key : keys)
    {
        if (Input::GetKey(key))
        {
            Vector3 movement(0, 0, 0);

            if (Input::GetKey('w')) movement.y += 10.1f;
            if (Input::GetKey('s')) movement.y -= 10.1f;
            if (Input::GetKey('a')) movement.x -= 10.1f;
            if (Input::GetKey('d')) movement.x += 10.1f;

            playerPos += movement;
        }
    }
}

// test