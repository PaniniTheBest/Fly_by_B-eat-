#include "Player.h"
#include <glut.h>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

int prevTime = 0;
bool keyStates[256] = { false };

void RenderScene(void)
{
	GameObject player;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = (currentTime - prevTime) / 1000.0f;
	prevTime = currentTime;

	player.velX += player.accX * deltaTime;


	player.velX += player.accX * deltaTime;
	player.velY += player.accY * deltaTime;
	player.velZ += player.accZ * deltaTime;

	player.posX += player.velX * deltaTime;
	player.posY += player.velY * deltaTime;
	player.posZ += player.velZ * deltaTime;

	if (player.posY <= 0.0f)
	{
		player.accY = 0.0f;
		player.velY = 0.0f;
	}
	else
	{
		player.accY = -2.0f;
	}

	glTranslatef(player.posX, player.posY, player.posZ);
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

/*void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		if (posY == 0.0f)
			velX = 5.0f;
		break;
	case 'a':
	case 'A':
		if (velX > 0.0f)
			velX -= 0.5f;
		else if (velX < 0.0f)
			velX += 0.5f;
	}
}*/